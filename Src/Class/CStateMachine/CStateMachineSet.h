/*
 * CStateMachineSet.h
 *
 *  Created on: 2019年8月23日
 *      Author: wyz
 */

#ifndef CLASS_CSTATEMACHINE_CSTATEMACHINESET_H_
#define CLASS_CSTATEMACHINE_CSTATEMACHINESET_H_
#include "CMyQueueBase.h"
#include "CMyQueue_Freertos.h"
#include "CMachineEventBase.h"
#include <list>
#include "cmsis_os.h"

namespace wyz {
template<typename ModuleEvent>
class CStateMachineSet {
public:
	CStateMachineSet(uint8_t levelOfMachine = 1,bool usingOS = false)
    {
		m_levelOfMachine = levelOfMachine;
		m_usingOSFlag = usingOS;
		if (usingOS == true) {
			m_pEventQueue = new CMyQueueFreertos<CMachineEventBase*>(5);
		}
	};
	~CStateMachineSet(){delete m_pEventQueue;};
	void SetToQueue(ModuleEvent event,uint8_t levelOfMachine =1)
	{
		ModuleEvent *pEventData = new SomeEvent(event);
		if(m_usingOSFlag == true)
		{
			m_pEventQueue->m_QueueSendToBack(pEventData,portMAX_DELAY);
		}else{//不使用操作系统
		}

	}
private:
	CMyQueueBase<CMachineEventBase*>* m_pEventQueue;
	uint8_t m_levelOfMachine;
	bool m_usingOSFlag;
};


}  // namespace wyz
#endif /* CLASS_CSTATEMACHINE_CSTATEMACHINESET_H_ */
