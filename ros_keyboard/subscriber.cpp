
#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  // ROS_INFO("I heard: [%s]", msg->data.c_str());
  ROS_INFO("%s", msg->data.c_str() );

/*
  if(msg->data.c_str() == "stop"){
    ROS_INFO("%s", "stop the car");
  }
  else if(msg->data.c_str() == "W"){
    ROS_INFO("%s", "move forward");
  }

*/

}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("keyboard_control", 1000, chatterCallback);
  ros::spin();
  return 0;
}
