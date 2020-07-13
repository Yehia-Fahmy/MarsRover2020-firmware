add_executable(arm.${TARGET}-board.elf)
target_sources(arm.${TARGET}-board.elf PRIVATE src/main.cpp)
target_link_libraries(arm.${TARGET}-board.elf PRIVATE ClawController CANBuffer DifferentialWristController EncoderRelative_Quadrature Motor)
target_set_firmware_properties(arm.${TARGET}-board.elf)

add_library(DifferentialWristController)
target_sources(DifferentialWristController PRIVATE src/DifferentialWristController.cpp)
target_include_directories(DifferentialWristController PUBLIC include)
target_link_libraries(DifferentialWristController PUBLIC ActuatorController PID Motor)
target_set_mbed_dependency(DifferentialWristController)

add_library(ClawController)
target_sources(ClawController PRIVATE src/ClawController.cpp)
target_include_directories(ClawController PUBLIC include)
target_link_libraries(ClawController PUBLIC ActuatorController PID) # Servo //TODO(qinyang-bao): fix all compile errors and renable servo code
target_set_mbed_dependency(ClawController)