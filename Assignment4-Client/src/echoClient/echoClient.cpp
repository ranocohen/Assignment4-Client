#include <stdlib.h>
#include <boost/locale.hpp>
#include "../headers/connectionHandler.h"
#include "../encoder/utf8.h"
#include "../encoder/encoder.h"
#include "../headers/stomp/ConnectFrame.h"
#include <iostream>
#include <boost/thread.hpp>
#include "../headers/CommandParser.h"

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
		while (line != "exit") {
			const short bufsize = 1024;
			char buf[bufsize];
			std::cin.getline(buf, bufsize);
			std::string line(buf);
			int len = line.length();
			CommandParser parser(line);
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
			else
			{
				string dummy("DUMMY \0");
				connectionHandler->sendLine(dummy);
			}
		}

	}
};

int main(int argc, char *argv[]) {
	boost::mutex mutex;

	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " host port" << std::endl
				<< std::endl;
		return -1;
	}

	ConnectionHandler* connectionHandler = new ConnectionHandler(&mutex);

	UserCommandHandler uch(1, connectionHandler);

	boost::thread thUCH(&UserCommandHandler::run, &uch);

	thUCH.join();

	return 0;
}

