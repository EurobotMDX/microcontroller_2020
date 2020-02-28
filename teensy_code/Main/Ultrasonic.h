#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "ROS.h"
#include <Arduino.h>
#include <ros.h>
#include <std_msgs/UInt16MultiArray.h>
#include <WProgram.h>
#include <NewPing.h>

/* Ultrasonic Sensor */
#define SONAR_NUM 2      // Number of sensors.
#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(5, 4, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(13, 14, MAX_DISTANCE)
};
/*-------------*/


//reads and saves data in an array
void read_sensors(uint16_t * array_of_readings){
  for(int number_of_sensors; number_of_sensors < SONAR_NUM; number_of_sensors++){
    sensor_msg.data[number_of_sensors] = sonar[number_of_sensors].ping_cm(); // update ros msg
    delay(50);//necessary for sensors to work
  }
}


#endif
