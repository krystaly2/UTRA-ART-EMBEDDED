
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>
#include <termios.h> //for terminal I/O interfaces

//get char from keyboard input
int getch()
{
  static struct termios oldt, newt;
  tcgetattr( STDIN_FILENO, &oldt);           // save old settings
  newt = oldt; 
  newt.c_lflag &= ~(ICANON);                 // disable buffering      
  tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new settings

  int c = getchar();  // read character (non-blocking)

  tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
  return c;
}



int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "publisher");
  ros::NodeHandle n;
  ros::Publisher keyboard_control_pub = n.advertise<std_msgs::String>("keyboard_control", 1000);
  ros::Rate loop_rate(10);

bool isGetChar = 0;
int c;
int old_c;

  
  
  while (ros::ok())
{
  



c = getch();   // call your non-blocking input function

    std::stringstream ss;

if (c == 'w')
    { ROS_INFO("%s", "w pressed ");
      ss << "W";} 
  else if (c == 'a')
    { ROS_INFO("%s", "a pressed ");
      ss << "A";}
  else if (c == 's')
    { ROS_INFO("%s", "s pressed ");
      ss << "S";}
  else if (c == 'd')
    { ROS_INFO("%s", "d pressed ");
      ss << "D";}



    
  //set up the msg
    std_msgs::String msg;


msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    keyboard_control_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();

  

}

return 0;
}
