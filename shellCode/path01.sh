cd /home/lbdbot01/catkin_ws
source /home/lbdbot01/catkin_ws/devel/setup.sh


rostopic pub --once RCmd std_msgs/UInt16 "data: 88"

rostopic pub --once RCmd std_msgs/UInt16 "data: 88"

sleep 3
rostopic pub RCmd std_msgs/UInt16 "data: 10" &

#sleep 3

#roslaunch rplidar_ros rplidar_lbd.launch &

#sleep 3
#rosrun lbdbot_cmd_override lbdbot_cmd_override &

sleep 3
rosrun lbdbot_path_run01 lbdbot_path_run01


