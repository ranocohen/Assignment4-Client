/*
 * CommandAnalyzer.cpp
 *
 *  Created on: Jan 8, 2014
 *      Author: idanakav
 */


#include "ConnectFrame.h"
#include "CommandParser.h"
#include <boost/algorithm/string.hpp>
#include <vector>
CommandParser::CommandParser(string command) {
	this->command = command;


}
StompFrame CommandParser::getStompFrame() {
	std::vector<std::string> parameters;
		boost::split(parameters, command, boost::is_any_of(" "));

		if(parameters.at(0)=="login") {
			ConnectFrame cf;
			cf.set_user(parameters.at(3));
			cf.set_code(parameters.at(4));
			cout << cf.toString();
			return cf;
		}
		StompFrame sf;
		return sf;
}
CommandParser::~CommandParser() {
}

