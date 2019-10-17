#include "rev2.h"

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here
  // Inverse caps lock lighting. Turn led off when caps active.
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinHigh(B2);
    // writePinLow(B2);
  } else {
    writePinLow(B2);
    // writePinHigh(B2);
  }

  led_set_user(usb_led);
}

void matrix_init_kb(void) {
  setPinOutput(B2);
  matrix_init_user();
}
