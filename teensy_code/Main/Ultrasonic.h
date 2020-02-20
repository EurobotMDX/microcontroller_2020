#ifndef ULTRASONIC_H
#define ULTRASONIC_H

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


/*ROS Stuff*/
ros::NodeHandle nh;
std_msgs::UInt16MultiArray sensor_msg;
ros::Publisher ultrasonic_sensors("ultrasonic_sensors", &sensor_msg);
/*-------------*/

//code from https://answers.ros.org/question/37185/how-to-initialize-a-uint8multiarray-message/
void init_ultrasonic_msg(){
  sensor_msg.layout.dim = (std_msgs::MultiArrayDimension *)malloc(sizeof(std_msgs::MultiArrayDimension)*2);
  sensor_msg.layout.dim[0].label = "height";
  sensor_msg.layout.dim[0].size = 2;
  sensor_msg.layout.dim[0].stride = 1;
  sensor_msg.layout.data_offset = 0;
  sensor_msg.data = (std_msgs::UInt16MultiArray::_data_type*) malloc(2 * sizeof(std_msgs::UInt16MultiArray::_data_type)); // https://answers.ros.org/question/285670/rosserial-multi-array-issue/
  sensor_msg.data_length = 2;
  nh.advertise(ultrasonic_sensors);
}
//reads and saves data in an array
void read_sensors(uint16_t * array_of_readings){
  for(int number_of_sensors; number_of_sensors < SONAR_NUM; number_of_sensors++){
    array_of_readings[number_of_sensors] = sonar[number_of_sensors].ping_cm();
    sensor_msg.data[number_of_sensors] = sonar[number_of_sensors].ping_cm(); // update ros msg
    delay(50);//necessary for sensors to work
  }
}
//Serial prints sensor values for debugging
void print_sensors(uint16_t * array_of_readings){
  for(int number_of_sensors; number_of_sensors < SONAR_NUM; number_of_sensors++){
    Serial.print(array_of_readings[number_of_sensors]);
    Serial.print("\t");
  }
  Serial.println("");
}
//publish messages
void publish_sensor_msg(){
  ultrasonic_sensors.publish(&sensor_msg);
}



#endif
