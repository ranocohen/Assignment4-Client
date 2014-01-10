/*
 * DisconnectFrame.cpp
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#include "../headers/stomp/DisconnectFrame.h"

DisconnectFrame::DisconnectFrame() : StompFrame("DISCONNECT",""){
	// TODO Auto-generated constructor stub

}

DisconnectFrame::~DisconnectFrame() {
	// TODO Auto-generated destructor stub
}

void  DisconnectFrame::set_id(string id) {
	addHeader("id",id);
}
void DisconnectFrame::apply(ConnectionHandler* cHandler) {}
