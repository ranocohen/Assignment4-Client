/*
 * CommandAnalyzer.h
 *
 *  Created on: Jan 8, 2014
 *      Author: idanakav
 */

#ifndef COMMANDPARSER_H_
#define COMMANDPARSER_H_

#include <string>
#include "StompFrame.h"
using namespace std;
class CommandParser {
public:
	CommandParser(string command);
	StompFrame getStompFrame();
	virtual ~CommandParser();

private:
	string command;
};

#endif /* COMMANDPARSER_H_ */
