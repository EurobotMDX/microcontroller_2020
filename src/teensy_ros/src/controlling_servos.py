#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import UInt16MultiArray

def talker():
	pub = rospy.Publisher('open_close_servo', UInt16MultiArray, queue_size=10)
	rospy.init_node('talker', anonymous=True)
	rate = rospy.Rate(1) # 10hz
	servo_data = UInt16MultiArray()
	servo_data.data = []
	a = 0	
	while not rospy.is_shutdown():
		if a == 0:
			servo_data.data = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
			a=1		
		if a == 1:
			servo_data.data = [180,180,180,180,180,180,180,180,180,180,180,180,180,180,180,180]		
			a = 1		
		pub.publish(servo_data)
		rate.sleep()
	
if __name__ == '__main__':
	try:
		talker()
	except rospy.ROSInterruptException:
		pass
