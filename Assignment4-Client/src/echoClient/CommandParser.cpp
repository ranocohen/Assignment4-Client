/*
 * CommandAnalyzer.cpp
 *
 *  Created on: Jan 8, 2014
 *      Author: idanakav
 */

#include "CommandParser.h"
#include <boost/algorithm/string.hpp>
#include <vector>
CommandParser::CommandParser(string command) {
	std::vector<std::string> parameters;

	boost::split(parameters, command, boost::is_any_of(" "));

}

CommandParser::~CommandParser() {
	// TODO Auto-generated destructor stub
}

