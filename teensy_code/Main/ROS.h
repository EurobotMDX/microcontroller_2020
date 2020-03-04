#ifndef ROS_H
#define ROS_H

#include <Arduino.h>
#include <ros.h>
#include <std_msgs/UInt16MultiArray.h>
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include <std_msgs/String.h>
#include <WProgram.h>
#include "Ultrasonic.h"
#include "Servo_Controller.h"

ros::NodeHandle nh;
std_msgs::UInt16MultiArray sensor_msg;



void servo_callback( const std_msgs::UInt16MultiArray& command)
{
  char error_buffer [1000];
  for (int i = 0; i < 16; i++) {
    servo_angles[i] = command.data[i];
    //lines below print servo angles to the terminal
      sprintf(error_buffer, "Angles Servo1:%d Servo2:%d Servo3:%d Servo4:%d Servo5:%d Servo6:%d Servo7:%d Servo8:%d Servo9:%d Servo10:%d Servo11:%d Servo12:%d Servo13:%d Servo14:%d Servo15:%d Servo16:%d", servo_angles[0], servo_angles[1], servo_angles[2], servo_angles[3], servo_angles[4], servo_angles[5], servo_angles[6], servo_angles[7], servo_angles[8], servo_angles[9], servo_angles[10], servo_angles[11], servo_angles[12], servo_angles[13], servo_angles[14], servo_angles[15]);
      nh.loginfo(error_buffer);
  }
    set_servo_angles();
}

ros::Publisher ultrasonic_sensors("ultrasonic_sensors", &sensor_msg);
ros::Subscriber<std_msgs::UInt16MultiArray> servo_controller("open_close_servo", servo_callback);



//code from https://answers.ros.org/question/37185/how-to-initialize-a-uint8multiarray-message/
void init_ultrasonic_msg() {
  sensor_msg.layout.dim = (std_msgs::MultiArrayDimension *)malloc(sizeof(std_msgs::MultiArrayDimension) * 2);
  sensor_msg.layout.dim[0].label = "height";
  sensor_msg.layout.dim[0].size = 2;
  sensor_msg.layout.dim[0].stride = 1;
  sensor_msg.layout.data_offset = 0;
  sensor_msg.data = (std_msgs::UInt16MultiArray::_data_type*) malloc(2 * sizeof(std_msgs::UInt16MultiArray::_data_type)); // https://answers.ros.org/question/285670/rosserial-multi-array-issue/
  sensor_msg.data_length = 2;
  nh.advertise(ultrasonic_sensors);
}

//publish messages
void publish_sensor_msg() {
  ultrasonic_sensors.publish(&sensor_msg);
}


#endif
