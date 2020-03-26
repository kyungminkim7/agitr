#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pubvel");
  ros::NodeHandle nh;

  auto pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);

  srand(time(nullptr));

  ros::Rate loop_rate(2);
  while (ros::ok()) {
    geometry_msgs::Twist msg;
    msg.linear.x = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    msg.angular.z = 2.0 * static_cast<double>(rand()) / static_cast<double>(RAND_MAX) - 1.0;

    pub.publish(msg);

    ROS_INFO_STREAM("Sending vel: " << " linear=" << msg.linear.x << " angular=" << msg.angular.z);

    loop_rate.sleep();
  }

  return 0;
}
