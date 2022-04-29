cmake_minimum_required(VERSION 2.8.11)
project (emulator)

include(CreateVirtualEnvironment.cmake)

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
  set(CMAKE_CXX_FLAGS_DEBUG  "-g")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_SOURCE_DIR}/src)

find_package (cxxopts)
if (CXXOPTS_FOUND)
  include_directories(${CXXOPTS_INCLUDE_DIRS})
  target_link_libraries (emulator ${BZIP2_LIBRARIES})
endif (CXXOPTS_FOUND)
find_package(Python3 REQUIRED COMPONENTS Interpreter)

set (
  SOURCE_FILES src/emulator.cpp src/memory_manager.cpp src/addressing_modes.cpp generated_opcodes.cpp generated_decoder.cpp src/memory_device.cpp src/cpu.cpp src/memory.cpp src/binary_loader.cpp
)

set (
  HEADER_FILES src/memory_manager.hpp src/register_file.hpp src/decoder.hpp generated_opcodes.hpp src/memory_device.hpp src/cpu.hpp src/memory.hpp src/binary_loader.hpp
)

CreateVirtualEnvironment(
    venv
    REQUIREMENTS_TXT ${CMAKE_SOURCE_DIR}/bin/requirements  # optional
    OUT_PYTHON_EXE PYTHON_EXE
    OUT_BINARY_DIR PYTHON_BIN_DIR
)

add_custom_command(
  OUTPUT generated_decoder.cpp generated_opcodes.cpp generated_opcodes.hpp
  COMMAND ${PYTHON_EXE} ${CMAKE_SOURCE_DIR}/bin/gen_code.py --filename=${CMAKE_SOURCE_DIR}/defs/uops.json
  DEPENDS ${CMAKE_SOURCE_DIR}/defs/uops.json ${CMAKE_SOURCE_DIR}/bin/gen_code.py venv
)

add_executable(emulator ${SOURCE_FILES} ${HEADER_FILES})

install(TARGETS emulator DESTINATION bin)
