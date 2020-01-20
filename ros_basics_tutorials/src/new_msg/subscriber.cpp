#include "ros/ros.h"
#include "ros_basics_tutorials/IoTSensor.h"

// Topic messages callback
void IoTSensorCallback(const ros_basics_tutorials::IoTSensor::ConstPtr& msg)
{
    ROS_INFO("[Listener] I recieved : \n id= %d \n temp = %f \n humidity = %f \n", msg->id,msg->temperature,msg->humidity);
}

int main(int argc, char **argv)
{
    // Initiate a new ROS node named "listener"
	ros::init(argc, argv, "listener_node");
	//create a node handle: it is reference assigned to a new node
	ros::NodeHandle node;


    // Subscribe to a given topic, in this case "IoTSensor".
	//chatterCallback: is the name of the callback function that will be executed each time a message is received.
    ros::Subscriber sub = node.subscribe("IoTSensor", 1000, IoTSensorCallback);

    // Enter a loop, pumping callbacks
    ros::spin();

    return 0;
}
