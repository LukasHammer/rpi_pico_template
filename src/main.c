/*
 * Author: Lukas Hammer
 * Date: December 2025
 * Description: Template raspberrypi pico program to toggle an LED on GPIO 25
 */

#include <stdio.h>
#include <pico/stdlib.h>

#define LED_PIN 25
#define LED_INIT() gpio_init(LED_PIN)
#define LED_PIN_OUT_DIR() gpio_set_dir(LED_PIN, GPIO_OUT)
#define TOGGLE_LED() gpio_xor_mask(1 << LED_PIN)

int main() {
    // Initialize the LED pin
    LED_INIT();
    LED_PIN_OUT_DIR();

    while (1) {
        TOGGLE_LED();
        sleep_ms(1000);
    }
}

