	/*
 * ConnectFrame.cpp
 *
 *  Created on: Jan 6, 2014
 *      Author: idanakav
 */

#include "../headers/stomp/ConnectFrame.h"
#include <string>

using namespace std;

ConnectFrame::ConnectFrame() : StompFrame("CONNECT","") {


}

ConnectFrame::~ConnectFrame() {
	// TODO Auto-generated destructor stub
}

void ConnectFrame::set_user(string user) {
	addHeader("login",user);
}
void ConnectFrame::set_host(string host) {
	addHeader("host",host);
}
void ConnectFrame::set_accept_version(string version) {
	addHeader("accept-version",version);
}

void ConnectFrame::set_code(string code) {
	addHeader("passcode",code);
}
void ConnectFrame::apply(ConnectionHandler* cHandler) {
	cout << "Login successfully" << endl;

}
