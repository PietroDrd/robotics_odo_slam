#include "../include/TFOdometryBroadcaster.h"


TFOdometryBroadcaster::TFOdometryBroadcaster()
{
    Subscriber = nh.subscribe("odom", 1000, &TFOdometryBroadcaster::CLBKTfCallback, this);
}

void TFOdometryBroadcaster::CLBKTfCallback(const nav_msgs::Odometry::ConstPtr& msg)
{

  tf::Transform transform;
  transform.setOrigin( tf::Vector3(msg->pose.pose.position.x, msg->pose.pose.position.y, msg->pose.pose.position.z) );
  transform.setRotation(tf::Quaternion(msg->pose.pose.orientation.x,msg->pose.pose.orientation.y,msg->pose.pose.orientation.z,msg->pose.pose.orientation.w));
  static tf::TransformBroadcaster br;
  br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "odom", "base_link"));


}

int main (int argc, char**argv)
{
    ros::init(argc, argv, "tf_gen");
    TFOdometryBroadcaster Br;
    ros::spin();
    return 0;
}



