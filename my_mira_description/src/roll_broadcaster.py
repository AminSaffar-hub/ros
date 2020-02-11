#!/usr/bin/env python 
import rospy
import tf

if __name__=='__main__':
    rospy.init_node('roll_link')
    br1 =tf.TransformBroadcaster()
    rate = rospy.Rate(3.0)
    while not rospy.is_shutdown():
        br1.sendTransform((0.0,0.0,0.0),
                          (0.0,0.0,0.0,1.0),
                          rospy.Time.now(),
                          "roll_M1_link",
                          "map")
        rate.sleep()