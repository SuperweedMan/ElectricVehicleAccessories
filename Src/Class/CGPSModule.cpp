/*
 * CGPSModule.cpp
 *
 *  Created on: 2019年7月25日
 *      Author: wyz
 */

#include <CGPSModule.h>
#include <CUart.h>
#include "CTimerMeter.h"
#include <stdexcept>
//#include <exception>

extern TIM_HandleTypeDef htim4;

namespace wyz {
CTimerMeter * pTimerMeter = CTimerMeter::GetTimerMeterInstance();

CGPSModule::CGPSModule(CStrategy *Strategy)
{
	this->m_Strategy = Strategy;
}

CGPSModule::~CGPSModule()
{

}

void CGPSModule::Update(CSubject * pSubject)  //有目标数据更新
{
	uint32_t size = static_cast<CUart*>(pSubject)->GetSizeOfRxBuf();
	uint8_t *pData= static_cast<CUart*>(pSubject)->GetPointOfRxBuf();
	char m_pDataBuf[size];
	string DataString;
	memcpy(m_pDataBuf,pData,size); //将uint8 *转 char *
	this->m_DataBufList.push_front(DataString.assign(m_pDataBuf, size));  //先进后出fifo模式
}

uint32_t CGPSModule::AnalysisLoop()
{
	string StrForReturn;
	if(this->m_DataBufList.empty() == false)
	{
		if(this->m_DataBufList.size()>10)
		{
			//过多，处理不及了
			return 1;
//			return "out of the max list size";
		}
		for(uint8_t i =0;i<this->m_DataBufList.size();i++)
		{
			//截取帧
			StrForReturn  = this->m_Strategy->ConcreteStrategy(this->m_DataBufList.back());
			this->m_DataBufList.pop_back();
			if(StrForReturn.length() == 0 and this->m_DataBufList.empty())
			{
//				return "";//没有可处理的
				return 0;
			}
			if(StrForReturn.length() != 0)
			{
				//开始处理
				uint8_t checkSum;
				uint8_t checkSumFormStr;
				checkSum = StrForReturn.c_str()[1];//不计算$
				uint8_t index = StrForReturn.find_last_of('*'); //获取校验码
				for(uint8_t j =1;j<index-1;j++) //计算校验码
					{
						checkSum = checkSum xor StrForReturn.c_str()[j+1];
					}
				checkSumFormStr = stoi(StrForReturn.substr(index+1),nullptr,16);
				if(checkSum == checkSumFormStr )
				{//校验通过
					return 0;
				}else //校验失败
				{
					if(this->m_DataBufList.empty())
					{
						return 0;
					}
				}
			}
		}
	}
//	return "the databuf is empty!";
	return 0;
}

CGPSModule::GpsData CGPSModule::GetGpsData()
{
	return this->m_GpsData;
}

} /* namespace wyz */
