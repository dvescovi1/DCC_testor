cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME DCC_Tester)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM, C and C++ languages
enable_language(C CXX ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Add Send generated sources
#add_subdirectory(Send)



# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Set source and header directories
set(SEND_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Send/INCLUDE" "${CMAKE_CURRENT_SOURCE_DIR}/Send/PORT_V4" "${CMAKE_CURRENT_SOURCE_DIR}/Send/LIB")

# Add sources to executable
file(GLOB SUSI_SOURCES
    Src/SUSI/*.c
)

file(GLOB SEND_SOURCES
    Send/SRC/SEND/*.cpp
    Send/PORT_V4/*.cpp
    Send/LIB/*.cpp
)
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    ${SUSI_SOURCES}
    ${SEND_SOURCES}
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    ${SEND_INCLUDE_DIR}
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
    SEND_VERSION=4
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
#    SendLib
    # Add user defined libraries


)
