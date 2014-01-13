/*
 * SendFrame.hid
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
	void set_message(string msg);
	void set_destination(string id);
	virtual ~SendFrame();
	virtual void apply(ConnectionHandler* cHandler);
};

#endif /* SENDFRAME_H_ */
