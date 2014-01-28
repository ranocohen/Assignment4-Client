/*
 * MessageFrame.cpp
 *
 *  Created on: Jan 28, 2014
 *      Author: ran
 */

#include "../headers/stomp/MessageFrame.h"

MessageFrame::MessageFrame() : StompFrame("MESSAGE","") {

}

MessageFrame::~MessageFrame() {
}


void MessageFrame::set_message(string msg) {
	setBody(msg);
}

void MessageFrame::apply(ConnectionHandler* cHandler) {

}
