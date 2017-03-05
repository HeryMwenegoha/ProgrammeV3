#pragma once
#include "AP_Parameters.h"
#include "Common.h"
#include "AHRS.h"
#include "PID_INFO.h"

#include "AP_AHRS.h"
#include "AP_Airspeed.h"

class AP_RollController
{
	public: 
	AP_RollController(){
		//gains = (_gains*)malloc(sizeof(_gains)); // allocate some memory to gains
	};
	void initialise(AP_Storage *, AP_AHRS *);
	float servo_out(float, float, float);
	
	private:
	float _rate_out(float, float, float);   // deg/sec;			
	pid_info _pid_info;
	_gains gains;
	
	float _speed;
	float _output;
	uint32_t _last_Msec;
	
	protected:
	AP_AHRS *_ahrs;
	
};