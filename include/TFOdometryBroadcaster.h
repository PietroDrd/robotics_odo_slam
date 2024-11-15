#ifndef __TFODOMETRYBROADCASTER_SOURCE__

#include "ros/ros.h"
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include "nav_msgs/Odometry.h"



class TFOdometryBroadcaster 
{
private:
    ros::NodeHandle nh;
    ros::Subscriber Subscriber;
    
     
public:
    TFOdometryBroadcaster();   
    void CLBKTfCallback(const nav_msgs::Odometry::ConstPtr& msg);
    
    
};

#define __TFODOMETRYBROADCASTER_SOURCE__
#endif // #ifndef __TFODOMETRYBROADCASTER_SOURCE__