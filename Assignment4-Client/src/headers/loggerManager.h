/*
 * loggerManager.h
 *
 *  Created on: Nov 15, 2013
 *      Author: Rancohen
 */

#ifndef LOGGER_MAN_H_
#define LOGGER_MAN_H_

#include "Poco/Logger.h"


using Poco::Logger;
using namespace std;

class LoggerManager {
public:
	LoggerManager();
	
	~LoggerManager();

private:
	Logger& logger;

};

#endif LOGGER_MAN_H_
