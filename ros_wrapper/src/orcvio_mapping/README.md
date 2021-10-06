# about 

This repo is used in OrcVIO [project website](http://me-llamo-sean.cf/orcvio_githubpage/), [Journal version](https://arxiv.org/abs/2007.15107)

If you find this repo useful, kindly cite our publications 

```
@article{orcvio,
  title={OrcVIO: Object residual constrained Visual-Inertial Odometry},
  author={M. {Shan} and Q. {Feng} and N. {Atanasov}},
  url = {http://erl.ucsd.edu/pages/orcvio.html},
  pdf = {https://arxiv.org/abs/2007.15107},
  journal={IEEE Transactions on Robotics},
  volume={},
  number={},
  pages={},
  year={2021},
  publisher={IEEE}
}    
```

# orcvio mapping demo 

- Download rosbag: [link]( https://www.dropbox.com/sh/bovb04lrb0l745r/AAA69peH_ELWLNzvkTwoeRB4a?dl=0&lst=&preview=indoor_vio5_2020-11-03-18-44-15.bag)

- Run

```
roslaunch orcvio_mapping orcvio_object_mapping_dcist.launch rosbag_path:=/Download Folder/darknet_sort-ros_2021-04-11-19-46-21.bag
```

* Parameters

  * min_dist_btw_objects: minimum distance between two objects.

  * max_dist_btw_cam_obj: maximum distance between the first viewpoint and object.

    


  
