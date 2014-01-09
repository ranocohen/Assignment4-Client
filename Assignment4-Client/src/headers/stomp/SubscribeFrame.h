/*
 * SubscribeFrame.h
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#ifndef SUBSCRIBEFRAME_H_
#define SUBSCRIBEFRAME_H_

#include "StompFrame.h"

class SubscribeFrame: public StompFrame {
public:
	SubscribeFrame();
	void set_destination(string user);
	void set_id(string code);
	virtual ~SubscribeFrame();

};

#endif /* SUBSCRIBEFRAME_H_ */
