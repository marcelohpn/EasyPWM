#include "EasyPWM.h"

EasyPWM::EasyPWM() {}

void EasyPWM::addPin(uint8_t pin, uint32_t frequency, uint8_t dutyCycle) {
    PWMPin pwmPin = {pin, frequency, 0, 0, 0, dutyCycle, frequency != 0};
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    if (frequency != 0) {
        updateTimes(pwmPin);
    }
    _pwmPins.push_back(pwmPin);
}

void EasyPWM::begin() {
    // Initialize all added pins
    for (auto &pwmPin : _pwmPins) {
        pinMode(pwmPin.pin, OUTPUT);
        digitalWrite(pwmPin.pin, LOW);
        if (pwmPin.frequency != 0) {
            updateTimes(pwmPin);
            pwmPin.isActive = true;
        }
    }
}

void EasyPWM::setFrequency(uint8_t pin, uint32_t frequency) {
    for (auto &pwmPin : _pwmPins) {
        if (pwmPin.pin == pin) {
            pwmPin.frequency = frequency;
            updateTimes(pwmPin);
            pwmPin.isActive = true;
            break;
        }
    }
}

void EasyPWM::setDutyCycle(uint8_t pin, uint8_t dutyCycle) {
    for (auto &pwmPin : _pwmPins) {
        if (pwmPin.pin == pin) {
            pwmPin.dutyCycle = dutyCycle;
            updateTimes(pwmPin);
            pwmPin.isActive = true;
            break;
        }
    }
}

void EasyPWM::set(uint8_t pin, uint32_t frequency, uint8_t dutyCycle) {
    for (auto &pwmPin : _pwmPins) {
        if (pwmPin.pin == pin) {
            pwmPin.frequency = frequency;
            pwmPin.dutyCycle = dutyCycle;
            updateTimes(pwmPin);
            pwmPin.isActive = true;
	    update(); // Call update() internally //teste

            break;
        }
    }
}

void EasyPWM::process() {
    update(); // Call update() internally
}

void EasyPWM::update() {
    _currentMicros = micros();
    for (auto &pwmPin : _pwmPins) {
        if (!pwmPin.isActive) continue; // Skip inactive pins

        if (_currentMicros - pwmPin.timerFreq <= pwmPin.tempoHigh) {
            digitalWrite(pwmPin.pin, HIGH);
        } else {
            digitalWrite(pwmPin.pin, LOW);
            if (_currentMicros - pwmPin.timerFreq >= (pwmPin.tempoHigh + pwmPin.tempoLow)) {
                pwmPin.timerFreq = _currentMicros;
            }
        }
    }
}

void EasyPWM::updateTimes(PWMPin &pwmPin) {
    uint32_t period = 1000000 / pwmPin.frequency; // Period in microseconds
    pwmPin.tempoHigh = (period * pwmPin.dutyCycle) / 100; // High time
    pwmPin.tempoLow = period - pwmPin.tempoHigh; // Low time
}
