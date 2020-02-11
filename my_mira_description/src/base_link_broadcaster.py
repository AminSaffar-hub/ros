#!/usr/bin/env python 
import rospy
import tf

if __name__=='__main__':
    rospy.init_node('my_fixed_base')
    br =tf.TransformBroadcaster()
    rate = rospy.Rate(3.0)
    while not rospy.is_shutdown():
        br.sendTransform((0.0,0.0,0.0),
                         (0.0,0.0,0.0,1.0),
                         rospy.Time.now(),
                         "base_link",
                         "map")
        rate.sleep()