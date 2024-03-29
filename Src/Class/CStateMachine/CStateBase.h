/*
 * CStateBase.h
 *
 *  Created on: 2019年8月20日
 *      Author: wyz
 */

#ifndef CLASS_CSTATEMACHINE_CSTATEBASE_H_
#define CLASS_CSTATEMACHINE_CSTATEBASE_H_
#include "CMachineEventBase.h"
#include "CStateMachine.h"

namespace wyz {

class CStateBase {
public:
	virtual ~CStateBase(){};
	virtual void InvokeStateAction(CStateMachine* sm, const CMachineEventBase* data) = 0;
private:
};

}  // namespace wyz
#endif /* CLASS_CSTATEMACHINE_CSTATEBASE_H_ */
