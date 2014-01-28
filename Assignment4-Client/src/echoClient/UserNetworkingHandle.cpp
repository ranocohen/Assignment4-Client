#include "../headers/UserNetworkingHandle.h"
#include "../headers/stomp/StompFrame.h"
#include "../headers/stomp/ErrorFrame.h"
#include "../headers/stomp/ConnectFrame.h"
#include "../headers/stomp/MessageFrame.h"

	using namespace std;
UserNetworkingHandle::UserNetworkingHandle(int number, ConnectionHandler* cH) :
		_id(number) {
	this->connectionHandler = cH;
	htmlfile = new HTMLHandler();
	htmlfile->openHTMLFile(connectionHandler->getUser());
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
	/*	cout << "NEW MESSAGE FROM SERVER " << std::endl;
		cout << answer<< std::endl;*/

		StompFrame* sf = getFrame(answer);

	}
}

StompFrame* UserNetworkingHandle::getFrame(string packetstring) {
	StompFrame* sf;
	string command;
	if (packetstring[0] == '\0' || packetstring[0] == '\n')
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
	else if(command =="MESSAGE")
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
	sf->apply(this->connectionHandler);
	if(command =="MESSAGE") {
		if(sf->getHeaderValue("isTweet") == "true") {
			std::cout << "New message : " << sf->getBody() << std::endl;
			htmlfile->addTweetTag(connectionHandler->getUser(),sf->getHeaderValue("sender"),sf->getBody(),sf->getHeaderValue("time"));
			//htmlfile->addTweetTag("ran","hello twitter","12:00");
			//htmlfile->addTweetTag("idan","adiel ashrov is my king","12:01");
			htmlfile->sealHTMLFile();
		}

	}
	if(command =="ERROR") {

		cout << "ERROR : " << sf->getBody();

	}

	return sf;
}
