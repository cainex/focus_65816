cmake_minimum_required(VERSION 2.8.11)
project(test_adc)

# Set the path to the cc65 bin folder if it's not in your PATH environment variable
# set(CMAKE_C_COMPILER "/path/to/cc65/bin/cl65")

# Set the path to the cc65 ld65 linker if it's not in your PATH environment variable
# set(CMAKE_LINKER "/path/to/cc65/bin/ld65")

# Set the target CPU for cc65
set(CPU "6502")

# Set the memory configuration for cc65
set(MEMORY_CONFIG "c64")

# Set the path to your assembly source file
set(SRC_FILE "test_adc.s")

# Set the output file name
set(OUTPUT_FILE "test_adc.bin")

# Set the linker configuration file
set(LINKER_CONFIG "${CMAKE_CURRENT_SOURCE_DIR}/linker.cfg")

# Set the options for the assembler
set(ASSEMBLER_OPTIONS "-t ${CPU} -m ${MEMORY_CONFIG}")

# Set the options for the linker
set(LINKER_OPTIONS "-C ${LINKER_CONFIG}")

# Set the output directory for the binary file
set(OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Create the output directory if it doesn't exist
file(MAKE_DIRECTORY ${OUTPUT_DIRECTORY})

# Assemble the source file
add_custom_command(
    OUTPUT ${OUTPUT_FILE}
    COMMAND cl65 ${ASSEMBLER_OPTIONS} ${SRC_FILE} -o ${OUTPUT_DIRECTORY}/${OUTPUT_FILE}
    DEPENDS ${SRC_FILE} ${LINKER_CONFIG}
)

# Link the object files and generate the raw binary file
add_custom_target(
    binary ALL
    COMMAND ld65 ${LINKER_OPTIONS} -o ${OUTPUT_DIRECTORY}/${OUTPUT_FILE} ${OUTPUT_DIRECTORY}/${OUTPUT_FILE}
    DEPENDS ${OUTPUT_FILE}
)

# Print a message showing where the output file was generated
add_custom_command(
    TARGET binary POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Output binary: ${OUTPUT_DIRECTORY}/${OUTPUT_FILE}"
)
