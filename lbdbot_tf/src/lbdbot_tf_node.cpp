#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
    ros::init(argc, argv, "lbdbot_tf");
    ros::NodeHandle n;

    ros::Rate r(10);
    
    tf::TransformBroadcaster broadcaster;

    while(n.ok()){
        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(
                    tf::Quaternion(0,0,0,1), 
                    tf::Vector3(0.0, 0.0, 0.1)),
                ros::Time::now(),
                "base_footprint",
                "base_link"
            )
        );

        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(
    //                tf::Quaternion(0,0,0.9999996829318346,0.00079632671073326), 
    //                tf::Quaternion(0,0,0,1), 
                      tf::Quaternion(0.9999996829318346,0,0,0.00079632671073326), 
                    tf::Vector3(0.1, 0.0, 0.24)),
                ros::Time::now(),
                "base_link",
                "laser"
            )
        );

        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(
    //                tf::Quaternion(0,0,0.9999996829318346,0.00079632671073326), 
                    tf::Quaternion(0,0,0,1), 
                    tf::Vector3(0.15, 0.0, 0.15)),
                ros::Time::now(),
                "base_link",
                "camera_link"
            )
        );

        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(
    //                tf::Quaternion(0,0,0.9999996829318346,0.00079632671073326), 
                    tf::Quaternion(0,0.3420201,0,0.9396926), 
                    tf::Vector3(0.15, 0.0, 0.850)),
                ros::Time::now(),
                "base_link",
                "camera1_link"
            )
        );
                broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(
    //                tf::Quaternion(0,0,0.9999996829318346,0.00079632671073326), 
                    tf::Quaternion(0,-0.3420201,0,0.9396926), 
                    tf::Vector3(0.15, 0, 0.15)),
                ros::Time::now(),
                "base_link",
                "camera2_link"
            )
        );


     //   broadcaster.sendTransform(
    //        tf::StampedTransform(
    //            tf::Transform(
    //                tf::Quaternion(0,0,0,1), 
    //                tf::Vector3(0, 0,0.0)),
    //            ros::Time::now(),
    //            "map",
    //            "odom"
    //        )
    //    );

        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(
                    tf::Quaternion(0.7068252,0,0,0.7073883), 
                    tf::Vector3(0.1, 0.23, 0.09)),
                ros::Time::now(),
                "base_link",
                "wheel_left_link"
            )
        );

        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(
                    tf::Quaternion(-0.7068252,0,0,0.7073883), 
                    tf::Vector3(0.1, -0.23, 0.09)),
                ros::Time::now(),
                "base_link",
                "wheel_right_link"
            )
        );

        broadcaster.sendTransform(
            tf::StampedTransform(
                tf::Transform(
                    tf::Quaternion(0.7068252,0,0,0.7073883), 
                    tf::Vector3(-0.2, 0, 0.02)),
                ros::Time::now(),
                "base_link",
                "caster_back_link"
            )
        );
    
        r.sleep();

    }
    
    }
