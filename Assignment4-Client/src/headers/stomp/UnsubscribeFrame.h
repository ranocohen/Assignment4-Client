/*
 * UnsubscribeFrame.h
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#ifndef UNSUBSCRIBEFRAME_H_
#define UNSUBSCRIBEFRAME_H_

#include "StompFrame.h"

class UnsubscribeFrame: public StompFrame {
public:
	UnsubscribeFrame();
	void set_id(string id);
	virtual ~UnsubscribeFrame();
	virtual void apply(ConnectionHandler* cHandler);
};

#endif /* UNSUBSCRIBEFRAME_H_ */
