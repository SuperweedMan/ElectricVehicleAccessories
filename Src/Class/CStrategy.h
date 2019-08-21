/*
 * CStrategy.h
 *
 *  Created on: 2019年7月28日
 *      Author: wyz
 */

#ifndef CLASS_CSTRATEGY_H_
#define CLASS_CSTRATEGY_H_
#include <string>
#include <cstring>

namespace wyz {
using namespace std;
class CStrategy {
public:
	virtual string ConcreteStrategy(string Str) = 0;
};

} /* namespace wyz */

#endif /* CLASS_CSTRATEGY_H_ */
