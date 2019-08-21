/*
 * CDispatcherLocks_FreeRTOS.h
 *
 *  Created on: 2019年8月20日
 *      Author: wyz
 */

#ifndef CLASS_CMYOS_CFREERTOS_CDISPATCHERLOCKS_FREERTOS_H_
#define CLASS_CMYOS_CFREERTOS_CDISPATCHERLOCKS_FREERTOS_H_
#include "cmsis_os.h"
#include "CMyDispatcherLocks.h"

namespace wyz {

class CDispatcherLocks_FreeRTOS {
public:
	static void TaskSuspendAll(){vTaskSuspendAll();}
	static void TaskResumeAll()
	{
		if(!xTaskResumeAll())      /* 关闭调度锁，如果需要任务切换，此函数返回pdTRUE，否则返回pdFALSE */
	        {
	            taskYIELD ();
	        }
	}
private:
	CDispatcherLocks_FreeRTOS(){}; //静态类,不可实例
	~CDispatcherLocks_FreeRTOS(){};
};

}  // namespace wyz




#endif /* CLASS_CMYOS_CFREERTOS_CDISPATCHERLOCKS_FREERTOS_H_ */
