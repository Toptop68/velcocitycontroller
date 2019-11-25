#include "ros.h"
#include <string>
#include <people_msgs/PositionMeasurementArray.h>

using namespace std;

void SetParameters(const people_msgs::PositionMeasurementArray msg);

ros::init(argc, argv, "velocitycontrol");
ros::NodeHandle n; //Enables ROS nodes

int main(int argc, char **argv)
{
ros::Rate loop_rate(2); //Update rate

while (ros::ok())
  {
ros::Subscriber sub = n.subscribe("/sensorPosition", 1000, SetParameters); //Subscribe to topic /sensorPosition
ros::spinOnce();
loop_rate.sleep(); //Delay function
  }
}

float DistanceToFace = 1; //Data from sensors
void SetParameters(const people_msgs::PositionMeasurementArray msg){ //Function that sets parameters. Sends to parameter server.

  n.setParam("max_vel_x", to_string(-(1.8/0.7)*(DistanceToFace+3.78)); //linear math function to set speed depending on distance (ax+b)

}
