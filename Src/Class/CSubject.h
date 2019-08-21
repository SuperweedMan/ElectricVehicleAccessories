/*
 * CSubject.h
 *
 *  Created on: Jul 24, 2019
 *      Author: wyz
 */

#ifndef CLASS_CSUBJECT_H_
#define CLASS_CSUBJECT_H_

namespace wyz {
class CObserver;

class CSubject {
public:
	virtual void Attach(CObserver* pObserver)=0;
	virtual void Detach(CObserver* pObserver)=0;
	virtual void Notify() = 0;
};

} /* namespace wyz */

#endif /* CLASS_CSUBJECT_H_ */
