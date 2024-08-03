EasyPWM

EasyPWM is an Arduino library designed to simplify the use of PWM (Pulse Width Modulation) signals. It allows you to easily control the frequency and duty cycle of PWM signals on multiple digital pins with minimal code. Unlike some libraries, EasyPWM does not alter hardware registers directly. Instead, it uses the micros() function to manage PWM timing, which makes it easier to understand and integrate into projects. The PWM capabilities will depend on the microcontroller being used.


Please note that using functions such as Serial.print() or other libraries that rely on delays or interrupts may affect the stability and precision of the PWM signal, especially at high frequencies.

Features

Add Multiple Pins: Quickly add multiple pins for PWM control.

Adjust Frequency: Set the frequency of the PWM signal for each pin.

Set Duty Cycle: Adjust the duty cycle of the PWM signal, expressed as a percentage.

Convenient set() Method: Configure frequency and duty cycle in a single call. It Automatic updates. 

No Direct Register Manipulation: PWM is managed using micros(), avoiding direct manipulation of hardware registers.

Impact of Other Functions: Be aware that functions like Serial.print() and other libraries that use delays or interrupts can impact PWM stability at high frequencies.

Installation

Download the Library:

Download the latest version of the EasyPWM library from the GitHub repository.
Add to Arduino IDE:

Open the Arduino IDE.
Go to Sketch -> Include Library -> Add .ZIP Library...
Select the downloaded ZIP file and click Open.
Usage
Here is a simple example of how to use the EasyPWM library in your Arduino sketch:

cpp
Copy code
#include <EasyPWM.h>

EasyPWM myPWM;

void setup() {
    myPWM.addPin(11, 5000, 75); // Adds pin 11 with an initial frequency of 5000 Hz and 75% duty cycle
    myPWM.addPin(12);           // Adds pin 12 with an initial frequency of 1000 Hz and 50% duty cycle (default)
    myPWM.begin();
}

void loop() {
    // Call process() to ensure PWM is updated
    myPWM.process();

    // Example: change the frequency and duty cycle of pin 12 after 5 seconds
    static uint32_t lastChangeTime = 0;
    uint32_t currentTime = millis();

    if (currentTime - lastChangeTime > 5000) { // every 5 seconds
        myPWM.set(12, 50, 25); // Set the frequency of pin 12 to 50 Hz and duty cycle to 25%
        lastChangeTime = currentTime;
    }
}
Methods
addPin(uint8_t pin, uint32_t frequency = 0, uint8_t dutyCycle = 50): Adds a pin for PWM control with optional frequency and duty cycle.
begin(): Initializes all added pins.
setFrequency(uint8_t pin, uint32_t frequency): Sets the frequency for a specific pin.
setDutyCycle(uint8_t pin, uint8_t dutyCycle): Sets the duty cycle for a specific pin.
set(uint8_t pin, uint32_t frequency, uint8_t dutyCycle): Sets both frequency and duty cycle for a specific pin.
process(): Updates the PWM signals. Must be called regularly in the loop() function.
Contributing
This library was created with the assistance of ChatGPT. Contributions are welcome! If you have suggestions or improvements, feel free to fork the repository and submit a pull request.

Disclaimer
EasyPWM is provided "as-is" without any warranties of any kind, express or implied. The authors make no guarantees regarding the performance, functionality, or reliability of this library. The use of this library is at your own risk, and the authors are not liable for any damages, losses, or other issues that may arise from its use. By using EasyPWM, you acknowledge and accept these terms.

License
This project is licensed under the MIT License. See the LICENSE file for details.

