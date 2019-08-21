/*
 * CMyQueueBase.h
 *
 *  Created on: 2019年8月18日
 *      Author: wyz
 */

#ifndef CLASS_CMYOS_CMYQUEUEBASE_H_
#define CLASS_CMYOS_CMYQUEUEBASE_H_

namespace wyz {

template <typename CQueueData>
class CMyQueueBase {
public:
	CMyQueueBase() {};
	virtual ~CMyQueueBase() {};
	long virtual m_QueueSendToBack( CQueueData data, unsigned int tickToWait,bool FromISR = false) = 0;
	long virtual m_QueueSendToFront( CQueueData data, unsigned int tickToWait,bool FromISR = false) = 0;
	CQueueData virtual m_QueueReceive(bool& flagOfSuccess, unsigned int tickToWait,bool FromISR = false) = 0;
	CQueueData virtual m_QueuePeek(bool& flagOfSuccess,unsigned int tickToWait,bool FromISR = false) = 0;
	unsigned long virtual m_QueueSpaceAvailable() = 0;
	unsigned long virtual m_QueueMessagesWaiting(bool FromISR = false) = 0;

private:
//	unsigned int m_QueueLength; //队列深度
//	unsigned int m_ItemSize; //队列单元长度，字节为单位
};


}  // namespace wyz
#endif /* CLASS_CMYOS_CMYQUEUEBASE_H_ */
