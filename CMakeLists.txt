cmake_minimum_required(VERSION 2.8.11)
project (emulator)

set(EMULATOR_MAJOR_VERSION 0)
set(EMULATOR_MINOR_VERSION 1)
set(EMULATOR_PATCH_VERSION 0)
set(EMULATOR_VERSION
  ${EMULATOR_MAJOR_VERSION}, ${EMULATOR_MINOR_VERSION}, ${EMULATOR_PATCH_VERSION})

set(DEF_INSTALL_CMAKE_DIR lib/CMake/emulator)
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation director for CMake files")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(warnings "-Wall -Wextra -Werror -Wc++11-extensions")
  set(CMAKE_CXX_FLAGS "-std=c++17") 
endif()

set (SOURCE_FILES emulator.cpp memory_manager.cpp addressing_modes.cpp opcode.cpp decoder.cpp)
set (HEADER_FILES memory_manager.hpp opcode.hpp register_file.hpp opcode.hpp decoder.hpp)

add_executable(emulator ${SOURCE_FILES})

install(TARGETS emulator DESTINATION bin)
