/*
 * CKeyboard.h
 *
 *  Created on: Aug 24, 2019
 *      Author: wyz
 */

#ifndef CLASS_CKEYBOARD_CKEYBOARD_H_
#define CLASS_CKEYBOARD_CKEYBOARD_H_
#include "main.h"
#include "CMachineEventBase.h"
#include "CStateBase.h"
#include "CStateMachine.h"
#include "CStateAction.h"
namespace wyz
{
struct Keydata{
		int type;
		int value;
	};
class CKeyboardEvent :public CMachineEventBase{
public:
	virtual ~CKeyboardEvent(){};
};
class CKeyboard:public CStateMachine
{
public:
	CKeyboard();
	~CKeyboard();
	struct Keydata GetKey();
	enum CKeyboardExternalEventType{
		DoNothing,
		GetKey,
	};
private:
	enum CKeyboardInternalEventType{
		DoNothing,Press,NoPress,ClickEvent,LongPressEvent,
	};
	enum CKeyboardStats{
		BEGIN,
		CONFIRM,
		READ,
		END
	} m_KeyboardStats;
	enum CKeyType{
		NoKey,
		Click,
		DoubleClick,
		LongPress
	} m_KeyType;
	enum CKeyValue{
		Zero,One,Two,Three,Four,Five,Six,Seven,Eight,Nine,Star,End,A,B,C,D,Nothing
	} m_KeyValue;
	struct Keydata m_Keydata;
	//状态函数
	void ST_Begin(CKeyboardEvent*);
	CStateAction<CKeyboard,CKeyboardEvent,&CKeyboard::ST_Begin> STA_begin;
	void ST_Confirm(CKeyboardEvent*);
	CStateAction<CKeyboard,CKeyboardEvent,&CKeyboard::ST_Confirm> STA_confirm;
	void ST_Read(CKeyboardEvent*);
	CStateAction<CKeyboard,CKeyboardEvent,&CKeyboard::ST_Read> STA_read;
	void ST_End(CKeyboardEvent*);
	CStateAction<CKeyboard,CKeyboardEvent,&CKeyboard::ST_End> STA_end;
};

} /* namespace wyz */

#endif /* CLASS_CKEYBOARD_CKEYBOARD_H_ */
