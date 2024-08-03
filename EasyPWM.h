#ifndef EASY_PWM_H
#define EASY_PWM_H

#include <Arduino.h>
#include <vector>

class EasyPWM {
public:
    EasyPWM();
    void addPin(uint8_t pin, uint32_t frequency = 0, uint8_t dutyCycle = 50);
    void begin();
    void setFrequency(uint8_t pin, uint32_t frequency);
    void setDutyCycle(uint8_t pin, uint8_t dutyCycle);
    void set(uint8_t pin, uint32_t frequency, uint8_t dutyCycle); // New function
    void process(); // Public method to call update internally

private:
    struct PWMPin {
        uint8_t pin;
        uint32_t frequency;
        uint32_t timerFreq;
        uint32_t tempoHigh;
        uint32_t tempoLow;
        uint8_t dutyCycle;
        bool isActive;
    };

    std::vector<PWMPin> _pwmPins;
    uint32_t _currentMicros;

    void update();
    void updateTimes(PWMPin &pwmPin);
};

#endif
