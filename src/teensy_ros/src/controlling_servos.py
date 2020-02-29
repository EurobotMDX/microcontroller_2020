#!/usr/bin/env python
# license removed for brevity
import rospy
from std_msgs.msg import UInt16MultiArray
import servo as srv


def main():
#	pub = rospy.Publisher('open_close_servo', UInt16MultiArray, queue_size=10)
	rospy.init_node('talker', anonymous=True)
	# init servo class	
	servo_board = srv.ServoBoard() 
	#update loop every second(1hz)	
	rate = rospy.Rate(1)
	

	while not rospy.is_shutdown():
	#	pub.publish(servo_board.servo_angles)
		#servo_board.move_servo(3,30)	
		servo_board.open_all_servos()		
		rate.sleep()
		servo_board.close_all_servos()
		rate.sleep()

if __name__ == '__main__':
	try:	
		main()
	except rospy.ROSInterruptException:
		pass
