/*
 * CAnalysisOfFrame.h
 *
 *  Created on: 2019年7月28日
 *      Author: wyz
 */

#ifndef CLASS_CANALYSISOFFRAME_H_
#define CLASS_CANALYSISOFFRAME_H_

#include <CStrategy.h>

namespace wyz {
using namespace std;

class CAnalysisOfFrame: public CStrategy {
private:
	string m_DataString;
	string m_LastDataString;
	string m_HeadOfFrame;
	string m_TailOfFrame;
	uint32_t m_SizeOfDataBuf;

public:
	CAnalysisOfFrame(uint32_t SizeOfDataBuf,string HeadOfFrame,string TailOfFrame);
	~CAnalysisOfFrame();
	string ConcreteStrategy(string Str);
};

} /* namespace wyz */

#endif /* CLASS_CANALYSISOFFRAME_H_ */
