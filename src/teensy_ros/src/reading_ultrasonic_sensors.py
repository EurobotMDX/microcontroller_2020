#!/usr/bin/env python
import rospy
from std_msgs.msg import UInt16MultiArray
import time
import psutil


def callback(data):
    global pid_output, pitch_angle
    for x in range(0,2):
        rospy.loginfo(rospy.get_caller_id() + " %f", data.data[x])
    rospy.loginfo("")

def listener():
    rospy.init_node('visualiser', anonymous=False)
    rospy.Subscriber("ultrasonic_sensors", UInt16MultiArray, callback)


def main():
    listener() 
    while 1:
        pass

if __name__ == '__main__':
    main()
    

