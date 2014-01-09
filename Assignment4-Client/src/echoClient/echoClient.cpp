#include <stdlib.h>
#include <boost/locale.hpp>
#include "../headers/connectionHandler.h"
#include "../encoder/utf8.h"
#include "../encoder/encoder.h"
#include "../headers/stomp/ConnectFrame.h"
#include <iostream>
#include <boost/thread.hpp>
#include "../headers/CommandParser.h"
class UserNetworkingHandle {
private:

	int _id;
	ConnectionHandler* connectionHandler;

public:
	UserNetworkingHandle(int number, ConnectionHandler* cH) :
		_id(number) , connectionHandler(cH){}

		void run() {
			while (1) {
				std::string answer;
				if (!connectionHandler->getFrameAscii(answer,'\0')) {
					std::cout << "Disconnected. Exiting...\n" << std::endl;
				}
				std::cout << answer << endl;
			}
		}
};

class UserCommandHandler {
private:

	int _id;
	ConnectionHandler* connectionHandler;

public:
	UserCommandHandler(int number, ConnectionHandler* cH) :
			_id(number) , connectionHandler(cH){}
	std::string line;
		void run() {
			while (line!="exit") {
				const short bufsize = 1024;
				char buf[bufsize];
				std::cin.getline(buf, bufsize);
				std::string line(buf);
				int len = line.length();
					CommandParser parser(line);
					StompFrame* sf = parser.getStompFrame();
					// Set the host
					sf->apply(connectionHandler);
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
};

int main(int argc, char *argv[]) {
	boost::mutex mutex;

	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " host port" << std::endl
				<< std::endl;
		return -1;
	}


	ConnectionHandler connectionHandler(&mutex);

	UserCommandHandler uch(1, &connectionHandler);
	UserNetworkingHandle unh(2, &connectionHandler);
	boost::thread thUCH(&UserCommandHandler::run, &uch);
	boost::thread thUNH(&UserNetworkingHandle::run, &unh);

	thUCH.join();
	thUNH.join();


	return 0;
}

