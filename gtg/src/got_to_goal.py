#!/usr/bin/env python


import rospy 
import actionlib 
from move_base_msgs.msg import MoveBaseAction,MoveBaseGoal
from actionlib_msgs.msg import * 
from geometry_msgs.msg import Point



def move_to_goal(xGoal , yGoal):
    ac = actionlib.SimpleActionClient("move_base",MoveBaseAction)

    while(not ac.wait_for_server(rospy.Duration.from_sec(5.0)) ):
        rospy.loginfo("still waiting")
    goal = MoveBaseGoal()

    goal.target_pose.header.frame_id = "map"
    goal.target_pose.header.stamp = rospy.Time.now()

    goal.target_pose.pose.position = Point(xGoal,yGoal,0)
    goal.target_pose.pose.orientation.x = 0.0
    goal.target_pose.pose.orientation.y = 0.0
    goal.target_pose.pose.orientation.z = 0.0
    goal.target_pose.pose.orientation.w = 1.0

    rospy.loginfo("sending goal location")
    ac.send_goal(goal)

    ac.wait_for_result(rospy.Duration(60))

    if(ac.get_state() == GoalStatus.SUCCEEDED):
        rospy.loginfo("goal_succeded")
        return True
    else:
        rospy.loginfo("goal_failed")
        return False

if __name__ =='__main__' :
    rospy.init_node('map_navigation',anonymous=False)
    x_goal = 2
    y_goal = 2
    move_to_goal(x_goal,y_goal)
    x_goal = 0
    y_goal = 2
    move_to_goal(x_goal,y_goal)
    x_goal = 0
    y_goal = 0
    move_to_goal(x_goal,y_goal)
    #rospy.spin()





