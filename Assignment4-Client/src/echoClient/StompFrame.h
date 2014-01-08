/*
 * StompFrame.h
 */

#ifndef STOMPFRAME_H_
#define STOMPFRAME_H_
#include <string>
#include <map>
#include <sstream>
#include <iostream>
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
	void setBody(string );
	void addHeader(string name,string value);
	string toString();


private:
	//header will be stored in map (name,value)
	std::map<std::string ,std::string> headers;
	string command;
	string body;
	string packet_string;
};

#endif /* STOMPFRAME_H_ */
