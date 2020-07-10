
/// \file PlannerCommonDef.h
/// \brief Definition file for control related data types
/// \author Hatem Darweesh
/// \date Dec 14, 2016


#ifndef PLANNERCOMMONDEF_H_
#define PLANNERCOMMONDEF_H_

#include <math.h>
#include <string>

namespace PlannerHNS
{

enum VEHICLE_TYPE {SMALL_VEHICLE,  NORMAL_VEHICLE,  MINI_VAN_VEHICLE,  BUS_VEHICLE,  ROBOT_VEHICLE };

class PID_CONST
{
public:
	double kP;
	double kI;
	double kD;

	PID_CONST()
	{
		kP = kI = kD = 0;
	}

	PID_CONST(const double& p, const double& i, const double& d)
	{
		kP = p;
		kI = i;
		kD = d;
	}
};

class ControllerParams
{
public:
	double SimulationSteeringDelay;
	double SteeringDelay;
	double minPursuiteDistance;
	double LowpassSteerCutoff;
	int ControlFrequency;
	PID_CONST Steering_Gain;
	PID_CONST Velocity_Gain;
	PID_CONST Accel_Gain;
	PID_CONST Brake_Gain;

	ControllerParams()
	{
		SimulationSteeringDelay = 0.0;
		SteeringDelay = 0.8;
		LowpassSteerCutoff = 5.0;
		minPursuiteDistance = 2.0;
		ControlFrequency = 25;
	}
};

class CAR_BASIC_INFO
{
public:
	VEHICLE_TYPE model = NORMAL_VEHICLE;

  double turning_radius = 5.2; // meters
  double wheel_base = 2.7; // meters
  double length = 4.3; // meters
  double width = 1.82; // meters

  double max_speed_forward = 10; // m/s
  double min_speed_forward = 0.0; // m/s speed that is considered stopping, to avoid small speed noise

  double max_steer_value = 660; // degrees, total steering wheel angle to the right
  double max_wheel_angle = 0.42; // radians, max angle for the front wheel = asin(wheel_base/turning_radius);

  double max_accel_value = 100.0; // accel pedal stroke force
  double max_brake_value = 100; // brake pedal stroke force
  double max_steer_torque = 100; // steering torque force
  double min_steer_torque = -100; // steering torque force

  double max_acceleration = 1.5; // m/s*s
  double max_deceleration = -1.5; // m/s*s
};


} /* namespace PlannerHNS */

#endif /* PLANNERCOMMONDEF_H_ */
