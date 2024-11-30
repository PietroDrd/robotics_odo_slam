Dardano Pietro
Desiderato Lorenzo
Ghilotti Filippo
___________________________________________________________________________

-- LAUNCH --
project2.launch -> launches the node responsible to create the Odometry TF broadcaster (to create baselink odom)

gmapping.launch -> opens RVIZ, launches the laser scan merger and creates the map

localization.launch -> opens RVIZ and runs amcl 

-- CONFIG --
amcl_config.launch 
gmapping_config.launch  
scan_merger_config.launch

contain all the parameters needed by the launchers.
The last one contains also the static transformation needed to create the TF tree (we have overwrote the laser_front and laser_rear transforms since the latter doesen't appear all the times).

REMARK: in scan_merger_config.launch for localization purpouses we had to comment the last line (row 19) of code, however it's mandatory for mapping !!


-- INCLUDE --
TFOdometryBroadcaster.h -> defines the class for the SRC node


-- SRC -- 
TFOdometryBroadcaster.cpp -> node that publish the odometry as a tf


-- MAP --
mao_provider.launch -> service that save the map created with gmapping

MAP FILES: map.pgm, map.yaml, grid.pgm

___________________________________________________________________________

TF TREE: map -> odom ->baselink -> laser_front
			        -> laser_rear
___________________________________________________________________________

robotics1_final.bag for mapping
robotics2_final.bag for testing
robotics3_final.bag for testing
___________________________________________________________________________

Package name: progetto_robotics_seconda_parte

roslaunch progetto_robotics_seconda_parte gmapping.launch
					  localization.launch

rosbag play robotics1_final.bag 		(to create the map)
rosbag play robotics2_final.bag --clock		(for localization, NB:  /use_sim_time: true)

___________________________________________________________________________

We included two images, saved directly from RVIZ, with the trajectories based on amcl localization as we couldn't use a service to create the images with the trajectories.

