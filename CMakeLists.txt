cmake_minimum_required(VERSION 3.22.1)

project(FVS LANGUAGES CXX)

# Avoid FetchContent warning.
cmake_policy(SET CMP0135 NEW)

# Require C++14.
set(CMAKE_CXX_STANDARD 14)

# Enable output of compile commands during generation.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# Add sub-directories.
add_subdirectory(extern)
add_subdirectory(src)
add_subdirectory(test)
