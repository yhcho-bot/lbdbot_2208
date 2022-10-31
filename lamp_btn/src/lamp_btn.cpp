#include <ros/ros.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/Bool.h>

bool lamp_on_btn;
bool lamp_on2_btn;
bool lamp_on3_btn;
bool lamp_off_btn;
bool lamp_btn_in= false;
int lamp_num;

void lamp_on_btn_callback(const std_msgs::Bool& lis_msg){
    lamp_on_btn = lis_msg.data;
}
void lamp_on2_btn_callback(const std_msgs::Bool& lis_msg){
    lamp_on2_btn = lis_msg.data;
}
void lamp_on3_btn_callback(const std_msgs::Bool& lis_msg){
    lamp_on3_btn = lis_msg.data;
}
void lamp_off_btn_callback(const std_msgs::Bool& lis_msg){
    lamp_off_btn = lis_msg.data;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "lamp_btn");
    ros::NodeHandle n;

    ros::Publisher lamp_btn_pub = n.advertise<std_msgs::UInt16>("RCmd", 1000);
    ros::Subscriber lamp_on_btn_sub = n.subscribe("/lamp_on_btn", 1000, lamp_on_btn_callback);
    ros::Subscriber lamp_on_btn2_sub = n.subscribe("/lamp_on2_btn", 1000, lamp_on2_btn_callback);
    ros::Subscriber lamp_on_btn3_sub = n.subscribe("/lamp_on3_btn", 1000, lamp_on3_btn_callback);
    ros::Subscriber lamp_off_btn_sub = n.subscribe("/lamp_off_btn", 1000, lamp_off_btn_callback);
    
    ros::Rate r(5);
    
    while(n.ok()){
    
        std_msgs::UInt16 pub_msg;
        if (lamp_on_btn==true) { lamp_btn_in = true;    lamp_num = 1; }
        if (lamp_on2_btn==true) { lamp_btn_in = true;    lamp_num = 2; }
        if (lamp_on3_btn==true) { lamp_btn_in = true;    lamp_num = 3; }

        if (lamp_off_btn==true) {
            lamp_btn_in = false;
            }

        if (lamp_btn_in==true) {
            if (lamp_num ==1) {
                pub_msg.data=21;
            }
            if (lamp_num == 2) {
                pub_msg.data=25;
            }            
            if (lamp_num == 3) {
                pub_msg.data=27;
            }  
         }
        else {
            pub_msg.data = 20;
        }

        lamp_btn_pub.publish(pub_msg);

        ros::spinOnce();

        r.sleep();

       }
    
    }
