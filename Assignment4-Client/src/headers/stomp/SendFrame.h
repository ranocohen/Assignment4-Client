/*
 * SendFrame.h
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#ifndef SENDFRAME_H_
#define SENDFRAME_H_

#include "StompFrame.h"

class SendFrame: public StompFrame {
public:
	SendFrame();
	void set_body(string id);
	void set_destination(string id);
	virtual ~SendFrame();
};

#endif /* SENDFRAME_H_ */