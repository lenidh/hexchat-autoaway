#ifdef WIN32

#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <wtsapi32.h>
#include "logging.h"

#define WINCLASS "AutoAwayMessageWindowClass"
#define WINTITLE "AutoAwayMessageWindowTitle"

// win32 module handle
static HINSTANCE hModule;

void autoaway_set_away();
void autoaway_unset_away();

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_WTSSESSION_CHANGE:
            if(wParam == WTS_SESSION_LOCK) {
                autoaway_log("Received session lock notification");
                autoaway_set_away();
            }
            if(wParam == WTS_SESSION_UNLOCK) {
                autoaway_log("Received session unlock notification");
                autoaway_unset_away();
            }
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

static bool RegisterDLLWindowClass ()
{
    WNDCLASSEX wc;
    wc.hInstance =  hModule;
    wc.lpszClassName = WINCLASS;
    wc.lpfnWndProc = WndProc;
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
        autoaway_log("ERROR: Failed to register window class");
        return false;
    }
    autoaway_log("Successfully registered window class");
    return true;
}

static unsigned long WINAPI ThreadProc(LPVOID lpParam)
{
    autoaway_log("Successfully spawned message loop thread");
    MSG msg;
    RegisterDLLWindowClass();
    HWND hwnd = CreateWindowEx (0, WINCLASS, WINTITLE, WS_EX_PALETTEWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, HWND_MESSAGE, NULL, hModule, NULL);
    WTSRegisterSessionNotification(hwnd, NOTIFY_FOR_THIS_SESSION);
    autoaway_log("Successfully created message-only window and registered to receive session change notifications");
    ShowWindow (hwnd, SW_SHOWNORMAL);
    while (GetMessage (&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    autoaway_log("Message loop ended");
    return msg.wParam;
}

bool WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, LPVOID lpvReserved) {
    if(fdwReason==DLL_PROCESS_ATTACH) {
        autoaway_log("Library is being loaded. Initialize instance...");
        hModule = hInstance;
        autoaway_log("Spawning message loop thread...");
        CreateThread(0, 0, ThreadProc, NULL, 0, NULL);
    }
    return true;
}

#endif // WIN32