/*
 * StompFrame.h
 *
 *  Created on: Jan 6, 2014
 *      Author: idanakav
 */

#ifndef STOMPFRAME_H_
#define STOMPFRAME_H_
#include <string>

using namespace std;

class StompFrame {
public:
	StompFrame();
	virtual string toString() =0;
	virtual ~StompFrame();
};

#endif /* STOMPFRAME_H_ */
