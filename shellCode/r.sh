sleep 5
cd /home/lbdbot01/catkin_ws
source /home/lbdbot01/catkin_ws/devel/setup.sh

sleep 2
#roslaunch rplidar_ros rplidar_lbd.launch & 

sleep 5
#roslaunch lbdbot_launch lbd_navigation.launch &
roslaunch lbdbot_launch lbd_to_amcl.launch &

sleep 5
roslaunch lbdbot_launch lbd_navigation_only.launch &

sleep 10
#rviz -d /home/lbdbot01/catkin_ws/navigation.rviz &
