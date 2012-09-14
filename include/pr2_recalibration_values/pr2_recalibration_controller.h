#ifndef PR2_RECALIBRATION_CONTROLLER_H
#define PR2_RECALIBRATION_CONTROLLER_H

#include <pr2_controller_interface/controller.h>
#include <pr2_mechanism_model/joint.h>

namespace controller 
{

class Pr2RecalibrationValues: public pr2_controller_interface::Controller
{
private: 
  pr2_mechanism_model::JointState* joint_state_; 
  pr2_mechanism_model::JointState* robot_;
  ros::NodeHandle node_;
  ros::ServiceServer srv_;

public:
  Pr2RecalibrationValues();
  ~Pr2RecalibrationValues();
  bool init(pr2_mechanism_modem::RobotState *robot, const std::string &joint_name);
  virtual bool init(pr2_mechanism_model::RobotState *robot, ros::HodeHandle &n);
  virtual void starting();
  virtual void update();
  virtual void stopping();
};
}

#endif
