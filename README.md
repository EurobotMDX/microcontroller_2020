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

Then you can either listen to the topic using rostopic with the following command

```
rosrun rosserial_arduino serial_node.py _port:=/dev/ttyACM0
```

Or you can run the python interpreter that prints out the values using the command 

```
rosrun teensy_ros reading_ultrasonic_sensors.py 
```

# To do list

* Plot the data coming from the ultrasonic sensors using some python library

* Add teensy and ros code that will be able to control the servos with python

* Create a launch file 

* Create some documentation on the pinouts of the stripboard

* Add the CNC shield 
