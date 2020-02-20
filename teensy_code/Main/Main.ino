
#include "Ultrasonic.h" 

uint16_t sensors[2];

void setup() {
  //Serial.begin(9600); 
//  nh.getHardware()->setBaud(115200);
  nh.initNode();
  
  //initialize ultrasonic sensor message
  init_ultrasonic_msg();
}

void loop() { 
  read_sensors(sensors);
 // print_sensors(sensors);
  publish_sensor_msg();
  nh.spinOnce();  
}
