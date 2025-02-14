#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;
const int BTN_PIN2 = 26;
const int LED_PIN = 4;
const int LED_PIN2 = 6;

int main() {
  stdio_init_all();
  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(BTN_PIN2);
  gpio_set_dir(BTN_PIN2, GPIO_IN);
  gpio_pull_up(BTN_PIN2);

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN , GPIO_OUT);
 
  gpio_put(LED_PIN, 0);

  gpio_init(LED_PIN2);
  gpio_set_dir(LED_PIN2 , GPIO_OUT);
 
  gpio_put(LED_PIN2, 0);

  int led1 = 0;
  int led2 = 0;

  while (true) {
    if (!gpio_get(BTN_PIN)){
      led1 = !led1;
      gpio_put(LED_PIN, led1);
      while (!gpio_get(BTN_PIN));
    }
    if (!gpio_get(BTN_PIN2)){
      led2 = !led2;
      gpio_put(LED_PIN2, led2);
      while (!gpio_get(BTN_PIN2));
    }
  }
}


