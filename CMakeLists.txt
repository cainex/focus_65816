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

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# include_directories(${CMAKE_SOURCE_DIR})

set (SOURCE_FILES emulator.cpp memory_manager.cpp addressing_modes.cpp generated_opcodes.cpp generated_decoder.cpp)
set (HEADER_FILES memory_manager.hpp register_file.hpp decoder.hpp generated_opcodes.hpp)

add_custom_command (
  OUTPUT generated_opcodes.json
  COMMAND python3 ${CMAKE_SOURCE_DIR}/gen_uops_json.py --filename=${CMAKE_SOURCE_DIR}/opcode_table.txt > generated_opcodes.json
  DEPENDS ${CMAKE_SOURCE_DIR}/opcode_table.txt ${CMAKE_SOURCE_DIR}/gen_uops_json.py
)

add_custom_command(
  OUTPUT generated_decoder.cpp
  COMMAND python3 ${CMAKE_SOURCE_DIR}/gen_code.py --filename=generated_opcodes.json > generated_decoder.cpp
  DEPENDS generated_opcodes.json ${CMAKE_SOURCE_DIR}/gen_code.py
)

add_custom_command(
  OUTPUT generated_opcodes.cpp generated_opcodes.hpp
  COMMAND python3 ${CMAKE_SOURCE_DIR}/gen_uops.py --filename=${CMAKE_SOURCE_DIR}/uops.json --output=generated_opcodes
  DEPENDS ${CMAKE_SOURCE_DIR}/uops.json ${CMAKE_SOURCE_DIR}/gen_uops.py
)
add_executable(emulator ${SOURCE_FILES} ${HEADER_FILES})

install(TARGETS emulator DESTINATION bin)
