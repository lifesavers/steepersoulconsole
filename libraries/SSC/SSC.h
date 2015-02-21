
/**************************************************************************/
/*! 
  @file     SSC.h
  @author   Adam David Clayman （粘土人） (adam@lifesavers.io)

*/
/**************************************************************************/
#ifndef SSC_H
#define SSC_H

extern const char *hello;

//PIN DECLARATIONS
extern const int mhz433_receiver;
extern const int mhz433_transmitter;
extern const int fingerprint_sensor_rx;
extern const int fingerprint_sensor_tx;
extern const int ir_receiver;
extern const int red_led;
extern const int green_led;
extern const int blue_led;
extern const int buzzer;
extern const int breath_alcohol_sensor;
extern const int bt_tx;
extern const int bt_rx;
extern const int obutton; // safety_orange_button = obutton or orange_button
extern const int sound;

// COUNTER DECLARATIONS
extern int obutton_press_state;
extern int last_obutton_press_state;
extern int obutton_press_counter;
extern int last_obutton_press_counter;
#endif