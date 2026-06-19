idf_component_register(SRCS "ultrasonic.c" "servo.c" "motor.c" "main.c"
                    REQUIRES esp_driver_gpio
                    REQUIRES esp_timer
                    PRIV_REQUIRES esp_driver_mcpwm
                    INCLUDE_DIRS ".")
