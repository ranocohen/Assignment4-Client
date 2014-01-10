	/*
 * ConnectFrame.cpp
 *
 *  Created on: Jan 6, 2014
 *      Author: idanakav
 */

#include "../headers/stomp/ConnectFrame.h"
#include <string>
#include <boost/thread.hpp>
#include "../headers/UserNetworkingHandle.h"
using namespace std;

ConnectFrame::ConnectFrame() : StompFrame("CONNECT","") {


}

ConnectFrame::~ConnectFrame() {
	// TODO Auto-generated destructor stub
}

void ConnectFrame::set_user(string user) {
	addHeader("login",user);
}

void ConnectFrame::set_code(string code) {
	addHeader("passcode",code);
}
void ConnectFrame::apply(ConnectionHandler* cHandler) {

	    if (!cHandler->connect()) {
	        std::cerr << "Could not connect to server. Check your Internet connection, IP and port." << std::endl;
	    } else
	    {
	    	UserNetworkingHandle unh(2, cHandler);
	    	boost::thread thUNH(&UserNetworkingHandle::run, &unh);
	    	thUNH.join();
	    }
}
