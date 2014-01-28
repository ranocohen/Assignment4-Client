#include "../headers/UserNetworkingHandle.h"
#include "../headers/stomp/StompFrame.h"
#include "../headers/stomp/ErrorFrame.h"
#include "../headers/stomp/ConnectFrame.h"
#include "../headers/stomp/MessageFrame.h"

	using namespace std;
UserNetworkingHandle::UserNetworkingHandle(int number, ConnectionHandler* cH) :
		_id(number) {
	this->connectionHandler = cH;

}

UserNetworkingHandle::~UserNetworkingHandle() {

}

void UserNetworkingHandle::run() {


	while (1) {

		std::string answer;
		if (!connectionHandler->getFrameAscii(answer, '\0')) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
			break;
		}
		cout << "NEW MESSAGE FROM SERVER " << std::endl;
		cout << answer<< std::endl;

		StompFrame* sf = getFrame(answer);

	}
}

StompFrame* UserNetworkingHandle::getFrame(string packetstring) {
	StompFrame* sf;
	string command;
	if (packetstring.length() == 0 || packetstring == "\0")
		return NULL;
	if (packetstring.find('\0') == std::string::npos) {
		std::stringstream ss;
		ss << "Packet string contains the null character at position "
				<< packetstring.find('\0') << "/" << packetstring.length()
				<< std::endl;
		return NULL;
	}

	std::stringstream ss(packetstring);
	while (command.empty() && ss.good())
		getline(ss, command);

	if(command == "ERROR")
		sf = new ErrorFrame();
	else if(command =="CONNECT")
		sf = new ConnectFrame();
	else if(command =="Message")
		sf = new MessageFrame();


	std::string line;
	getline(ss, line);
	while ((ss.good()) && (line.size() > 0) && (line[0] != 0)) {
		if (line.find(':') == std::string::npos)
			return NULL;
		std::string name = line.substr(0, line.find(":"));
		std::string value = line.substr(line.find(":") + 1);
		if (name.empty())
			return NULL;
		sf->addHeader(name, value);
		getline(ss, line);
	}
	string body;
	while (ss.good()) {
		int c = ss.get();
		if (c != -1)
			body += c;
	}
	sf->setBody(body);


	return sf;
}
