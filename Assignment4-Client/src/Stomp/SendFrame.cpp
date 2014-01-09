/*
 * SendFrame.cpp
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#include "../headers/stomp/SendFrame.h"

SendFrame::SendFrame() {
	// TODO Auto-generated constructor stub

}

SendFrame::~SendFrame() {
	// TODO Auto-generated destructor stub
}

void SendFrame::set_body(string message) {
	setBody(message);
}

void SendFrame::set_destination(string dest) {
	addHeader("destination",dest);
}

