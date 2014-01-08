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

	std::stringstream ss;
	ss<<"CONNECT"<<"\n";
	ss<<"login:idan\n";
	ss<<'\n'<<'\0';
/*
		ss<<'login'<<':'<<'idan'<<'\n';

	ss<<'\n'<<'\n'<<'\0';*/
	return ss.str();

}
ConnectFrame::~ConnectFrame() {
	// TODO Auto-generated destructor stub
}

