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

include_directories(${CMAKE_SOURCE_DIR})

set (SOURCE_FILES emulator.cpp memory_manager.cpp addressing_modes.cpp opcode.cpp generated_decoder.cpp)
set (HEADER_FILES memory_manager.hpp opcode.hpp register_file.hpp opcode.hpp decoder.hpp)

add_custom_command (
  OUTPUT generated_opcodes.json
  COMMAND python3 ${CMAKE_SOURCE_DIR}/gen_uops_json.py --filename=${CMAKE_SOURCE_DIR}/opcode_table.txt > generated_opcodes.json
  DEPENDS ${CMAKE_SOURCE_DIR}/opcode_table.txt
)

add_custom_command(
  OUTPUT generated_decoder.cpp
  COMMAND python3 ${CMAKE_SOURCE_DIR}/gen_code.py --filename=generated_opcodes.json > generated_decoder.cpp
  DEPENDS generated_opcodes.json
)

add_executable(emulator ${SOURCE_FILES} ${HEADER_FILES})

install(TARGETS emulator DESTINATION bin)
