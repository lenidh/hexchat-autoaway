project (AutoAway)
cmake_minimum_required (VERSION 3.0)

# version number
set(AUTOAWAY_VERSION_MAJOR 0)
set(AUTOAWAY_VERSION_MINOR 4)
set(AUTOAWAY_VERSION_PATCH 0)
set(AUTOAWAY_VERSION_PRERELEASE "-beta1")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/autoaway_config.h.in"
    "${PROJECT_BINARY_DIR}/autoaway_config.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

file(GLOB SOURCES "src/*.c")

if(WIN32)
    file(GLOB PLATFORM_SOURCES "src/win32/*.c")
    set(LIBS ${LIBS} wtsapi32)
endif(WIN32)

add_library(AutoAway SHARED ${SOURCES} ${PLATFORM_SOURCES})
target_link_libraries(AutoAway ${LIBS})