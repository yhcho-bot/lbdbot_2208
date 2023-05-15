#include <ros/ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf2/LinearMath/Quaternion.h>



bool forward_max_btn;
bool forward_75_btn;
bool forward_50_btn;
bool forward_25_btn;
bool zero_speed_btn;
bool backward_max_btn;
bool backward_75_btn;
bool backward_50_btn;
bool backward_25_btn;
bool move_1m_f;
bool move_2m_f;
bool move_1m_b;

bool btn_in=false;
bool move_in=false;
int btn_num=0;
int move_num=0;
nav_msgs::Odometry pose;
float lx, ly, lz, ax, ay, az;

void forward_max_btn_callback(const std_msgs::Bool& lis_msg){  forward_max_btn = lis_msg.data;}
void forward_75_btn_callback(const std_msgs::Bool& lis_msg){   forward_75_btn = lis_msg.data;}
void forward_50_btn_callback(const std_msgs::Bool& lis_msg){   forward_50_btn = lis_msg.data;}
void forward_25_btn_callback(const std_msgs::Bool& lis_msg){    forward_25_btn = lis_msg.data;}
void zero_speed_btn_callback(const std_msgs::Bool& lis_msg){   zero_speed_btn = lis_msg.data;}
void backward_max_btn_callback(const std_msgs::Bool& lis_msg){   backward_max_btn = lis_msg.data;}
void backward_75_btn_callback(const std_msgs::Bool& lis_msg){   backward_75_btn = lis_msg.data;}
void backward_50_btn_callback(const std_msgs::Bool& lis_msg){   backward_50_btn = lis_msg.data;}
void backward_25_btn_callback(const std_msgs::Bool& lis_msg){   backward_25_btn = lis_msg.data;}
void move_1m_f_callback(const std_msgs::Bool& lis_msg){   move_1m_f = lis_msg.data;}
void move_2m_f_callback(const std_msgs::Bool& lis_msg){   move_2m_f = lis_msg.data;}
void move_1m_b_callback(const std_msgs::Bool& lis_msg){   move_1m_b = lis_msg.data;}

void odom_callback(const nav_msgs::Odometry::ConstPtr& msg) {
   lx = msg->pose.pose.position.x;
   ly = msg->pose.pose.position.y;
   lz = msg->pose.pose.position.z;
   ax = msg->pose.pose.orientation.x;
   ay = msg->pose.pose.orientation.y;
   az = msg->pose.pose.orientation.z;

}

