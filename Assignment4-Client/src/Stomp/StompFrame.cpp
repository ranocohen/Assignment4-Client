/*
 * ConnectFrame.cpp
 *
 *  Created on: Jan 6, 2014
 *      Author: idanakav
 */

#include "../headers/stomp/StompFrame.h"

StompFrame::StompFrame() {

}
StompFrame::StompFrame(string command, string body) {
	this->command = command;
	this->body = body;
}

StompFrame::~StompFrame() {
// TODO Auto-generated destructor stub
}
void StompFrame::setBody(string body) {
	this->body = body;
}

string StompFrame::getBody() {
	return this->body;
}

void StompFrame::addHeader(string name, string value) {
	headers.insert(std::make_pair(name, value));
}

string StompFrame::toString() {
	std::stringstream ss;
	ss << command << '\n';
	for (std::map<std::string, std::string>::iterator it = headers.begin();
			it != headers.end(); ++it) {
		ss << it->first << ':' << it->second << '\n';
	}
	ss << '\n' << body << '\0';
	return ss.str();

}
string StompFrame::readableString() {
	std::stringstream ss;
	ss << command << " : " << body;
	return ss.str();
}

string StompFrame::getHeaderValue(string header) {



	return headers.find(header)->second;
}

