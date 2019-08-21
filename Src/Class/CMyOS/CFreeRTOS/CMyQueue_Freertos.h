/*
 * CMyQueueFreertos.h
 *
 *  Created on: 2019年8月18日
 *      Author: wyz
 */

#ifndef CLASS_CMYOS_CMYQUEUE_FREERTOS_H_
#define CLASS_CMYOS_CMYQUEUE_FREERTOS_H_
#include "CMyQueueBase.h"
#include "cmsis_os.h"

namespace wyz {
template <typename CQueueData>
class CMyQueueFreertos :public CMyQueueBase<CQueueData>
{
public:
	CMyQueueFreertos(unsigned portBASE_TYPE queueLength);
	virtual ~CMyQueueFreertos();

	portBASE_TYPE m_QueueSendToBack( CQueueData data, unsigned int tickToWait,bool FromISR = false);
	portBASE_TYPE m_QueueSendToFront( CQueueData data, unsigned int tickToWait,bool FromISR = false);
	CQueueData m_QueueReceive(bool& flagOfSuccess,unsigned int tickToWait,bool FromISR = false);
	CQueueData m_QueuePeek(bool& flagOfSuccess,unsigned int tickToWait,bool FromISR = false);
	UBaseType_t virtual m_QueueSpaceAvailable();
	UBaseType_t m_QueueMessagesWaiting(bool FromISR = false);
private:
	xQueueHandle m_QueueHandle;
};
//读取队列可用数据量
template <typename CQueueData>
UBaseType_t CMyQueueFreertos<CQueueData>::m_QueueSpaceAvailable()
{
	return uxQueueSpacesAvailable(this->m_QueueHandle);
}
//构造函数
template <typename CQueueData>
CMyQueueFreertos<CQueueData>::CMyQueueFreertos(unsigned portBASE_TYPE queueLength)
{
	m_QueueHandle = xQueueCreate(queueLength,sizeof(CQueueData));
}

//发送数据到后面
template <typename CQueueData>
portBASE_TYPE CMyQueueFreertos<CQueueData>::m_QueueSendToBack( CQueueData data, unsigned int tickToWait,bool FromISR)
{
	if(FromISR == true)
	{
		return xQueueOverwriteFromISR(this->m_QueueHandle,&data,pdFALSE);
	}else{
		return xQueueSendToBack(this->m_QueueHandle,&data,tickToWait);
	}
}


//数据发送到数据前面
template <typename CQueueData>
portBASE_TYPE CMyQueueFreertos<CQueueData>::m_QueueSendToFront( CQueueData data, unsigned int tickToWait,bool FromISR )
{
	if(FromISR == true)
	{
		return xQueueSendToFrontFromISR(this->m_QueueHandle,&data,pdFALSE);
	}else{
		return xQueueSendToFront(this->m_QueueHandle,&data,tickToWait);
	}

}
//从队列里面接受数据
template <typename CQueueData>
CQueueData CMyQueueFreertos<CQueueData>::m_QueueReceive(bool& flagOfSuccess, unsigned int tickToWait,bool FromISR)
{
	CQueueData data;
	if(FromISR == true)
	{
		if (xQueueReceiveFromISR(this->m_QueueHandle,&data,pdFALSE) == pdTRUE)
		{
			flagOfSuccess = true;
		}
		else{
			flagOfSuccess = false;
		}
	}else{
		if( xQueueReceive(this->m_QueueHandle,&data,tickToWait) == pdTRUE)
		{
			flagOfSuccess = true;
		}else
		{
			flagOfSuccess = false;
		}
	}
	return data;
}
//获取数据而不删除
template <typename CQueueData>
CQueueData CMyQueueFreertos<CQueueData>::m_QueuePeek(bool& flagOfSuccess,unsigned int tickToWait,bool FromISR)
{
	CQueueData data;
	if(FromISR == true)
	{
		if( xQueuePeekFromISR(this->m_QueueHandle,&data) == pdTRUE)
		{
			flagOfSuccess = true;
		}else{
			flagOfSuccess = false;
		}
	}else
	{
		if( xQueuePeek(this->m_QueueHandle,&data,tickToWait))
		{
			flagOfSuccess = true;
		}else{
			flagOfSuccess = false;
		}
	}
	return data;
}

//获取队列数据总数
template <typename CQueueData>
UBaseType_t CMyQueueFreertos<CQueueData>::m_QueueMessagesWaiting(bool FromISR)
{
	if(FromISR == true)
	{
		return uxQueueMessagesWaitingFromISR(this->m_QueueHandle);
	}else{
		return uxQueueMessagesWaiting(this->m_QueueHandle);
	}
}
//析构函数
template <typename CQueueData>
CMyQueueFreertos<CQueueData>::~CMyQueueFreertos()
{
	vQueueDelete(this->m_QueueHandle);
}


} /* namespace wyz */
#endif /* CLASS_CMYOS_CMYQUEUE_FREERTOS_H_ */
