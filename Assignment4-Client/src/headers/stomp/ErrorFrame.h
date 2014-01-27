/*
 * SendFrame.hid
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#ifndef ERRORFRAME_H_
#define ERRORFRAME_H_

#include "StompFrame.h"

class ErrorFrame: public StompFrame {
public:
	ErrorFrame();
	string readableString();
	virtual ~ErrorFrame();
	virtual void apply(ConnectionHandler* cHandler);
};

#endif /* ERRORFRAME_H_ */
