/*
 * SendFrame.cpp
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#include "../headers/stomp/SendFrame.h"

SendFrame::SendFrame() : StompFrame("SEND",""){
	// TODO Auto-generated constructor stub

}

SendFrame::~SendFrame() {
	// TODO Auto-generated destructor stub
}


void SendFrame::set_destination(string dest) {
	addHeader("destination",dest);
}

void SendFrame::apply(ConnectionHandler* cHandler) {}
