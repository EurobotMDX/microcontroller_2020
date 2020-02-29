
#include "Ultrasonic.h"
#include "Servo_Controller.h"
#include "ROS.h"

uint16_t sensors[2];

void setup() {
 
  //  nh.getHardware()->setBaud(115200);
  nh.initNode();
  init_servo_board();
  //initialize ultrasonic sensor message
  init_ultrasonic_msg();
  nh.subscribe(servo_controller);
}

void loop() {
  read_sensors(sensors);
  publish_sensor_msg();
  nh.spinOnce();

}
