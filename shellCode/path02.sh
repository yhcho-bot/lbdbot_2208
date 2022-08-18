cd /home/lbdbot/catkin_ws
source /home/lbdbot/catkin_ws/devel/setup.sh


rostopic pub --once RCmd std_msgs/UInt16 "data: 88"

rostopic pub --once RCmd std_msgs/UInt16 "data: 21"

sleep 3
rostopic pub RCmd std_msgs/UInt16 "data: 10" &

sleep 3

#roslaunch rplidar_ros rplidar_lbd.launch &

#sleep 3
#rosrun lbdbot_cmd_override lbdbot_cmd_override &

sleep 3
rosrun lbdbot_path_run02 node


