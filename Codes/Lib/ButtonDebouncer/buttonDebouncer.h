/**
 * @brief Button Debouncer library, header file with function definitions
 * @date 2023-03-21
 * 
 */

#ifndef _BUTTON_DEBOUNCER_H_
#define _BUTTON_DEBOUNCER_H_

#ifdef __cplusplus

/* Includes */
#include <cstdint>

/* Defines */
#define MASK 0b11000111

/* Function definitions */

volatile void updateButton(uint8_t& buttonHistory, uint8_t buttonPin);
uint8_t isButtonPressed(uint8_t& buttonHistory);
uint8_t isButtonReleased(uint8_t& buttonHistory);
uint8_t isButtonDown(uint8_t& buttonHistory);
uint8_t isButtonUp(uint8_t& buttonHistory);

#endif /* __cplusplus */
#endif /* _BUTTON_DEBOUNCER_H_ */