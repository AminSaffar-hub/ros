#!/usr/bin/env python 

import roslib
import rospy
import tf 
import time
import math

if __name__ == '__main__':
    rospy.init_node('frame_a_frame_b_broadcaster_node')
    time.sleep(2)
    tf_broadcaster = tf.TransformBroadcaster()

    while(not rospy.is_shutdown()):
        rot_q = tf.transformations.quaternion_from_euler(0.2,0.3,0.1)
        trans_v = (1.0,2.0,3.0)

        current_time = rospy.Time.now()
        tf_broadcaster.sendTransform(
            trans_v,
            rot_q,
            current_time,
            "frame_b","frame_a"
        )
        time.sleep(0.5)
    rospy.spin()