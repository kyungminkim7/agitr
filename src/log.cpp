#include <ros/ros.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "log");
  ros::NodeHandle nh;

  ros::Rate loopRate(10.0);

  for (auto i = 1; ros::ok(); ++i, loopRate.sleep()) {
    ROS_DEBUG_STREAM("Counted to " << i);

    auto mod = 3;
    if (i % mod == 0) {
      ROS_INFO_STREAM(i << " is divisible by " << mod);
    }

    mod = 5;
    if (i % mod == 0) {
      ROS_WARN_STREAM(i << " is divisible by " << mod);
    }

    mod = 10;
    if (i % mod == 0) {
      ROS_ERROR_STREAM(i << " is divisible by " << mod);
    }

    mod = 20;
    if (i % mod == 0) {
      ROS_FATAL_STREAM(i << " is divisible by " << mod);
    }
  }
}
