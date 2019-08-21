/*
 * CAnalysisOfFrame.cpp
 *
 *  Created on: 2019年7月28日
 *      Author: wyz
 */

#include <CAnalysisOfFrame.h>

namespace wyz {

CAnalysisOfFrame::CAnalysisOfFrame(uint32_t SizeOfDataBuf,string HeadOfFrame,string TailOfFrame) {
	// TODO Auto-generated constructor stub
	this->m_HeadOfFrame = HeadOfFrame;
	this->m_TailOfFrame = TailOfFrame;
	this->m_DataString.reserve(SizeOfDataBuf*2);
	this->m_LastDataString.reserve(SizeOfDataBuf);
	this->m_SizeOfDataBuf = SizeOfDataBuf;
}

CAnalysisOfFrame::~CAnalysisOfFrame() {
	// TODO Auto-generated destructor stub
}

string CAnalysisOfFrame::ConcreteStrategy(string Str)
{
	string::size_type  Index;
	this->m_DataString = Str;
	if(this->m_LastDataString.empty() == false)
	{
		Index = this->m_LastDataString.find(this->m_HeadOfFrame);    //上次存下来的截取帧头内的
		if(Index != this->m_LastDataString.npos)
		{
			this->m_LastDataString = this->m_LastDataString.substr(Index);
			this->m_DataString.insert(0, this->m_LastDataString);//链接字符串
		}
	}
	Index = this->m_DataString.find(this->m_HeadOfFrame);
	if(Index != this->m_DataString.npos)  //找到帧头
	{
		this->m_DataString = this->m_DataString.substr(Index); //截取帧头后面的（包括帧头）
		Index = this->m_DataString.rfind(this->m_TailOfFrame); //准备截取
		if(Index == this->m_DataString.npos) //命令不完全
		{
			if(this->m_DataString.length() < this->m_SizeOfDataBuf)
			{
				this->m_LastDataString = this ->m_DataString; //存起来
				this->m_DataString = "";
				return this->m_DataString;
			}else
			{
				//超过一帧可能的长度则清空
				this->m_DataString.clear();
				this->m_LastDataString.clear();
				return this->m_DataString;
			}
		}else{ //完整命令
			this->m_LastDataString = this->m_DataString.substr(Index+this->m_TailOfFrame.length());//剩余的放入缓存区
			//完整命令
			return this->m_DataString.substr(0,Index+this->m_TailOfFrame.length());
		}
	}else
	{
		//找不到帧头
		this->m_DataString = "";
		return this->m_DataString;
	}

}

} /* namespace wyz */
