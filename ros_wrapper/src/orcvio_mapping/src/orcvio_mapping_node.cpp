#include <ros/ros.h>
#include "ObjectInitNode.h"

using namespace orcvio_mapping;

int main(int argc, char **argv) {

    // Create ros node
    ros::init(argc, argv, "orcvio_mapping");
    ros::NodeHandle nh("~");

    // Debug
    // ROS_INFO("Done reading config values");
  
    ObjectInitNode object_mapper(nh);

    // Done!
    ros::spin();
    return EXIT_SUCCESS;

}
