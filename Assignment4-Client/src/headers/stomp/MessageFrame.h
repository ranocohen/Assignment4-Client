/*
 * MessageFrame.h
 *
 *  Created on: Jan 28, 2014
 *      Author: ran
 */

#ifndef MESSAGEFRAME_H_
#define MESSAGEFRAME_H_
#include <string>
#include "../connectionHandler.h"
#include "StompFrame.h"

using namespace std;

class MessageFrame : public StompFrame {
public:
	MessageFrame();
	virtual ~MessageFrame();

	void set_body(string id);
	void set_message(string msg);
	virtual void apply(ConnectionHandler* cHandler);
};

#endif /* MESSAGEFRAME_H_ */
