#!/usr/bin/env python
import rospy 
from geometry_msgs.msg import Twist 
from nav_msgs.msg import Odometry 
import math
import tf 

print('----------------------------------------')
print('Roll-Pitch-Yaw Conversion to quaternions')
print('----------------------------------------')

roll = math.radians(30)
pitch = math.radians(42)
yaw = math.radians(58)

print('roll',math.degrees(roll),'pitch',math.degrees(pitch),'yaw',math.degrees(yaw))

quaternion = tf.transformations.quaternion_from_euler(roll,pitch,yaw)

print('----------------------------------------')
print('the resulting quaternions')

for i in range(0,4):
    print(quaternion[i])


rpy = tf.transformations.euler_from_quaternion(quaternion)
roll = rpy[0]
pitch = rpy[1]
yaw = rpy[2]

print('----------------------------------------')
print('convert back to euler from quaternion')
print('----------------------------------------')

print('roll',math.degrees(roll),'pitch',math.degrees(pitch),'yaw',math.degrees(yaw))
