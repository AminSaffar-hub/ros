#!/usr/bin/env python

import rospy
from std_srvs import srv 


def call_service():
    rospy.wait_for_service('/global_localization')
    client=rospy.ServiceProxy('/global_localization',srv.Empty)
    client()
if __name__ == "__main__":
    call_service()