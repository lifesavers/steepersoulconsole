#include <Arduino.h>           // For general Input/Output
#include <SSC.h>               // For pin layout and basic pin variable declarations.
#include <ICE.h>               // In Case of Emergency File, Customized for Home, Campus, Apartment, Dwelling...
#include <AccountSecrets.h>    // Customizable Service Provider Account Secrets: PagerDuty, Twilio, Temboo, Fitbit, etc. You must either build Your own from the Template, or join a Service Organization that will handle this for You.
#include <Bridge.h>            // For communication between the Arduino and Linux chipsets
#include <Console.h>           // Used to communicate with board wirelessly with Serial interface. Takes the place of Serial.println("x"); statements.
#include <SoftwareSerial.h>    // Needed for SSC α007's Bluetooth Transceiver (HC-05) Serial Connection. Simulates Serial line on arbitrary set of interrupt-capable btpincodes.
/*
Behavior Tests

1. Take button press, stream "Safety Orange Button pressed!" when activated
2. Establish state for obutton; flip state on an integer from 0 to 1 to 2, and back, representing major modes.
3. Establish connection to timeserver, print present time to Serial
4. When state flip occurs, stream linked success message for change, with present time
5. Attach PagerDuty to obutton press in 2
6. Secure Bluetooth ACK linkage to HC-05 device
7. Trigger PagerDuty blank from Bluetooth phone
8. Establish basic logging, basic timestamped alert code message on memory card
9. Sync PagerDuty call and basic alert log
10. Add more behaviors, building to basic Fitbit Sleep Logs

*/


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  
  // SET-UP INPUTS
  pinMode(obutton, INPUT);
//  pinMode(breath_alcohol_sensor, INPUT); For upcoming versions, requires user testing
  SoftwareSerial bluetooth(16, 15);              // Pins for RX-In (16), TX-Out (15) for Steeper Souls Console. These may need to be reversed for production testing.

  // SET-UP OUTPUTS
  pinMode(red_led, OUTPUT);     
  pinMode(green_led, OUTPUT);     
  pinMode(blue_led, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(obutton);
  
  
}


// HELPER FUNCTIONS
void whiteRGB() {
  analogWrite(red_led, 255);
  analogWrite(green_led, 255);
  analogWrite(blue_led, 255);
}


void redRGB() {
  analogWrite(red_led, 255);
  analogWrite(green_led, 0);
  analogWrite(blue_led, 0);
}

void greenRGB() {
  analogWrite(red_led, 0);
  analogWrite(green_led, 255);
  analogWrite(blue_led, 0);
}

void blueRGB() {
  analogWrite(red_led, 0);
  analogWrite(green_led, 0);
  analogWrite(blue_led, 255);
}
