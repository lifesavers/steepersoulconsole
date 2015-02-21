
/**************************************************************************/
/*! 
  @file     SSC.cpp
  @author   Adam David Clayman （粘土人） (adam@lifesavers.io)

*/
/**************************************************************************/

#include <Arduino.h>
#include "SSC.h"

// 2, 4, 9, 11, 12, 13

 	// DIGITAL PIN DEFINITIONS
		// Open Digital Pins: 13
  		// PWM-Capable Pins: 3, 5, 6, 9, 10, 11
		const int mhz433_receiver = 0; // On interrupt #2; Reads same frequency (433 MHz) as many garage door openers (~PWM capable)
		const int mhz433_transmitter = 1; // Transmits on same frequency (433 MHz) as many garage door openers(~PWM capable)
		// Pin 2 = VR Shield *ITR
		const int blue_led = 3; // (~PWM capable)
		// const int safeorange_line = 4; // (~PWM capable) // Pin 4 = VR Shield
		const int green_led = 5; // (~PWM capable) *ITR
		const int red_led = 6; // (~PWM capable)
		const int ir_receiver = 7; // ITR*
//		const int tbutton = 8; // Shifted to obutton. Currently the primary consent and call button. Life-saving alerting tool.
		// Pin 9 = VR Shield (~PWM Capable)	
		const int buzzer = 10; // Buzzer for triggered intermittent and continuous alarm sounds
		// Pin 11 = VR Shield (~PWM capable)
		// Pin 12 = VR Shield
//		const int fingerprint_sensor_tx = 13; // Out from Arduino Yun as tx to fingerprint sensor as rx (~PWM capable)

	// ANALOG PIN DEFINITIONS
		// Open Analog Pins: A3/17, A4/18, A5/19
		const int breath_alcohol_sensor = A0; // Corresponds to digital I/0 pin 14. Analog Input Pin 0, maps 0-5V voltage reading to 0-1023
		const int bt_tx = 15; // Yellow hotwire, labelled as rx on the HC-06 Bluetooth Module, the signal is transmitted out from the Arduino's perspective (tx)
		const int bt_rx = 16; // Green hotwire, labelled as tx on the HC-06 Bluetooth Module, the signal is received from the Arduino's perspective (rx)
		const int obutton = 18; // Site for safety orange relief code. Triggers, and acts as ∱TEAMtable mode switch when sustained.
		// const int green_inactivation_button = 17; // Green inactivation button, ideally a headboard mini-button; Digital I/O 17 corresponds to Analog Input Pin 3. Used to cycle-down from GREEN(s) to resting state only. Can not be used to inactivate "Code Red" or "Code Blue"
		// A5 is empty

	// DIGITAL INTERRUPT DEFINITIONS
		// Pin 3 (interrupt 0)
		// Pin 2 (interrupt 1)
		// Pin 0 (interrupt 2)
		// Pin 1 (interrupt 3)
		// Pin 7 (interrupt 4)

	// COUNTER DEFINITIONS
		int obutton_press_state = 1;
		int last_obutton_press_state = 1;
		int obutton_press_counter = 0;
		int last_obutton_press_counter = 0;

// What's not presently enabled: Fingerprint sensor, Brush sensors

	// DISPLACED PERSONS (DUE TO VOICE RECOGNITION SHIELD)
	//	const int fingerprint_sensor_rx = 2; // In from fingerprint sensor tx to Arduino Yun (as rx)
