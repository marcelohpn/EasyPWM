/*    __  ___ ___     ____   ______ ______ __    ____     __  __ ____   _   __    
   /  |/  //   |   / __ \ / ____// ____// /   / __ \   / / / // __ \ / | / /   
  / /|_/ // /| |  / /_/ // /    / __/  / /   / / / /  / /_/ // /_/ //  |/ /  
 / /  / // ___ | / _, _// /___ / /___ / /___/ /_/ /  / __  // ____// /|  /   
/_/  /_//_/  |_|/_/ |_| \____//_____//_____/\____/  /_/ /_//_/    /_/ |_/    
*/

#define LED 13

#include <EasyPWM.h>

EasyPWM myPWM;

void setup() {
    myPWM.addPin(LED);      // Adds pin 13 with an initial frequency of 1000 Hz and 50% duty cycle (default)
    myPWM.addPin(9, 500, 25); // Adds pin 9 with an initial frequency of 500 Hz and 25% duty cycle
    myPWM.begin();
}

void loop() {
    
    // Call process() to ensure PWM is updated
    //myPWM.process(); //if you call myPWM.set, it automatic update

    myPWM.set(LED, 100, 25); // Set the frequency of pin 13 to 120 Hz and duty cycle to 40%

    myPWM.set(9, 1000, 50); // Set the frequency of pin 9 to 1000 Hz and duty cycle to 50%
       
}
