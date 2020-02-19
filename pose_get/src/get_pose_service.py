#!/usr/bin/env python

from pose_get.srv import Pose
from pose_get.srv import PoseRequest
from pose_get.srv import PoseResponse
from geometry_msgs.msg import PoseWithCovarianceStamped
from geometry_msgs.msg import PoseWithCovariance
import rospy


current_pose = PoseWithCovariance()
def pose_callback(pos):
    global current_pose
    current_pose = pos.pose
    rospy.loginfo("message recieved")
#    current_pose.pose.position.x = pos.pose.pose.position.x
#    current_pose.pose.position.y = pos.pose.pose.position.y
#    current_pose.pose.position.z = pos.pose.pose.position.z
#    current_pose.pose.orientation.x = pos.pose.pose.orientation.x
#    current_pose.pose.orientation.y = pos.pose.pose.orientation.y
#    current_pose.pose.orientation.z = pos.pose.pose.orientation.z
#    current_pose.pose.orientation.w = pos.pose.pose.orientation.w
#    current_pose.covariance = pos.pose.covariance
    

def pose_responce(req):
    return PoseResponse(current_pose)
def node():
    rospy.init_node('get_pose', anonymous=True)
    rospy.Subscriber('/amcl_pose',PoseWithCovarianceStamped, pose_callback)
    rospy.Service('pose', Pose, pose_responce) 
    rospy.spin()
if __name__ == "__main__":
    node()   