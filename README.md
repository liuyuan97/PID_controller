# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

[video1]: p_tuning.mp4 "Video1"
[video2]: challenge_video_proc.mp4 "Video2"

## Requirements

* The Term 2 Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases).  
* Set up and install [uWebSocketIO](https://github.com/uWebSockets/uWebSockets) for either Linux or Mac systems
*
## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Components

* main.cpp -  read the measurements with the simulator, calls a PID related functions, and send the control commands to the simulator
* pid.cpp - PID class including the initialize, error computation, and final control command


## PID Parameter Tuning

The following material comes from this [link](https://en.wikipedia.org/wiki/PID_controller#Manual_tuning). 

### PID Parameter

The distinguishing feature of the PID controller is the ability to use the three control terms of proportional, integral and derivative influence on the controller output to apply accurate and optimal control. The following table shows effects of increasing one of three parameter independently, proportional parameter K_p, integral parameter K_i, and derivative parameter K_d. 


| Parameter |	Rise time	|	Overshoot	|	Settling time	|	Steady-state error	|	Stability		|
|:---------:|:-------------:|:-------------:|:-----------------:|:---------------------:|:-----------------:|
|	K_p		|	Decrease	|	Increase	|	Small change	|	Decrease			|	Degrade			|
|	K_i		|	Decrease	|	Increase	|	Increase		|	Eliminate			|	Degrade			|
|	K_d		|	Minor change|	Decrease	|	Decrease		|	No effect in theory	|	Improve if small|

Base on the above theory, we manually tuned the PID parameter as the following.

### Proportional Parameter Tuning
The first step is to increase the K_p until the output of the loop oscillates while keep the K_i and K_d as zeros. Then, the K_p should be set to approximately half of that value.  For this control system, we found the K_p to be 0.3 so that the car swings left and right along the lane as shown in this [video](p_tuning.mp4). Then, we chose the K_p as 0.15.

### Integral Parameter Tuning
The second step is to increase the K_i until any offset is corrected in sufficient time for the process while keep K_d as 0.15, and K_d as zero.  We found the K_i to be 0.00001 that removes the offset effects.  This [video](i_tuning.mp4) confirms this.

### Derivative Parameter Tuning
The third step is to increase the K_d to increase the system response time. We found that K_d to be 2.5 is a good number as shown in this [record](d_tuning.mp4).  This concludes our PID parameter tuning.


