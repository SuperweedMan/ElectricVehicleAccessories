/*
 * CDevice.h
 *
 *  Created on: 2019年7月21日
 *      Author: wyz
 */

#ifndef CDEVICE_H_
#define CDEVICE_H_
#include  "CObserver.h"
#include "main.h"
namespace wyz {
using namespace std;

class CDevice {  //驱动程序基类
public:
	virtual uint8_t Open()=0;
	virtual uint8_t Close()=0;
	virtual void BlockRead(uint8_t *pDataBuf,uint32_t Size,uint32_t TimeOut=200)=0;
	virtual void Blockwrite(uint8_t *pDataBuf,uint32_t Size,uint32_t TimeOut=200)=0;
	virtual void NonBlockRead(uint8_t *,uint32_t Size,uint32_t TimeOut=200)=0;
	virtual void NonBlockWrite(uint8_t *pDataBuf,uint32_t Size,uint32_t TimeOut=200)=0;
};

} /* namespace wyz */

#endif /* CDEVICE_H_ */
