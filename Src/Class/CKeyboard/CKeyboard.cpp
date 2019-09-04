/*
 * CKeyboard.cpp
 *
 *  Created on: Aug 24, 2019
 *      Author: wyz
 */

#include "CKeyboard.h"

namespace wyz
{

CKeyboard::CKeyboard()
{
	//绑定状态函数到状态
	this->AddItemOfStateMap(CKeyboardStats::BEGIN,&STA_begin);
	this->AddItemOfStateMap(CKeyboardStats::CONFIRM, &STA_confirm);
	this->AddItemOfStateMap(CKeyboardStats::END, &STA_end);
	this->AddItemOfStateMap(CKeyboardStats::READ, &STA_read);
	//填充外部事件状态转移表
	this->AddItemOfTransitions(CKeyboardExternalEventType::GetKey, CKeyboardStats::BEGIN, CKeyboardStats::CONFIRM);
	//填充内部事件状态转移表
	this->AddItemOfInternalTransitions(CKeyboardInternalEventType::Press, CKeyboardStats::BEGIN, CKeyboardStats::CONFIRM);
	this->AddItemOfInternalTransitions(CKeyboardInternalEventType::NoPress, CKeyboardStats::BEGIN, CKeyboardStats::END);
	this->AddItemOfInternalTransitions(CKeyboardInternalEventType::Press, CKeyboardStats::CONFIRM, CKeyboardStats::READ);
	this->AddItemOfInternalTransitions(CKeyboardInternalEventType::NoPress, CKeyboardStats::CONFIRM, CKeyboardStats::END);
	this->AddItemOfInternalTransitions(CKeyboardInternalEventType::ClickEvent, CKeyboardStats::READ, CKeyboardStats::END);
	this->AddItemOfInternalTransitions(CKeyboardInternalEventType::LongPressEvent, CKeyboardStats::READ, CKeyboardStats::END);

}

CKeyboard::~CKeyboard()
{
	// TODO Auto-generated destructor stub
}

struct Keydata CKeyboard::GetKey()
{
	CKeyboardEvent event;
	event.m_ExternalEventType = CKeyboardExternalEventType::GetKey;
	ExternalEvent(&event, event.m_ExternalEventType);
}

} /* namespace wyz */
