#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <math>

double x,y,yaw;
ros::Publisher velocity_publisher ;

void poseCallback(const turtlesim::Pose::constPtr& pose_msg)
{
x = pose_msg.x;
y = pose_msg.y;
yaw = pose_msg.theta;
}

void move(float speed ,float distance , bool isForward)
{
double x0=x,y0=y,yaw0=yaw;
float distance_moved = 0.0 ;
geometry_msgs::Twist velocity_message;
if(is_forward)
    velocity_message.linear.x = abs(speed);
else 
    velocity_message.linear.x = -abs(speed);
}
ros::rate loop_rate(10);
velocity_publisher =  n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
while (distance_moved < distance)
{
    ROS_INFO("turtle_sim moves forward");
    velocity_publisher.publish(velocity_message);
    distance_moved = abs(0.5*sqrt(pow((x-x0),2)+pow((y-y0),2)));
    ROS_INFO("distance walked = %f",distance_moved);
    ros::spinOnce(); 
    loop_rate.sleep();
}
velocity_message.linear.x = 0;
velocity_publisher.publish(velocity_message);
ros::spinOnce(); 
loop_rate.sleep();
}





int main(int argc, char **argv)
{
    // Initiate a new ROS node named "listener"
	ros::init(argc, argv, "robot_cleaner");
	//create a node handle: it is reference assigned to a new node
	ros::NodeHandle node;
    ros::Subscriber pose_subscriber = n.Subscribe("/turtle1/pose",1000,poseCallback);
    move(10,10,true);
}
