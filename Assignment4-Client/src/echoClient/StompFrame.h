/*
 * StompFrame.h
 *
 *  Created on: Jan 6, 2014
 *      Author: idanakav
 */

#ifndef STOMPFRAME_H_
#define STOMPFRAME_H_
#include <string>
#include <map>

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
	void setHeaderValue(string name,string value);

	virtual string toString() =0;


private:
	//header will be stored in map (name,value)
	std::map<std::string ,std::string> headers_;
};

#endif /* STOMPFRAME_H_ */
