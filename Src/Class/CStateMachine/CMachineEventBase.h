/*
 * CMachineEventBase.h
 *
 *  Created on: 2019年8月19日
 *      Author: wyz
 */

#ifndef CLASS_CSTATEMACHINE_CMACHINEEVENTBASE_H_
#define CLASS_CSTATEMACHINE_CMACHINEEVENTBASE_H_

class CMachineEventBase {
public:
	virtual ~CMachineEventBase(){};
	int m_InternalEventType;
	int m_ExternalEventType;
};



#endif /* CLASS_CSTATEMACHINE_CMACHINEEVENTBASE_H_ */
