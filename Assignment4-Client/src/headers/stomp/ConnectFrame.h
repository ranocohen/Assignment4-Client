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

class ConnectFrame: public StompFrame {
public:
	ConnectFrame();
	void set_user(string user);
	void set_code(string code);
	virtual ~ConnectFrame();


};

#endif /* CONNECTFRAME_H_ */
