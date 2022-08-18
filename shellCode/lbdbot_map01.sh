
cd /home/lbdbot/catkin_ws
source ./devel/setup.sh

sleep 5
roslaunch rplidar_ros rplidar_lbd.launch &

#sleep 10
#rosbag record --duration=60 /scan /tf &

sleep 20
roslaunch gmapping slam_gmapping_lbd.launch

