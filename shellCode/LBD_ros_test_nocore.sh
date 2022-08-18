#! /bin/bash


source /home/lbdbot/catkin_ws/devel/setup.sh
sleep 3
sudo chmod 666 /dev/aduMega 
rosrun rosserial_python serial_node.py __name:="motion_controller" _port:=/dev/aduMega _baud:=500000 &

sleep 6
sudo chmod 666 /dev/sensorBoard
rosrun rosserial_python serial_node.py __name:="sensor_board" _port:=/dev/sensorBoard _baud:=250000 &

sleep 10
rosrun lbdbot_tf lbdbot_tf_node &

sleep 5
rostopic pub -1 RCmd std_msgs/UInt16 10 &

sleep 3
sudo chmod 666 /dev/rplidar
roslaunch rplidar_ros rplidar_lbd.launch &


sleep 3
cd /home/lbdbot/catkin_ws
rosrun lbdbot_cmd_override lbdbot_cmd_override &

cd /home/lbdbot/catkin_ws

