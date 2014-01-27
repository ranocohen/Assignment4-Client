// AppLogger.cpp

#include "Poco/LoggingFactory.h"
#include "Poco/Logger.h"
#include "Poco/ConsoleChannel.h"
#include "Poco/FileChannel.h"

#include "../headers/AppLogger.h"

using namespace Poco;
using namespace std;

CAppLogger::CAppLogger(void) {
	// We tell the vector how much elements we it'll have - its more efficient.
	mLoggers.resize(ELoggersCount);

	//configureLogger(CAppLogger::file);
	// Build the loggers
	mLoggers[ELoggerConsole] = &Logger::create("Log.Console",
			LoggingFactory::defaultFactory().createChannel("ConsoleChannel"),
			this->console_level);
	mLoggers[ELoggerFile] = &Logger::create("Log.File",
			LoggingFactory::defaultFactory().createChannel("FileChannel"),
			this->file_level);
	//note that the priorty level set different. the file logger will have more masseges then the console logger

	// Set file channel path property (file & directory).
	mLoggers[ELoggerFile]->getChannel()->setProperty("path", this->log_file_name);

	// Open all loggers.
	vector<Logger*>::iterator iterator;
	for (iterator = mLoggers.begin(); iterator != mLoggers.end(); iterator++) {
		if (*iterator != NULL) {
			(*iterator)->getChannel()->open();
		}
	}
}

CAppLogger::~CAppLogger(void) {
	// Close all loggers
	vector<Logger*>::iterator iterator;
	for (iterator = mLoggers.begin(); iterator != mLoggers.end(); iterator++) {
		if (*iterator != NULL) {
			(*iterator)->getChannel()->close();
			(*iterator)->getChannel()->release();
		}
	}
}

void CAppLogger::Log(const std::string& inLogString,
		Poco::Message::Priority inPriority/* = Poco::Message::PRIO_INFORMATION*/) {
	Message msg;
	msg.setPriority(inPriority);
	msg.setText(inLogString);

	vector<Logger*>::iterator iterator;
	for (iterator = mLoggers.begin(); iterator != mLoggers.end(); iterator++) {
		if (*iterator != NULL) {
			(*iterator)->log(msg);
		}
	}
}

void CAppLogger::Log(const std::ostringstream& inLogString,
		Poco::Message::Priority inPriority/* = Poco::Message::PRIO_INFORMATION*/) {
	Log(inLogString.str(), inPriority);
}

/*
 *configuration settings for logger
 */
void CAppLogger::configureLogger(char* conf) {
			this->log_file_name = "logFile";
			this->console_level = 2;
			this->file_level    = 2;
}
