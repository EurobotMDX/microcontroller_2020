# microcontroller_2020

# Prerequisites

To run this code you need: 
* The teensy board with the sensors connected 
* Ubuntu 16.04 and ros kinetic 

# Running the code

The first step is to upload the code to the teensy. The files can be found in the teensy_code folder. Next run roscore on one of the terminals and on another terminal run the command 

```
rosrun rosserial_arduino serial_node.py _port:=/dev/ttyACM0
```

Next if you want to control the servo with rostopic pub you can use the command 

```
rostopic pub /open_close_servo std_msgs/UInt16MultiArray "layout:
  dim:
  - label: ''
    size: 16
    stride: 0
  data_offset: 0
data:
- 0
- 0
- 0
- 0
- 0
- 0
- 0
- 0
- 0
- 0
- 0
- 0
- 0
- 0
- 0
- 0"
```

Or you can run the python code using the command

```
rosrun teensy_ros controlling_servos.py
```

# Possible Issues

* If you are trying to run the command rostopic above and the terminal keeps inputting each line seperately with > on each line then you must first type ctrl + x then ctrl + e when nano opens up you can paste the command there then type ctrl x to save and run it.

* Don't ever Serial print with the teensy it makes it so that you can never run rosserial_arduino until you restart computer.

* If you get the error 'could not open port' when running the rosserial command then you must run the command sudo chmod 666 /dev/ttyACM0 (If this is not the port of the teensy you can find it by going to cd /dev and ls. The Teensy will be ttyACMx

* Don't upload arduino code while the rosserial node is running. It will make it so that your teensy port is no longer at ttyACM0 but ttyACM1 and every time you run rosserial the tty increments by 1

# To do list

* ~~Add teensy and ros code that will be able to control the servos with python~~ (Completed)

* Create a launch file 

* Create some documentation of PCB

* Add the CNC shield code

