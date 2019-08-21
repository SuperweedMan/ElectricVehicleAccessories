/*
 * CStateMachine.h
 *
 *  Created on: 2019年8月20日
 *      Author: wyz
 */

#ifndef CLASS_CSTATEMACHINE_CSTATEMACHINE_H_
#define CLASS_CSTATEMACHINE_CSTATEMACHINE_H_

namespace wyz {

class CStateMachine {
public:
	virtual ~CStateMachine() {};

	int GetCurrentState(){return this->m_CurrentState;}
protected:

private:
	int m_CurrentState;
	int m_NewState;
};

}  // namespace wyz
#endif /* CLASS_CSTATEMACHINE_CSTATEMACHINE_H_ */
