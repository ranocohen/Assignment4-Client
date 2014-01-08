#include <stdlib.h>
#include <boost/locale.hpp>
#include "connectionHandler.h"
#include "../encoder/utf8.h"
#include "../encoder/encoder.h"
#include "ConnectFrame.h"
#include <iostream>
#include <boost/thread.hpp>

class UserNetworkingHandle {
private:

	int _id;

public:
    UserNetworkingHandle(int number, boost::mutex* mutex) :
			_id(number) {
	}

	void run() {
		for (int i = 0; i < 100; i++) {
            std::cout << i << ") Task " << _id << " is working" << std::endl;
		}
	}
};

class UserCommandHandler {
private:

	int _id;

public:
	UserCommandHandler(int number, boost::mutex* mutex) :
			_id(number) {
	}

	void run() {
		for (int i = 0; i < 100; i++) {
            std::cout << i << ") Task " << _id << " is working" << std::endl;
		}
	}
};

int main(int argc, char *argv[]) {
	boost::mutex mutex;

	UserCommandHandler uch(1, &mutex);
	UserCommandHandler uch1(2, &mutex);
	boost::thread th1(&UserCommandHandler::run, &uch);
	boost::thread th2(&UserCommandHandler::run, &uch1);

	th1.join();
	th2.join();

	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " host port" << std::endl
				<< std::endl;
		return -1;
	}
	std::string host = argv[1];
	int port = atoi(argv[2]);

	ConnectionHandler connectionHandler(host, 61613, &mutex);
	if (!connectionHandler.connect()) {
		std::cerr << "(BOOST) Cannot connect to " << host << ":" << port
				<< std::endl;
		return 1;
	}

	Encoder encoder;

	ConnectFrame cf;


	while (1) {
		std::cout << cf.toString();
		//send the string to the server:
		string ans = cf.toString();
		if (!connectionHandler.sendBytes(cf.toString().c_str(),
				cf.toString().length())) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
			break;
		}
		std::cout << "sent";

		std::string answer;

		if (!connectionHandler.getLine(answer)) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
		}
		std::cout << "ans:" << answer;

		string a;
		std::string utf8g(encoder.fromBytes(a.c_str()));

		const short bufsize = 1024;
		char buf[bufsize];
		std::cin.getline(buf, bufsize);
		std::string line(buf);
		int len = line.length();
		if (!connectionHandler.sendLine(line)) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
			break;
		}
		// connectionHandler.sendLine(line) appends '\n' to the message. Therefore we send len+1 bytes.
		std::cout << "Sent " << len + 1 << " bytes to server" << std::endl;

		if (!connectionHandler.getLine(answer)) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
		}

		std::cout << "answer:" << endl;
		std::cout << answer << endl;
		;
	}
	return 0;
}

