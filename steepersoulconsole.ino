#include <Arduino.h>           // For general Input/Output
#include <SSC.h>               // For pin layout and basic pin variable declarations.
#include <ICE.h>               // In Case of Emergency File, Customized for Home, Campus, Apartment, Dwelling...
#include <AccountSecrets.h>    // Customizable Service Provider Account Secrets: PagerDuty, Twilio, Temboo, Fitbit, etc. You must either build Your own from the Template, or join a Service Organization that will handle this for You.
#include <Bridge.h>            // For communication between the Arduino and Linux chipsets
#include <Console.h>           // Used to communicate with board wirelessly with Serial interface. Takes the place of Serial.println("x"); statements.
#include <SoftwareSerial.h>    // Needed for SSC α007's Bluetooth Transceiver (HC-05) Serial Connection. Simulates Serial line on arbitrary set of interrupt-capable btpincodes.
#include <SPI.h>
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

Tunnel, stroight and true. You are sitting on a critical voting right, governing private space.

Bear in mind: Default IP for Dragino Architexture is http://192.168.240.1/, account handle is ___ and password on starter consoul is ____.

*/


void setup() {
  // Start More Religious Cycles of Life, on Religious HH Core
  
  
  Serial.begin(9600);
  
  // SET-UP INPUTS
  pinMode(obutton, INPUT);             // Breath alcohol [heartmonitor], ambient light [steeping|studymore], requires user testing
  SoftwareSerial bluetooth(16, 15);    // Pins for RX-In (16), TX-Out (15) for Steeper Souls Console. These may need to be reversed for production testing.

  // Sensor Optionalities for Branch Growths
  // [heartmonitor]: breath alcohol, fingerprint sensor
  // [steeping]: ambient light, * electronics off switch *  [* Zhongguo student strategy, suggested by Gezhi HS Student *]
  // [writingreading]: ambient noise
  // [speakinglistening]: 
  // 

  // SET-UP OUTPUTS
  pinMode(red_led, OUTPUT);     
  pinMode(green_led, OUTPUT);     
  pinMode(blue_led, OUTPUT);
  pinMode(buzzer, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  //obutton_state = oButtonReader();
  obutton_press_state = digitalRead(obutton);
  Serial.println(obutton_press_state);
  
  
}


int oButtonReader() {
  // put your main code here, to run repeatedly:
  obutton_press_state = digitalRead(obutton);

  if (obutton_press_state == 0 && obutton_press_state != last_obutton_press_state) {
    obutton_press_counter++;
    Serial.println(obutton_press_counter);
  }
  
  last_obutton_press_state = obutton_press_state;
  return obutton_press_counter;
}


// HELPER FUNCTIONS


void safetyorangeRGB() {
  analogWrite(red_led, 232);
  analogWrite(green_led, 118);
  analogWrite(blue_led, 0);
}

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
