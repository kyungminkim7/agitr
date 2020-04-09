#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

namespace {
ros::Publisher pub;
}

void onCmdVelReceived(const geometry_msgs::Twist &twist) {
  auto twistReversed(twist);
  twistReversed.linear.x *= -1;
  twistReversed.angular.z *= -1;
  pub.publish(twistReversed);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "reverse_cmd_vel");

  ros::NodeHandle nh;
  pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel_reversed", 1000);
  auto sub = nh.subscribe("turtle1/cmd_vel", 1000, &onCmdVelReceived);

  ros::spin();

  return 0;
}
