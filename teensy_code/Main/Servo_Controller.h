#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!

#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

#define NUMBER_OF_SERVOS 16 //Number of servos
const uint16_t min_servo_value[NUMBER_OF_SERVOS] = {80,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
const uint16_t max_servo_value[NUMBER_OF_SERVOS] = {540,540,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint16_t servo_angles[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void init_servo_board(){
  
  pwm.begin();
  // In theory the internal oscillator is 25MHz but it really isn't
  // that precise. You can 'calibrate' by tweaking this number till
  // you get the frequency you're expecting!
  pwm.setOscillatorFrequency(27000000);  // The int.osc. is closer to 27MHz  
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
}

void open_servo(uint8_t servo_to_open){
  pwm.setPWM(servo_to_open,0,max_servo_value[servo_to_open]);
}

void close_servo(uint8_t servo_to_close){
  pwm.setPWM(servo_to_close,0,min_servo_value[servo_to_close]);
}

void open_all_servos(){
  for(int i=0; i<NUMBER_OF_SERVOS;i++){
    pwm.setPWM(i,0,max_servo_value[i]);
  }
}

void close_all_servos(){
  for(int i=0; i<NUMBER_OF_SERVOS;i++){
    pwm.setPWM(i,0,min_servo_value[i]);
  }
}

uint16_t get_pulse_from_angle(uint16_t servo_min, uint16_t servo_max, uint8_t desired_angle){
  return map(desired_angle,0,180,servo_min,servo_max);
}

void set_servo_angles(){
  for(int i=0; i<16; i++){
    uint16_t pulse = get_pulse_from_angle(min_servo_value[i],max_servo_value[i], servo_angles[i]);
    pwm.setPWM(i, 0, pulse);
  }
}

#endif
