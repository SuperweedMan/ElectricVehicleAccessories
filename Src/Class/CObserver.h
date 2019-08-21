/*
 * CObserver.h
 *
 *  Created on: Jul 24, 2019
 *      Author: wyz
 */

#ifndef CLASS_COBSERVER_H_
#define CLASS_COBSERVER_H_
#include "CSubject.h"

namespace wyz {

class CObserver {
public:
	virtual  void Update(CSubject* pSubject)=0;
};

} /* namespace wyz */

#endif /* CLASS_COBSERVER_H_ */
