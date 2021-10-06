## hyperparameters 

- in `OrcVIO-Object-Mapping/src/orcvio/obj/ObjectFeatureInitializer.cpp`, an initial scale `Eigen::Vector3d empirical_bbox_scale` is defined to accommodate the fact that the bounding box does not enclose the object tightly, this needs to be tuned for each type of object detection 

- in `OrcVIO-Object-Mapping/src/ObjectInitNode.cpp`, object distance thresholds `min_dist_btw_objects` and `max_dist_btw_cam_obj` are used to prune the objects that are too close to each other (possibly duplicates of the same object), and the object that is too far from the camera (possibly wrong object detection)

- in `orcvio_mapping/launch/om_unity_gq.launch`, there are parameters related with the object tracking thresholds, `max_object_feature_track` and `min_object_feature_track`, which refers to the maximum/minimum number of frames to track an object
   * if an object is lost before `min_object_feature_track` is reached, then it is discarded 
   * if an object is tracked long enough, which exceeds `max_object_feature_track`, then the object will be reconstructed and no longer tracked 