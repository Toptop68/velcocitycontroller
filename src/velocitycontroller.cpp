#include "ros.h"
#include <std_msgs/Header>
#include <std_msgs/Empty.h>
#include <yocs_controllers/velocitycontrol.hpp>
#include <yocs_controllers/default_controller.hpp>
#include <string>
#include <people_msgs/PositionMeasurement.h>

using namespace std;
void setParameters();

int main(int argc, char **argv)
{
ros::init(argc, argv, "velocitycontrol");

ros::NodeHandle n; //Enables ROS nodes

float DistanceToFace = 1; //Data from sensors
ros::Rate loop_rate(2); //Update rate

while (ros::ok())
  {
ros::Subscriber sub = n.subscribe("/sensorPosition", 1000, SetParameters); //Subscribe to topic /sensorPosition
ros::spinOnce();
loop_rate.sleep(); //Delay function
  }
}


void SetParameters(){ //Function that sets parameters. Sends to parameter server.

  n.setParam("max_vel_x", to_string(-(1.8/0.7)*(DistanceToFace)+3.78)); //linear math function to set speed depending on distance (ax+b)
/*
  if(DistanceToFace > 3) { // Checks DistanceToFace float and publishes fitting velocity parameters.
    n.setParam("max_vel_x", "0.0"); // 0% of max speed
    n.setParam("min_vel_X", "0.0");
    n.setParam("max_rotational_vel", "3.14");
    n.setParam("min_in_place_rotational_vel", "3.14");
  }

  else if (DistanceToFace > 2.64 && DistanceToFace < 3){ //
    n.setParam("max_vel_x", "0.14"); // 20% of max speed
    n.setParam("min_vel_X", "0.0");
    n.setParam("max_rotational_vel", "3.14");
    n.setParam("min_in_place_rotational_vel", "3.14");
  }
  else if(DistanceToFace > 2.28 && DistanceToFAce < 2.65){
    n.setParam("max_vel_x", "0.28"); // 40% of max speed
    n.setParam("min_vel_X", "0.0");
    n.setParam("max_rotational_vel", "3.14");
    n.setParam("min_in_place_rotational_vel", "3.14");
  }
  else if(DistanceToFace > 1.92 && DistanceToFace < 2.29){
    n.setParam("max_vel_x", "0.42"); // 60% of max speed
    n.setParam("min_vel_X", "0.0");
    n.setParam("max_rotational_vel", "3.14");
    n.setParam("min_in_place_rotational_vel", "3.14");
  }
  else if(DistanceToFace > 1.56 && DistanceToFace < 1.93){
    n.setParam("max_vel_x", "0.56"); // 80% of max speed
    n.setParam("min_vel_X", "0.0");
    n.setParam("max_rotational_vel", "3.14");
    n.setParam("min_in_place_rotational_vel", "3.14");
  }
  else if(DistanceToFace > 1.2 && DistanceToFace < 1.57){
    n.setParam("max_vel_x", "0.7"); // 100% of max speed
    n.setParam("min_vel_X", "0.2");
    n.setParam("max_rotational_vel", "3.14");
    n.setParam("min_in_place_rotational_vel", "3.14");
  }
  */
}
