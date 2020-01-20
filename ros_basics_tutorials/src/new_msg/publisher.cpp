#include "ros/ros.h"
#include "ros_basics_tutorials/IoTSensor.h"


int main(int argc, char **argv)
{
	// Initiate new ROS node named "talker_node"
	ros::init(argc, argv, "talker_node");

	//create a node handle: it is reference assigned to a new node
	ros::NodeHandle n;
	//create a publisher with a topic "IoTSensor" that will send a String message
	ros::Publisher chatter_publisher = n.advertise<ros_basics_tutorials::IoTSensor>("IoTSensor", 1000);
	//Rate is a class the is used to define frequency for a loop. Here we send a message each second.
	ros::Rate loop_rate(1); //1 message per second

   int count = 0;
   while (ros::ok()) // Keep spinning loop until user presses Ctrl+C
   {
       
	   ros_basics_tutorials::IoTSensor msg;

       
       msg.id = 1;
       msg.name = "IoTsensor1";
       msg.temperature = 38.5;
       msg.humidity = 35;

       //print the content of the message in the terminal
       ROS_INFO("[Talker] I published \n id= %d \n name = %s \n temp = %f \n humidity = %f \n", msg.id,(msg.name),msg.temperature,msg.humidity);

       //Publish the message
       chatter_publisher.publish(msg);

       ros::spinOnce(); // Need to call this function often to allow ROS to process incoming messages

      loop_rate.sleep(); // Sleep for the rest of the cycle, to enforce the loop rate
       count++;
   }
   return 0;
}


