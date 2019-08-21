/*
 * CTimerMeter.h
 *
 *  Created on: 2019年8月2日
 *      Author: wyz
 */

#ifndef CLASS_CTIMERMETER_H_
#define CLASS_CTIMERMETER_H_
#include "main.h"

namespace wyz {

class CTimerMeter {
private:
	CTimerMeter();
	~CTimerMeter();
	TIM_HandleTypeDef  * m_Timer;
	double m_NumberOfMs = 0;
	bool m_FlagOfRun = false;
public:
	static CTimerMeter* GetTimerMeterInstance()
	{
		static CTimerMeter* m_pTmierMeter;
		if (m_pTmierMeter == NULL) {
			m_pTmierMeter = new CTimerMeter();
		}
		return m_pTmierMeter;
	}

	void StartCounter(TIM_HandleTypeDef * timer)
	{
		this->m_NumberOfMs = 0;
		__HAL_TIM_SET_COUNTER(timer,0);
		this->m_Timer = timer;
		HAL_TIM_Base_Start_IT(timer);
		this->m_FlagOfRun = true;
	}
	double StopCounter(TIM_HandleTypeDef * timer)
	{
		double counter;
		uint32_t i = __HAL_TIM_GET_COUNTER(timer);
		HAL_TIM_Base_Stop_IT(timer);
		counter = (double)i;
		this->m_Timer = NULL;
		this->m_FlagOfRun = false;
		return this->m_NumberOfMs + (counter/1000.0);
	}
	void HardInterruptOfTimer(TIM_HandleTypeDef * timer)
	{
		if(this->m_FlagOfRun == true)
		{
			if(this->m_Timer != NULL and this->m_Timer->Instance == timer->Instance)
				{
					this->m_NumberOfMs ++ ;
				}
		}
	}
};

} /* namespace wyz */

#endif /* CLASS_CTIMERMETER_H_ */
