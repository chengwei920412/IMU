#ifndef PID_H_
#define PID_H_
#ifdef __cplusplus
 extern "C" {
#endif
#include "stm32f4xx.h"
#include "math_nb.h"

#define PID_TRUE  0xff
#define PID_FALSE 0x00

#define PID_DT 0.02//500HZ

struct PID{
	float target;  // Ä¿±êÖµ
	float current; // µ±Ç°Öµ
	float merror;
	float last_error;
	float Integrator;	//µ±Ç°»ý·ÖÖµ
	float deriv;
	float last_deriv;
	float iLimit;
	float Kp;	   //±ÈÀý
	float Ki;	   //»ý·Ö
	float Kd;	   //Î¢·Ö

	unsigned char Lowpass_EN;
	float outP;         //< proportional output (debugging)
  	float outI;         //< integral output (debugging)
  	float outD;         //< derivative output (debugging)
	float PID_out;   //µ±Ç°PID µÄÊä³ö
};

extern struct PID TEMPERATURE;

#define DEFAULT_PID_INTEGRATION_LIMIT  15.0

void pidInit(struct PID* pid, const float kp,
             const float ki, const float kd);
float pidUpdate(struct PID* pid, float measured,float dt);
float pidUpdate_err(struct PID* pid,float err, float dt);
void pidSetIntegralLimit(struct PID* pid, float limit);
void pidSetError(struct PID* pid, float err);
void pidReset(struct PID* pid);
void pidSetTarget(struct PID* pid, float target);
void pidSetKp(struct PID* pid, float kp);
void pidSetKi(struct PID* pid, float ki);
void pidSetKd(struct PID* pid, float kd);
void pidSet(struct PID* pid, float kp, float ki, float kd);
void pidSetMeasured(struct PID* pid, float measured);
void pidSetTarget_Measure(struct PID* pid, float target, float measured);
void pidSetLowPassEnable(struct PID* pid);
void temperature_pid(void);

#endif /* PID_H_ */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/






























