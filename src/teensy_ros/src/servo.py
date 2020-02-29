#!/usr/bin/env python
import rospy
from std_msgs.msg import UInt16MultiArray

class ServoBoard():
	servo_angles = UInt16MultiArray()
	servo_angles.data = [0 for i in range(16)]
	def __init__(self):
		self.pub = rospy.Publisher('open_close_servo', UInt16MultiArray, queue_size=10)
	
	def move_servo(self, servo_to_move, angle_to_move_to):
		self.servo_angles.data[servo_to_move] = angle_to_move_to
		self.pub.publish(self.servo_angles)	
	
	def close_all_servos(self):
		self.servo_angles.data = [0 for i in range(16)]
		self.pub.publish(self.servo_angles)

	def open_all_servos(self):
		self.servo_angles.data = [180 for i in range(16)]
		self.pub.publish(self.servo_angles)	

		
