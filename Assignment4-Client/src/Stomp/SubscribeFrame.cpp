/*
 * SubscribeFrame.cpp
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#include "../headers/stomp/SubscribeFrame.h"

SubscribeFrame::SubscribeFrame() : StompFrame("SUBSCRIBE",""){
	// TODO Auto-generated constructor stub

}

SubscribeFrame::~SubscribeFrame() {
	// TODO Auto-generated destructor stub
}

void SubscribeFrame::set_destination(string dest) {
	addHeader("destination",dest);
}

void  SubscribeFrame::set_id(string id) {
	addHeader("id",id);
}
