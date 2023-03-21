/**
 * @brief Button Debouncer library, function implementations implementation
 * @date 2023-03-21
 * 
 */

#include "buttonDebouncer.h"

/* Includes */
#include "Arduino.h"

volatile void updateButton(uint8_t& buttonHistory, uint8_t buttonPin) {
    buttonHistory = (buttonHistory << 1);  // with buttonHistory as a pointer?
    buttonHistory |= (!digitalRead(buttonPin));
}

uint8_t isButtonPressed(uint8_t& buttonHistory) {
    uint8_t pressed = 0;
    if ((buttonHistory & MASK) == 0b00000111) {
        pressed = 1;
        buttonHistory = 0b11111111;  // = 0xFF
    }
    return pressed;
}
uint8_t isButtonReleased(uint8_t& buttonHistory) {
    uint8_t released = 0;
    if ((buttonHistory & MASK) == 0b11000000) {
        released = 1;
        buttonHistory = 0b00000000;  // = 0x00
    }
    return released;
}
uint8_t isButtonDown(uint8_t& buttonHistory) {
    return (buttonHistory == 0b11111111);  // = 0xFF
}

uint8_t isButtonUp(uint8_t& buttonHistory) {
    return (buttonHistory == 0b00000000);  // = 0x00
}
