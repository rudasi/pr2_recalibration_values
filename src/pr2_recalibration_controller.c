#include "pr2_recalibration_values/pr2_recalibration_controller.h"
#include <pluginlib/class_list_macros.h>

namespace controller
{
Pr2RecalibrationValues::Pr2RecalibrationValues()
: joint_state_(NULL), robot_(NULL)
{
}

Pr2RecalibrationValues::~Pr2RecalibrationValues()
{
//need to figure out how to stop dervice
}

bool Pr2RecalibrationValues::init(pr2_mechanism_model::RobotState *robot, const std::string &joint_name)
{
  if(!robot)
  {
    ROS_ERROR("The given robot was NULL");
    return false;
  }
  robot_ = robot;

  joint_state_ = robot_->getJointState(joint_name);
  if(!joint_name_)
  {
    ROS_ERROR("Pr2RecalibrationController could not find the joint named \"%s\"",
            joint_name.c_str());
    return false;
  } 
  
  return true;
}

bool Pr2RecalibrationValues::init(pr2_mechanism_model::RobotState *robot, ros::NodeHandle &n)
{
  assert(robot);
  node_ = n;
  robot_ = robot;
  
  std::string joint_name;
  if(!node_.getParam("joint", joint_name))
  {
    ROS_ERROR("No joint given (namespace: %s)", node_.getNamespace().c_str());
    return false;
  }

  if (!(joint_state_ = robot_->getJointState(joint_name)))
  {
    ROS_ERROR("Could not find joint \"%s\" (namespace: %s)",
              joint_name.c_str(), node_.getNamespace().c_str());
    return false;
  }

  //need to advertise service and create srv file
}
   
void Pr2RecalibrationValues::update()
{


}

void Pr2CalibrationValues::stopping()
{
}


}

