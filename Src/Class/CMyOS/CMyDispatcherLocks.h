/*
 * CMyDispatcherLocks.h
 *
 *  Created on: 2019年8月20日
 *      Author: wyz
 */

#ifndef CLASS_CMYOS_CMYDISPATCHERLOCKS_H_
#define CLASS_CMYOS_CMYDISPATCHERLOCKS_H_
namespace wyz {

class CMyDispatcherLocks {
public:
	virtual ~CMyDispatcherLocks(){};
	virtual void TaskSuspendAll() = 0;
	virtual void TaskResumeAll() = 0;
};



}  // namespace wyz
#endif /* CLASS_CMYOS_CMYDISPATCHERLOCKS_H_ */
