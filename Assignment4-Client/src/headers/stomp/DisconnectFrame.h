/*
 * DisconnectFrame.h
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#ifndef DISCONNECTFRAME_H_
#define DISCONNECTFRAME_H_

#include "StompFrame.h"

class DisconnectFrame: public StompFrame {
	public:
		DisconnectFrame();
		void set_id(string id);
		virtual ~DisconnectFrame();
	};

#endif /* DISCONNECTFRAME_H_ */
