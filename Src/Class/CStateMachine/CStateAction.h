/*
 * CStateAction.h
 *
 *  Created on: 2019年8月20日
 *      Author: wyz
 */

#ifndef CLASS_CSTATEMACHINE_CSTATEACTION_H_
#define CLASS_CSTATEMACHINE_CSTATEACTION_H_
//#include "CStateMachine.h"
#include "CStateBase.h"

namespace wyz {
class CStateMachine;
template < typename SM,typename ED,void (SM::*Action)(ED*) >
class CStateAction : public CStateBase
{
public:
	CStateAction() {};
	virtual ~CStateAction() {};
	void InvokeStateAction(CStateMachine * sm, CMachineEventBase * data)
	{
		SM* derivedSm = static_cast<SM*>(sm);    //父辈指针变成子辈
		ED* derivedData = static_cast<ED*>(data);
		(derivedSm->*Action)(derivedData);      //成功用子辈具体状态机调用子辈函数
	}
private:

};

}  // namespace wyz
#endif /* CLASS_CSTATEMACHINE_CSTATEACTION_H_ */
