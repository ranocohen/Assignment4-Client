/*
 * CommandAnalyzer.h
 *
 *  Created on: Jan 8, 2014
 *      Author: idanakav
 */

#ifndef COMMANDPARSER_H_
#define COMMANDPARSER_H_

#include <string>
using namespace std;
class CommandParser {
public:
	CommandParser(string command);
	virtual ~CommandParser();
};

#endif /* COMMANDPARSER_H_ */
