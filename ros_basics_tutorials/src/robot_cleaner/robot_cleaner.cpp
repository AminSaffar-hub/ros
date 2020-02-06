#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>


double x,y,yaw;
ros::Publisher velocity_publisher ;
ros::Subscriber pose_subscriber ;
turtlesim::Pose t_p;
const double PI = 3.14159265359;

void poseCallback(const turtlesim::Pose::ConstPtr& pose_msg)
{
t_p.x = pose_msg->x;
t_p.y = pose_msg->y;
t_p.theta = pose_msg->theta;
}

double getDistance(double x1, double y1, double x2, double y2){
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}

double degrees2radians(double angle_in_degrees){
	return angle_in_degrees *PI /180.0;
}

void move(float speed ,float distance , bool isForward)
{
// variable declaration    
float distance_moved = 0.0 ;
geometry_msgs::Twist velocity_message;
ros::Rate loop_rate(10);

//speed setting
if(isForward)
    velocity_message.linear.x = abs(speed);
else 
    velocity_message.linear.x = -abs(speed);
double t0 = ros::Time::now().toSec();

//keep sendig velocity messages while u've not reached the required distance
do
{
    velocity_publisher.publish(velocity_message);
    double t1 = ros::Time::now().toSec();
    distance_moved = speed*(t1-t0);
    ros::spinOnce(); 
    loop_rate.sleep();
}while (distance_moved < distance);

//tell the robot to stop distance reached 
velocity_message.linear.x = 0;
velocity_publisher.publish(velocity_message);
ros::spinOnce(); 
loop_rate.sleep();
}

void rotate(float angular_speed ,float angle , bool isCloackwise)
{
//variables declarations
geometry_msgs::Twist velocity_message;
float angle_moved = 0;
ros::Rate loop_rate(10);

//resetting all velocities
velocity_message.linear.x = 0;
velocity_message.linear.y = 0;
velocity_message.linear.z = 0;
velocity_message.angular.x = 0;
velocity_message.angular.y = 0;
velocity_message.angular.z = 0;

//velocity settings 
if (isCloackwise)
{
    velocity_message.angular.z = -angular_speed;
}else
{
    velocity_message.angular.z = angular_speed;
}

//keep sendig velocity messages while u've not reached the required angle
double t0 = ros::Time::now().toSec();
do 
{
    velocity_publisher.publish(velocity_message);
    double t1 = ros::Time::now().toSec();
    angle_moved = (t1-t0) * angular_speed ;
    ros::spinOnce(); 
    loop_rate.sleep();
}while(angle_moved < angle);

//tell the robot to stop turning 
velocity_message.angular.z = 0;
velocity_publisher.publish(velocity_message);
ros::spinOnce(); 
loop_rate.sleep();
}





int main(int argc, char **argv)
{
    // Initiate a new ROS node named "listener"
	ros::init(argc, argv, "robot_cleaner");
	//create a node handle: it is reference assigned to a new node
	ros::NodeHandle n;
    pose_subscriber = n.subscribe("/turtle1/pose",1000,poseCallback);
    velocity_publisher =  n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",10);
    move(0.4,3,true);
    rotate(0.4,PI/2,false);
    move(0.4,3,true);
}
