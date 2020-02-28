#ifndef ROS_H
#define ROS_H

#include <Arduino.h>
#include <ros.h>
#include <std_msgs/UInt16MultiArray.h>
#include <std_msgs/String.h>
#include <WProgram.h>
#include "Ultrasonic.h"
#include "Servo_Controller.h"

ros::NodeHandle nh;
std_msgs::UInt16MultiArray sensor_msg;

void servo_callback( const std_msgs::String& command)
{

  if (command.data[0] == 'o')
  {
    nh.loginfo("Servos Opened");
  }
    if (command.data[0] == 'c')
  {
    nh.loginfo("Servos Closed");
  }

}

ros::Publisher ultrasonic_sensors("ultrasonic_sensors", &sensor_msg);
ros::Subscriber<std_msgs::String> servo_controller("open_close_servo", servo_callback);



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
