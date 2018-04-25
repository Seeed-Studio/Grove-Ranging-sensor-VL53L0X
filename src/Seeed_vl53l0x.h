#ifndef _SEEED_VL53L0X_H
#define _SEEED_VL53L0X_H

#include <Arduino.h>
#include <Wire.h>

#include "vl53l0x_api.h"
#include "vl53l0x_platform.h"
#include "required_version.h"

#define DEBUG_EN
#define IIC_DEFAULT_ADDR  0x29
#define CONTINUOUS_MODE_MESURE_TIME  5

class Seeed_vl53l0x
{
	typedef unsigned int   u32;
	typedef unsigned short u16;
	typedef unsigned char  u8;
	public:
		~Seeed_vl53l0x(){}
		void print_pal_error(VL53L0X_Error Status);

		VL53L0X_Error VL53L0X_common_init();
		VL53L0X_Error VL53L0X_single_ranging_init();
		VL53L0X_Error VL53L0X_high_speed_ranging_init();
		VL53L0X_Error VL53L0X_high_accuracy_ranging_init();
		VL53L0X_Error VL53L0X_long_distance_ranging_init();
		VL53L0X_Error VL53L0X_continuous_ranging_init();

		VL53L0X_Error PerformSingleRangingMeasurement(VL53L0X_RangingMeasurementData_t* RangingMeasurementData);
		VL53L0X_Error PerformContinuousRangingMeasurement(VL53L0X_RangingMeasurementData_t* RangingMeasurementData);
	private:
		void VL53L0X_IIC_init(u8 IIC_ADDRESS = IIC_DEFAULT_ADDR);
		VL53L0X_Error check_version();
		VL53L0X_Error VL53L0X_set_limit_param();
		VL53L0X_Error VL53L0X_calibration_oprt();
		VL53L0X_Error VL53L0X_calibration_set();
		
		
		VL53L0X_Dev_t MyDevice;
		VL53L0X_Dev_t *pMyDevice = &MyDevice;
		VL53L0X_Version_t   Version;
		VL53L0X_Version_t   *pVersion   = &Version;
		//VL53L0X_DeviceInfo_t DeviceInfo;
		
};


#endif