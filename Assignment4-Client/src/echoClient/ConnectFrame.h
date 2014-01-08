/*
 * ConnectFrame.h
 *
 *  Created on: Jan 6, 2014
 *      Author: idanakav
 */

#ifndef CONNECTFRAME_H_
#define CONNECTFRAME_H_
#include "StompFrame.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class ConnectFrame : StompFrame {
public:
	ConnectFrame();
	string toString();
	virtual ~ConnectFrame();
};

#endif /* CONNECTFRAME_H_ */
