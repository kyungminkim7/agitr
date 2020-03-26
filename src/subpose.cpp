#include <iomanip>

#include <ros/ros.h>
#include <turtlesim/Pose.h>

void onPoseReceived(const turtlesim::Pose &pose) {
  ROS_INFO_STREAM(std::setprecision(2) << std::fixed <<
                  "position=(" << pose.x << "," << pose.y << ") " <<
                  "direction=" << pose.theta);
}

int main(int argc, char *argv[]) {
    ros::init(argc, argv, "subpose");
    ros::NodeHandle nh;

    auto sub = nh.subscribe("turtle1/pose", 1000, &onPoseReceived);

    ros::spin();

    return 0;
}
