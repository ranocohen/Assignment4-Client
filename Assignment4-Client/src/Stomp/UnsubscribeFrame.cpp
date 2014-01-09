/*
 * UnsubscribeFrame.cpp
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#include "../headers/stomp/UnsubscribeFrame.h"

UnsubscribeFrame::UnsubscribeFrame(): StompFrame("UNSUBSCRIBE","") {
	// TODO Auto-generated constructor stub

}

UnsubscribeFrame::~UnsubscribeFrame() {
	// TODO Auto-generated destructor stub
}

void UnsubscribeFrame::set_id(string id) {
	addHeader("id", id);


}

void UnsubscribeFrame::apply(ConnectionHandler* cHandler) {}
