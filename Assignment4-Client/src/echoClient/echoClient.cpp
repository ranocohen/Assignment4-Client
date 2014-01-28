#include <stdlib.h>
#include <boost/locale.hpp>
#include "../headers/connectionHandler.h"
#include "../encoder/utf8.h"
#include "../encoder/encoder.h"
#include "../headers/stomp/ConnectFrame.h"
#include <iostream>
#include <boost/thread.hpp>
#include "../headers/CommandParser.h"
#include "../headers/AppLogger.h"
#include "HTMLHandler.h"


class UserCommandHandler {
private:

	int _id;
	ConnectionHandler* connectionHandler;

public:
	UserCommandHandler(int number, ConnectionHandler* cH) :
			_id(number) {
		connectionHandler = cH;
	}
	std::string line;
	void run() {
		CommandParser parser(line);
		while (line != "exit") {
			const short bufsize = 1024;
			char buf[bufsize];
			std::cin.getline(buf, bufsize);
			std::string line(buf);
			int len = line.length();
			parser.setCommand(line);
			StompFrame* sf = parser.getStompFrame(connectionHandler);
			// Set the host
			if (sf != NULL) {
				string toSend = sf->toString();
				if (!connectionHandler->sendLine(toSend)) {
					std::cout << "Disconnected. Exiting...\n" << std::endl;
					break;
				}
				// connectionHandler.sendLine(line) appends '\n' to the message. Therefore we send len+1 bytes.
				std::cout << "Sent " << len + 1 << " bytes to server"
						<< std::endl;
			}
		}

	}
};

int main(int argc, char *argv[]) {
	boost::mutex mutex;

	//CAppLogger::file = "logFile";

	//CAppLogger::Instance().Log("FATAL" , Poco::Message::PRIO_FATAL);

	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " host port" << std::endl
				<< std::endl;
		return -1;
	}

	HTMLHandler* htmlfile = new HTMLHandler();
	htmlfile->addTweetTag("ran","hello twitter","12:00");
	htmlfile->addTweetTag("idan","adiel ashrov is my king","12:01");

	htmlfile->sealHTMLFile();

	ConnectionHandler* connectionHandler = new ConnectionHandler(&mutex);

	UserCommandHandler uch(1, connectionHandler);

	boost::thread thUCH(&UserCommandHandler::run, &uch);

	thUCH.join();

	return 0;
}

char* CAppLogger::file;


