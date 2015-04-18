/*
Smash Lies
===========
Dream awake, get up and get up and go awe
Some peace of mind from the daily grind...

*/


// Soul Safety Console based on Arduino Esplora model
/* Quality Assurance Objectives: 
       1) Fractional distill of æpe events for Engaugement, Marital Engagement
       2) Reactionary force function counter for αpe events, on 1869ms measures
       3) Conversation starter on quanlit (quantity and quality) of life (lit, love, liberty, labor, life is time [LIT])
       4) Provide regular LIT-driven recoding interface for intrapersonal and interpersonal soul meal sen/s/ate interferences: feedbacks and feedforwards
       5) Default option reliable microcontroller, software, and open hardware programming for life, for all non-efree days

Notice: Much of this code comes from the Esplora Library Examples, and includes work by Enrico Gueli <enrico.gueli@gmail.com> and Tom Igoe       
*/

#include <Esplora.h>

int test_reader = 1;

// Buzzer - these are the frequencies for the notes from middle C
// to one octave above middle C:
const int note[] = {
  262, // C
  277, // C#
  294, // D
  311, // D#
  330, // E
  349, // F
  370, // F#
  392, // G
  415, // G#
  440, // A
  466, // A#
  494, // B
  523  // C next octave
};


void setup() {
  // put your setup code here, to run once:

  int test_reader_state = 0;
  pinMode(test_reader, INPUT);
  
  
  

}

void loop() {

  // Read 


  // Read Joystick
  int xValue = Esplora.readJoystickX();        // read the joystick's X position
  int yValue = Esplora.readJoystickY();        // read the joystick's Y position
  int obutton = Esplora.readJoystickSwitch();   // read the joystick orange pushbutton
  

  int test_reader_state = digitalRead(test_reader);
  Serial.println(test_reader);
  if (Esplora.readButton(1) == LOW) {
    MangoRGB();
//    Esplora.tone(330); // Æve Mango  
  }
    
  
}

void redRGB() {
  Esplora.writeRGB(255, 0, 0);  // make the LED red  
}

void greenRGB() {
  Esplora.writeRGB(0, 255, 0);  // make the LED red  
}

void blueRGB() {
  Esplora.writeRGB(0, 0, 255);  // make the LED red  
}

void safety_orangeRGB() {
  Esplora.writeRGB(232, 118, 0);  // make the LED red  
}

void MangoRGB() { // Make the LED mango cycle
  // Test color true
  Esplora.writeRGB(26, 255, 0); // make the LED 10% yellow, off-green
  delay(236);
  Esplora.writeRGB(77, 255, 0); // make the LED 30% yellow, off-green
  delay(236);
  Esplora.writeRGB(128, 255, 0); // make the LED 50% yellow, off-green
  delay(218);
  Esplora.writeRGB(179, 255, 0); // make the LED 70% yellow, off-green
  delay(218);
  Esplora.writeRGB(230, 255, 0); // make the LED 90% yellow
  delay(218);
  Esplora.writeRGB(255, 255, 0); // make the LED 100% yellow
  delay(218);
  Esplora.writeRGB(255,0,0); // make the LED flash red
  delay(240); // benched and physical social distance separation at 4-12 feet for 24 hour minimum, mango report making is obligatory
}

