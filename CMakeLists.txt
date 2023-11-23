cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# set(PROJECT yapc_poc)
set(PICO_BOARD vgaboard)

# # Initialise pico_sdk from installed location
# # (note this can come from environment, CMake cache etc)
# set(PICO_SDK_PATH "${CMAKE_CURRENT_LIST_DIR}/../pico-sdk/")
# # set(PICO_SDK_PATH "${PICO_SDK_PATH}")
# # message(FATAL_ERROR "PICO_SDK_PATH=${PICO_SDK_PATH}")

# Pull in Raspberry Pi Pico SDK (must be before project)
# include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.5.0")
  message(
    FATAL_ERROR 
    "Raspberry Pi Pico SDK version 1.5.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}"
  )
endif()

project(yapc_poc
  C CXX ASM
)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(yapc_poc 
  src/main.c
)

pico_set_program_name(yapc_poc "YetAnotherPicoComputer POC")
pico_set_program_version(yapc_poc "0.1")

pico_enable_stdio_uart(yapc_poc 0)
pico_enable_stdio_usb(yapc_poc 1)

# Use pico-filesystem as a local repository for now
# add_subdirectory (external/pico-filesystem pfs)
add_subdirectory (../pico-filesystem pfs)
target_link_libraries(yapc_poc flash_filesystem)
target_link_libraries(yapc_poc sdcard_filesystem)
target_link_libraries(device_filesystem)

# Add any PICO_CONFIG entries specified in the Advanced settings
add_compile_definitions(PICO_MALLOC_PANIC=0)

# Add the standard library to the build
target_link_libraries(yapc_poc
  pico_stdlib
)

# Add the standard include files to the build
target_include_directories(yapc_poc PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/include
  # ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# # Add any user requested libraries
# target_link_libraries(yapc_poc 
#         hardware_spi
#         hardware_i2c
#         hardware_dma
#         hardware_pio
#         hardware_interp
#         hardware_timer
#         hardware_watchdog
#         hardware_clocks
# )

pico_add_extra_outputs(yapc_poc)

target_compile_definitions(yapc_poc PUBLIC 
)

# EOF
