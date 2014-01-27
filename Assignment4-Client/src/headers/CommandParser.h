/*
 * CommandAnalyzer.h
 *
 *  Created on: Jan 8, 2014
 *      Author: idanakav
 */

#ifndef COMMANDPARSER_H_
#define COMMANDPARSER_H_

#include <string>
#include "../headers/connectionHandler.h"
#include "stomp/StompFrame.h"
#include <map>
using namespace std;
class CommandParser {
public:
	CommandParser(string command);
	StompFrame* getStompFrame(ConnectionHandler* cH);
	virtual ~CommandParser();
	string getUniqueId();
	string getSubscribeId(string topic);

private:
	string command;
	int uniqueId;
	map<string, string> following;


};

#endif /* COMMANDPARSER_H_ */
