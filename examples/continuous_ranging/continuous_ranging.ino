#include "Seeed_vl53l0x.h"
Seeed_vl53l0x VL53L0X;

void setup()
{ 
	VL53L0X_Error Status = VL53L0X_ERROR_NONE;
	Serial.begin(115200);
	Status=VL53L0X.VL53L0X_common_init();
	if(VL53L0X_ERROR_NONE!=Status)
	{
		Serial.println("start vl53l0x mesurement failed!");
		VL53L0X.print_pal_error(Status);
		while(1);
	}
	VL53L0X.VL53L0X_continuous_ranging_init();
	if(VL53L0X_ERROR_NONE!=Status)
	{
		Serial.println("start vl53l0x mesurement failed!");
		VL53L0X.print_pal_error(Status);
		while(1);
	}
}


void loop()
{
	VL53L0X_RangingMeasurementData_t RangingMeasurementData;
	VL53L0X.PerformContinuousRangingMeasurement(&RangingMeasurementData);
}


