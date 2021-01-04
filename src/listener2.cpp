#include "ros/ros.h"
#include "hello_ros/MyMessage.h"

void chatterCallback(const hello_ros::MyMessage::ConstPtr& msg){
    ROS_INFO("I heard: [%s] / Count: [%ld]", msg->message.c_str(), msg->count);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "listener1");

    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("my_message", 1000, chatterCallback);
    ros::spin();

    return 0;
}