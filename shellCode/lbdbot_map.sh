
cd /home/lbdbot01/catkin_ws
source ./devel/setup.sh

sleep 5
roslaunch rplidar_ros rplidar.launch &

sleep 10
#roslaunch hector_slam_launch LBD_slam.launch
rosrun gmapping slam_gmapping scan:=base_scan

sleep 50
rosbag record -O --duration=5m scan_data /scan /tf
