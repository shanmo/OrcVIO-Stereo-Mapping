cmake_minimum_required(VERSION 2.8.12)
project(orcvio_mapping)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

add_compile_options(-std=c++11)

# Modify cmake module path if new .cmake files are required
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    tf
    nav_msgs
    sensor_msgs
    geometry_msgs
    eigen_conversions
    tf_conversions
    tf2_ros
    nodelet
    image_transport
    cv_bridge
    message_filters
    pcl_conversions
    pcl_ros
    std_srvs
    sort_ros 
)
find_package(arl_perception_msgs QUIET)
if (${arl_perception_msgs_FOUND})
  ## message("arl_perception_msgs_FOUND; ${arl_perception_msgs_FOUND}")
  add_definitions("-DENABLE_ARL_PERCEPTION_MSGS")
  include_directories(${arl_perception_msgs_INCLUDE_DIRS})
endif()

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(SuiteSparse REQUIRED)
find_package(Ceres REQUIRED)
find_package(Sophus QUIET)
if (NOT ${Sophus_FOUND})
  find_package(sophus REQUIRED)
endif()

###################################
## catkin specific configuration ##
###################################
catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS
        roscpp std_msgs tf nav_msgs sensor_msgs geometry_msgs
        eigen_conversions tf_conversions message_runtime
        image_transport cv_bridge message_filters pcl_conversions
        pcl_ros std_srvs
    DEPENDS Boost EIGEN3 OpenCV SUITESPARSE
)

###########
## Build ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
    ${OpenCV_INCLUDE_DIRS}
    ${SUITESPARSE_INCLUDE_DIRS}
    ${CERES_INCLUDE_DIRS}
    ${Sophus_INCLUDE_DIRS}
)


# Object Mapper 
add_library(orcvio_mapping_core
    src/ObjectInitNode.cpp 
    src/orcvio/obj/ObjectFeature.cpp 
    src/orcvio/obj/ObjectFeatureInitializer.cpp 
    src/orcvio/obj/ObjectLM.cpp
    src/orcvio/obj/ObjectLMLite.cpp
    src/orcvio/obj/ObjectResJacCam.cpp
    src/orcvio/obj/ObjectState.cpp
    src/orcvio/feat/kf.cpp
    src/orcvio/feat/Feature.cpp
    src/orcvio/feat/FeatureInitializer.cpp
)

add_dependencies(orcvio_mapping_core
    ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(orcvio_mapping_core
  ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ${Boost_LIBRARIES}
  ${arl_perception_msgs_LIBRARIES}
  )

# Object Mapper node
add_executable(orcvio_mapping_node
    src/orcvio_mapping_node.cpp
)

add_dependencies(orcvio_mapping_node
    ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(orcvio_mapping_node
    orcvio_mapping_core
    ${catkin_LIBRARIES}
)



#############
## Install ##
#############

#install(TARGETS
#  orcvio_mapping_node 
#  orcvio_mapping_node 
#  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

#install(DIRECTORY include/
#  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#  PATTERN "*_nodelet.h" EXCLUDE
#)

#install(DIRECTORY
#    launch
#    ${PROJECT_SOURCE_DIR}/../../../config
#  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
#  )
