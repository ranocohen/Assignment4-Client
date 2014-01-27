/*
 * SendFrame.cpp
 *
 *  Created on: Jan 9, 2014
 *      Author: ran
 */

#include "../headers/stomp/ErrorFrame.h"

ErrorFrame::ErrorFrame() : StompFrame("ERROR",""){
	// TODO Auto-generated constructor stub

}

ErrorFrame::~ErrorFrame() {
	// TODO Auto-generated destructor stub
}



void ErrorFrame::apply(ConnectionHandler* cHandler) {




}
