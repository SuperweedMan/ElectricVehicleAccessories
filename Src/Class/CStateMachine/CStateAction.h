/*
 * CStateAction.h
 *
 *  Created on: 2019年8月20日
 *      Author: wyz
 */

#ifndef CLASS_CSTATEMACHINE_CSTATEACTION_H_
#define CLASS_CSTATEMACHINE_CSTATEACTION_H_
#include "CStateMachine.h"

namespace wyz {

template<class SM,class ED,void (SM::*Action)(const ED*) >
class CStateAction :public CStateBase
{
public:
	CStateAction() {};
	virtual ~CStateAction() {};
	void InvokeStateAction(CStateMachine* sm, const CMachineEventBase* data)
	{
		SM* derivedSm = static_cast<SM*>(sm);    //父辈指针变成子辈
		const ED* derivedData = static_cast<const ED*>(data);
		(derivedSm->*Action)(derivedData);      //成功用子辈具体状态机调用子辈函数
	}
private:
};

}  // namespace wyz
#endif /* CLASS_CSTATEMACHINE_CSTATEACTION_H_ */