int main(int argc, char** argv){
    ros::init(argc, argv, "speed_btn");
    ros::NodeHandle n;

    ros::Subscriber forward_max_btn_sub = n.subscribe("/forward_max_btn", 1000, forward_max_btn_callback);
    ros::Subscriber forward_75_btn_sub = n.subscribe("/forward_75_btn", 1000, forward_75_btn_callback);
    ros::Subscriber forward_50_btn_sub = n.subscribe("/forward_50_btn", 1000, forward_50_btn_callback);
    ros::Subscriber forward_25_btn_sub = n.subscribe("/forward_25_btn", 1000, forward_25_btn_callback);
    ros::Subscriber zero_speed_btn_sub = n.subscribe("/zero_speed_btn", 1000, zero_speed_btn_callback);
    ros::Subscriber backward_max_btn_sub = n.subscribe("/backward_max_btn", 1000, backward_max_btn_callback);
    ros::Subscriber backward_75_btn_sub = n.subscribe("/backward_75_btn", 1000, backward_75_btn_callback);
    ros::Subscriber backward_50_btn_sub = n.subscribe("/backward_50_btn", 1000, backward_50_btn_callback);
    ros::Subscriber backward_25_btn_sub = n.subscribe("/backward_25_btn", 1000, backward_25_btn_callback);
    ros::Subscriber move_1m_f_sub = n.subscribe("/move_1m_f", 1000, move_1m_f_callback);
    ros::Subscriber move_2m_f_sub = n.subscribe("/move_2m_f", 1000, move_2m_f_callback);
    ros::Subscriber move_1m_b_sub = n.subscribe("/move_1m_b", 1000, move_1m_b_callback);
    ros::Subscriber odom_sub = n.subscribe("/odom", 1000, odom_callback);

    ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1);
    ros::Publisher goal_pub = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 1);

    float nMax_speed;

    //n.getParam("speed_btn/max_speed", nMax_speed);
    nMax_speed = 1.6;
    ros::Rate r(200);
    
    geometry_msgs::Twist cmd_vel_tmp;
    geometry_msgs::PoseStamped goal;
    tf2::Quaternion myQ;

    goal.pose.position.x = lx;
    goal.pose.position.y = ly;
    goal.pose.position.z = lz;
    myQ.setRPY(ax, ay, az);
    goal.pose.orientation.x = myQ.getX();
    goal.pose.orientation.y = myQ.getY();
    goal.pose.orientation.z = myQ.getZ();
    goal.pose.orientation.w = myQ.getW();

    float old_speed=0;
    
    while(ros::ok()){
        if (forward_max_btn==true) { btn_in = true;    btn_num = 1; }
        if (forward_75_btn==true ) { btn_in = true;    btn_num = 2; }
        if (forward_50_btn==true)  { btn_in = true;    btn_num = 3; }
        if (forward_25_btn==true)  { btn_in = true;    btn_num = 4; }
        if (zero_speed_btn==true)  { btn_in = true;    btn_num = 5; }
        if (backward_max_btn==true){ btn_in = true;    btn_num = 6; }
        if (backward_75_btn==true) { btn_in = true;    btn_num = 7; }
        if (backward_50_btn==true) { btn_in = true;    btn_num = 8; }
        if (backward_25_btn==true) { btn_in = true;    btn_num = 9; }
        if (move_1m_f == true) { move_in =true; move_num =1; }
        if (move_2m_f == true) { move_in =true; move_num =2; }
        if (move_1m_b == true) { move_in =true; move_num =3; }

        if (move_in == true){
           switch(move_num){
              case 1:{
                 move_in = false;
                 goal.pose.position.x +=1;
                 goal_pub.publish(goal);
                 break;
              }
              case 2:{
                 move_in = false;
                  goal.pose.position.x +=2;
                 goal_pub.publish(goal);
                 break;
              }

              case 3:{
                 move_in = false;
                  goal.pose.position.x -=1;
                 goal_pub.publish(goal);
                 break;
              }

              default:{}
           }
        }

        if (btn_in==true) {
            switch(btn_num) {
                case 1:{ old_speed=nMax_speed;  
                         btn_in = false; 
                         cmd_vel_tmp.linear.x = old_speed;
                         vel_pub.publish(cmd_vel_tmp); 
                         } break;
                case 2:{ old_speed=nMax_speed*0.75;  
                         btn_in = false;
                         cmd_vel_tmp.linear.x = old_speed;
                         vel_pub.publish(cmd_vel_tmp); 
                         } break; 
                case 3:{ old_speed=nMax_speed*0.5;  
                            btn_in = false;
                         cmd_vel_tmp.linear.x = old_speed;
                         vel_pub.publish(cmd_vel_tmp); 
                          } break;
                case 4:{ old_speed=nMax_speed*0.25;  
                            btn_in = false; 
                         cmd_vel_tmp.linear.x = old_speed;
                         vel_pub.publish(cmd_vel_tmp); 
                         } break;
                case 5:{ old_speed=0;  
                         btn_in = false;
                         cmd_vel_tmp.linear.x = old_speed;
                         vel_pub.publish(cmd_vel_tmp); 
                          } break;
                case 6:{ old_speed=-nMax_speed;  
                         btn_in = false; 
                         cmd_vel_tmp.linear.x = old_speed;
                         vel_pub.publish(cmd_vel_tmp); 
                         } break;
                case 7:{ old_speed=-nMax_speed*0.75;  
                         btn_in = false; 
                         cmd_vel_tmp.linear.x = old_speed;
                         vel_pub.publish(cmd_vel_tmp); 
                         } break;
                case 8:{ old_speed=-nMax_speed*0.5;  
                         btn_in = false;
                         cmd_vel_tmp.linear.x = old_speed;
                         vel_pub.publish(cmd_vel_tmp); 
                         } break; 
                case 9:{ old_speed=-nMax_speed*0.25;  
                         btn_in = false; 
                         cmd_vel_tmp.linear.x = old_speed;
                         vel_pub.publish(cmd_vel_tmp);  } break;
                default: old_speed = old_speed;                        
                        break;
            }
         }

        ros::spinOnce();

        r.sleep();

       }
    
    }
