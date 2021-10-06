## detection type conversion  

In order to use rosbags with topic `/husky/detection` of `arl-unity-ros` message type, we need to convert it to sort ros bbox message type. Follow these steps 

- source the sort ros bbox type, via `source devel/setup.bash`
- use `scripts/process_rosbag/convert_detection_to_bboxes.py` to perform the conversion, one example is 
```
python convert_detection_to_bboxes.py --template_bag /home/erl/orcvio/dataset/simulation/docker_compose_opcity_car_door_quad_bboxes_only.bag --input_bag /home/erl/orcvio/dataset/simulation/orc_vio_bag_2021-09-24-15-11-18.bag --output_bag /home/erl/orcvio/dataset/simulation/orcvio_bag_2021-09-24-15-11-18_bboxes.bag
```

## intrinsics 

```
# camera instrinsic
camera_model: "pinhole"       # only support "pinhole"
distortion_model: "radtan"    # only support "radtan" and "equidistant"
resolution_width: 640
resolution_height: 480
intrinsics:
   fx: 260.99805320956386
   fy: 260.99805320956386
   cx: 320
   cy: 240
distortion_coeffs:
   k1: 0
   k2: 0
   p1: 0
   p2: 0
```

## extrinsics 

- the topics in tf are `husky/camera` and `husky/imu` 
- use `rosrun tf tf_echo husky/imu husky/camera` to get the `rosrun tf tf_echo [reference_frame] [target_frame]`, output is 
```
- Translation: [0.300, 0.000, -0.000]
- Rotation: in Quaternion [0.500, -0.500, 0.500, -0.500]
            in RPY (radian) [-1.571, -0.000, -1.571]
            in RPY (degree) [-90.000, -0.000, -90.000]
```

## launch files 

- on the main branch, run `roslaunch orcvio orcvio_unity_object_gq.launch`
- on the stereo mapping branch, run `roslaunch orcvio orcvio_unity_gq.launch` 