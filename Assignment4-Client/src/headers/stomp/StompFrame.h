/*
 * StompFrame.h
 */

#ifndef STOMPFRAME_H_
#define STOMPFRAME_H_
#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include "../connectionHandler.h"
using namespace std;

class StompFrame {
public:
	StompFrame();
	StompFrame(string packetstring);
	StompFrame(string command,string body);
	virtual ~StompFrame();

	string getHeaderValue(string);
	string getCommand();
	string getBody();
	void setBody(string message);
	void addHeader(string name,string value);
	string toString();
	virtual void apply(ConnectionHandler* cHandler)=0;

private:
	//header will be stored in map (name,value)
	std::map<std::string ,std::string> headers;
	string command;
	string body;
	string packet_string;
};

#endif /* STOMPFRAME_H_ */
