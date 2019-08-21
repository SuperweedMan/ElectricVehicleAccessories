/*
 * CDeviceDecorator.h
 *
 *  Created on: 2019年7月25日
 * *  作为驱动CDevice的装饰基类
 *      Author: wyz
 */

#ifndef CLASS_CDEVICEDECORATOR_H_
#define CLASS_CDEVICEDECORATOR_H_

#include <CDevice.h>

namespace wyz {

class CDeviceDecorator: public CDevice {
protected:
	CDevice *m_pDevice; //关键指针,回溯用
};

} /* namespace wyz */

#endif /* CLASS_CDEVICEDECORATOR_H_ */
