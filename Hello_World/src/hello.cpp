#include "Arduino.h"

#if 0
const uint8_t LED_BUILTINT = 13;
#else
const uint8_t ON_BOARD_LED = 13;
#endif
bool status = LOW;

uint16_t pwm_value = 0U;
uint16_t TIME_LIMIT_MS = 100U;
int8_t step = 5;

void setup()
{
    pinMode(ON_BOARD_LED, OUTPUT);
    digitalWrite(ON_BOARD_LED, status);
}

void loop()
{
    delay(TIME_LIMIT_MS-pwm_value);
    status = !(status);
    digitalWrite(ON_BOARD_LED, status);
    delay(pwm_value);
    status = !(status);
    digitalWrite(ON_BOARD_LED, status);
    pwm_value += step;

    if ( (0U != (pwm_value / TIME_LIMIT_MS)) ||
        (0U == pwm_value)
    )
    {
        step *=-1;
    }

    //pwm_value %= TIME_LIMIT_MS;

}
