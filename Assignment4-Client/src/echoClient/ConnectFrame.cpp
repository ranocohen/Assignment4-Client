/*
 * ConnectFrame.cpp
 *
 *  Created on: Jan 6, 2014
 *      Author: idanakav
 */

#include "ConnectFrame.h"

ConnectFrame::ConnectFrame() {
	// TODO Auto-generated constructor stub

}
string ConnectFrame::toString() {
	string s = "@CONNECT \n"
				"accept-version:1.2 \n"
				"host:127.0.0.1 \n"
				"login:idan \n"
				"passcode:1234 \n";

	s += '\0';

	return s;


}
ConnectFrame::~ConnectFrame() {
	// TODO Auto-generated destructor stub
}

