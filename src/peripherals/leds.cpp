/*
QMesh
Copyright (C) 2020 Daniel R. Fay

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "leds.hpp"

IndicatorLED led1(LED1);
IndicatorLED led2(LED2);
IndicatorLED led3(LED3);

void IndicatorLED::blinkFn(void) {
        if(led_state == LED_BLINK) {
            *pin = !*pin;
            evt_queue->call_in(blink_period, callback(this, &IndicatorLED::blinkFn));
        }
        else {
            *pin = 0;
        }
}

IndicatorLED::IndicatorLED(PinName led_pin_name) {
    led_state = LED_OFF;
    blink_led = false;
    blink_period = 250;
    pin = new DigitalOut(led_pin_name);
    *pin = 0;
}

void IndicatorLED::LEDSolid(void) {
    led_state = LED_SOLID;
    blink_led = false;
    *pin = 1;
}

void IndicatorLED::LEDOff(void) {
    led_state = LED_OFF;
    blink_led = false;
    *pin = 0;
}   

void IndicatorLED::LEDBlink(void) {
    blink_period = 250;
    blink_led = true;
    if(led_state != LED_BLINK) {
        led_state = LED_BLINK;
        evt_queue->call_in(blink_period, callback(this, &IndicatorLED::blinkFn));
    }
}

void IndicatorLED::LEDFastBlink(void) {
    blink_period = 50;
    blink_led = true;
    if(led_state != LED_BLINK) {
        led_state = LED_BLINK;
        evt_queue->call_in(blink_period, callback(this, &IndicatorLED::blinkFn));
    }
}

IndicatorLED::~IndicatorLED() {
    delete pin;
}


class Nucleo144LEDs {
    
};