#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <wtsapi32.h>
#include "session-tracking.h"
#include "logging.h"

#define WINDOW_CLASS "AutoAwayMessageWindowClass"
#define WINDOW_TITLE "AutoAwayMessageWindowTitle"

// win32 module handle
static void* module_handle = NULL;

// message window handle
static void* window_handle = NULL;

// message thread handle
static void* thread_handle = NULL;

static void default_event_handler(int event) {}
static void (*session_event_handler)(int) = &default_event_handler;

static LRESULT __stdcall window_proc(HWND hwnd, unsigned int msg, WPARAM wParam, LPARAM lParam) {
    switch(msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_WTSSESSION_CHANGE:
            if(wParam == WTS_SESSION_LOCK) {
                (*session_event_handler)(EVENT_SESSION_LOCK);
            }
            if(wParam == WTS_SESSION_UNLOCK) {
                (*session_event_handler)(EVENT_SESSION_UNLOCK);
            }
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

static bool register_window_class() {
    autoaway_log("Register window class");
    WNDCLASSEX wc;
    wc.hInstance =  module_handle;
    wc.lpszClassName = WINDOW_CLASS;
    wc.lpfnWndProc = window_proc;
    wc.style = 0;
    wc.cbSize = sizeof (WNDCLASSEX);
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.lpszMenuName = NULL;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    if (!RegisterClassEx(&wc)) {
        int err = GetLastError();
        if(err == ERROR_CLASS_ALREADY_EXISTS)
            autoaway_log("Error: Window class has already been registered");
        else
            autoaway_log("Error: Unable to register the window class due to an unknown reason");
        return false;
    }
    return true;
}

static void unregister_window_class() {
    autoaway_log("Unregister window class");
    if(UnregisterClass(WINDOW_CLASS, module_handle) == false){
        autoaway_log("Error: Unable to unregister the window class");
    }
}

static unsigned long __stdcall thread_proc(void* param) {
    autoaway_log("Start message loop thread");
    int result = 0;
    bool registered = register_window_class();
    if(registered) {
        window_handle = CreateWindowEx (0, WINDOW_CLASS, WINDOW_TITLE, WS_EX_PALETTEWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, HWND_MESSAGE, NULL, module_handle, NULL);
        WTSRegisterSessionNotification(window_handle, NOTIFY_FOR_THIS_SESSION);

        MSG msg;
        while (GetMessage (&msg, NULL, 0, 0) > 0) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        WTSUnRegisterSessionNotification(window_handle);
        window_handle = NULL;
        unregister_window_class();

        result = msg.wParam;
    } else {
        autoaway_log("Warning: Session will not be tracked");
    }
    autoaway_log("Exit message loop thread");
    return result;
}

void start_tracking_session(void (*event_handler)(int)) {
    if(thread_handle == NULL) {
        thread_handle = CreateThread(0, 0, &thread_proc, NULL, 0, NULL);
        if(thread_handle == NULL) {
            autoaway_log("Error: Unable to start message loop thread");
        } else {
            session_event_handler = event_handler;
        }
    }
}

void stop_tracking_session() {
    if(thread_handle != NULL) {
        session_event_handler = &default_event_handler;
        if(window_handle != NULL) SendMessage(window_handle, WM_CLOSE, 0, 0);
        WaitForSingleObject(thread_handle, INFINITE);
        thread_handle = NULL;
    }
}

bool __stdcall DllMain(void* instance, unsigned long reason, void* reserved) {
    if(reason == DLL_PROCESS_ATTACH) {
        module_handle = instance;
    }
    else if(reason == DLL_PROCESS_DETACH) {
        module_handle = NULL;
    }
    return true;
}
