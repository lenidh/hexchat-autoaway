project (AutoAway)
cmake_minimum_required (VERSION 3.0)

# version number
set(AUTOAWAY_VERSION_MAJOR 0)
set(AUTOAWAY_VERSION_MINOR 4)
set(AUTOAWAY_VERSION_PATCH 0)
set(AUTOAWAY_VERSION_PRERELEASE "-beta1")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/autoaway_config.h.in"
    "${PROJECT_BINARY_DIR}/autoaway_config.h"
)

# add the binary tree to the search path for include files
# so that we will find autoaway_config.h
include_directories("${PROJECT_BINARY_DIR}")

file(GLOB SOURCES "src/*.c")

if(WIN32)
    file(GLOB PLATFORM_SOURCES "src/win32/*.c")
endif(WIN32)
if(UNIX)
    file(GLOB PLATFORM_SOURCES "src/dbus/*.c")
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GIO REQUIRED gio-unix-2.0)
endif(UNIX)

add_library(AutoAway SHARED ${SOURCES} ${PLATFORM_SOURCES})

if(WIN32)
    target_link_libraries(AutoAway wtsapi32)
endif(WIN32)

if(GIO_FOUND)
    target_link_libraries(AutoAway ${GIO_LIBRARIES})
    target_include_directories(AutoAway PUBLIC ${GIO_INCLUDE_DIRS})
endif(GIO_FOUND)