#! /bin/bash


source /home/lbdbot01/catkin_ws/devel/setup.sh
sleep 3
sudo chmod 666 /dev/aduMega01 
sleep 1
rosrun rosserial_python serial_node.py __name:="motion_controller_01" _port:=/dev/aduMega01 _baud:=500000 &

sleep 6
sudo chmod 666 /dev/sensorBoard
sleep 1
cd /home/lbdbot01/catkin_ws
rosrun rosserial_python serial_node.py __name:="sensor_board_01" _port:=/dev/sensorBoard _baud:=250000 &

sleep 10
rosrun lbdbot_tf lbdbot_tf_node &

sleep 5
rostopic pub -1 RCmd std_msgs/UInt16 10 &

sleep 3
cd /home/lbdbot01/catkin_ws
sudo chmod 666 /dev/rplidar
roslaunch rplidar_ros rplidar_lbd.launch &

#sleep 10
#cd /home/lbdbot01/camtest
#python3 cam03.py

sleep 3
cd /home/lbdbot01/catkin_ws
rosrun lbdbot_cmd_override lbdbot_cmd_override &

cd /home/lbdbot01/catkin_ws

