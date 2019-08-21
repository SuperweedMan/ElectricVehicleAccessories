/*
 * CGPSModule.h
 *
 *  Created on: 2019年7月25日
 *      Author: wyz
 */

#ifndef CLASS_CGPSMODULE_H_
#define CLASS_CGPSMODULE_H_


#include "totalInclude.h"
#include "CStrategy.h"
namespace wyz {

class CGPSModule: public CObserver { //作为观察者
public:
	CGPSModule(CStrategy *Strategy);
	~CGPSModule();
	void Update(CSubject *pSubject);
	uint32_t AnalysisLoop();
	typedef struct gpsData
	{
		uint32_t DateOfUTC;
		uint32_t TimeOfUTC;
		uint8_t GpsMode;
		double Dimension;
		uint8_t DimensionalDirection;
		double Longitude;
		uint8_t LongitudinalDirection;
		float GroundSpeed;
		double CourseOfGround;

	} GpsData;
	GpsData GetGpsData();
private:
	string m_DataString;
	string m_LastDataString;
	uint32_t m_SizeOfDataBuf;
	list<string> m_DataBufList;
	CStrategy* m_Strategy;
	GpsData m_GpsData;
};

} /* namespace wyz */

#endif /* CLASS_CGPSMODULE_H_ */
