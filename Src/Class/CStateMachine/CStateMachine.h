/*
 * CStateMachine.h
 *
 *  Created on: 2019年8月20日
 *      Author: wyz
 */

#ifndef CLASS_CSTATEMACHINE_CSTATEMACHINE_H_
#define CLASS_CSTATEMACHINE_CSTATEMACHINE_H_
#include <map>
#include <vector>
#include "CMachineEventBase.h"
#include "CStateAction.h"
#include "CStateBase.h"

namespace wyz {

class CStateMachine {
public:
	virtual ~CStateMachine() {};
	void SetEvent(CMachineEventBase* pEvent);
	int GetCurrentState(){return this->m_CurrentState;}
	void AddItemOfStateMap(int state,CStateBase * pStateAction);
	void AddItemOfTransitions(int eventType,int state,std::vector<int> newStats);
	void AddItemOfInternalTransitions(int eventType,int state,std::vector<int> newStats);
protected:
	void ExternalEvent(CMachineEventBase * pData,int EventType);
	void InternalEvent(CMachineEventBase * pData);
private:
	std::map<int,CStateBase*> m_StateMap; //map<state,CStateBase*>
	std::map<int64_t ,std::vector<int> > m_IntranalTransitions;
	std::map<int64_t ,std::vector<int> > m_Transitions;//map<CEventType and currentState,vector<newState>>
	std::map<int64_t,std::vector<int>>::iterator m_TransitionsItem;
	int m_CurrentState = 0;
	int m_NewState = 0;
	int64_t MergeIntToLong(int value_1,int value_2);
};
void CStateMachine::AddItemOfInternalTransitions(int eventType,int state,std::vector<int> newStats)
{
	m_IntranalTransitions[MergeIntToLong(eventType, state)] = newStats;
}

void CStateMachine::AddItemOfStateMap(int state,CStateBase * pStateAction)
{
	m_StateMap[state] = pStateAction;
}

void CStateMachine::AddItemOfTransitions(int eventType,int state,std::vector<int> newStats)
{
	m_Transitions[MergeIntToLong(eventType, state)] = newStats;
}

void CStateMachine::SetEvent(CMachineEventBase* pEvent)
{
	ExternalEvent(pEvent, pEvent->m_ExternalEventType);
}

void CStateMachine::InternalEvent(CMachineEventBase *pData)
{
	int64_t merge = MergeIntToLong(pData->m_InternalEventType, m_CurrentState);
	if (m_IntranalTransitions.count(merge)!=0) {
		uint32_t times = m_IntranalTransitions[merge].size();
		for (uint32_t i = 0; i < times ; ++i) {
			m_NewState = m_IntranalTransitions[merge].at(i);
			if(m_StateMap.count(m_NewState) != 0)
			{   //存在状态函数
				CStateBase *pState = m_StateMap[m_NewState];
				pState->InvokeStateAction(this, pData);
				m_CurrentState = m_NewState;
			}
		}
	}
	if(m_IntranalTransitions.count(MergeIntToLong(pData->m_InternalEventType, m_CurrentState))!=0)
	{InternalEvent(pData);}//迭代，直到没有状态转移
}

void CStateMachine::ExternalEvent(CMachineEventBase * pData,int EventType)
{
	m_TransitionsItem = m_Transitions.find(MergeIntToLong(EventType, m_CurrentState));
	if(m_TransitionsItem != m_Transitions.end())
	{   //存在状态转移
		//若一个事件发生多次状态转移,用动态数组存多次转移的状态
		for (uint32_t i = 0;  i < m_TransitionsItem->second.size(); ++ i) {
			m_NewState = m_TransitionsItem->second.at(i);
			if(m_StateMap.count(m_NewState) != 0)
			{   //存在状态函数
				CStateBase *pState = m_StateMap[m_NewState];
				pState->InvokeStateAction(this, pData);
				m_CurrentState = m_NewState;
				InternalEvent(pData);
			}
		}
	}
}


int64_t CStateMachine::MergeIntToLong(int value_1,int value_2)
{
	union mergeUnion
	{
		int64_t INT64_t;
		struct LowHigh{
			int lowInt;
			int highInt;
		}lowhigh;
	} mergeUnion;
	mergeUnion.lowhigh.lowInt = value_1;
	mergeUnion.lowhigh.highInt = value_2;
	return mergeUnion.INT64_t;
}

}  // namespace wyz
#endif /* CLASS_CSTATEMACHINE_CSTATEMACHINE_H_ */
