/*
 * ConnectFrame.cpp
 *
 *  Created on: Jan 6, 2014
 *      Author: idanakav
 */

#include "StompFrame.h"

StompFrame::StompFrame() {


}

StompFrame::~StompFrame() {
	// TODO Auto-generated destructor stub
}
void StompFrame::addHeader(string name,string value) {
	//headers.insert(name,value);
}

string StompFrame::toString() {
	std::stringstream ss;
	ss<<command<<'\n';
	for(std::map<std::string,std::string>::iterator it=headers.begin();it!=headers.end();++it)
	{
		ss<<it->first<<':'<<it->second<<'\n';
	}
	ss<<'\n'<<'\n'<<body<<'\0';
	return ss.str();
}

