#include "ros/ros.h"
#include "hello_ros/MyMessage.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "talker2");

    ros::NodeHandle n;
    ros::Publisher my_message_pub = n.advertise<hello_ros::MyMessage>("my_message", 1000);
    ros::Rate loop_rate(10);

    int count = 0;

    while(ros::ok()){
        hello_ros::MyMessage msg;
        msg.message = "Hello! World";
        msg.count = count;

        ROS_INFO("%s %ld", msg.message.c_str(), msg.count);
        my_message_pub.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}