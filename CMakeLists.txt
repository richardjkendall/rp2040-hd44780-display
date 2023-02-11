# What CMake to start at
cmake_minimum_required(VERSION 3.12)
 
# Include the subsidiary .cmake file to get the SDK
include(pico_sdk_import.cmake)
 
# Set the name and version of the project
project(LcdDisplay VERSION 1.0.0)

# Initalise the SDK
pico_sdk_init()

# Link the Project to a source file (step 4.6)
add_executable(LcdDisplay ${CMAKE_CURRENT_LIST_DIR}/main.c ${CMAKE_CURRENT_LIST_DIR}/lcd.c)

# Link the Project to an extra library (pico_stdlib)
target_link_libraries(LcdDisplay pico_stdlib hardware_gpio)
 
# Enable USB, UART output
pico_enable_stdio_usb(LcdDisplay 1)
pico_enable_stdio_uart(LcdDisplay 1)
 
# Enable extra outputs (SWD?)
pico_add_extra_outputs(LcdDisplay)