/*
 * CommandAnalyzer.cpp
 *
 *  Created on: Jan 8, 2014
 *      Author: idanakav
 */

#include "../headers/stomp/ConnectFrame.h"
#include "../headers/stomp/SubscribeFrame.h"
#include "../headers/stomp/UnsubscribeFrame.h"
#include "../headers/stomp/SendFrame.h"
#include "../headers/CommandParser.h"
#include <boost/algorithm/string.hpp>
#include <vector>
#include <boost/thread.hpp>
#include "../headers/UserNetworkingHandle.h"

CommandParser::CommandParser(string command) {
	this->command = command;
}
StompFrame* CommandParser::getStompFrame(ConnectionHandler* cH) {
	std::vector<std::string> parameters;
	boost::split(parameters, command, boost::is_any_of(" "));

	if (parameters.at(0) == "login") {
		ConnectFrame* cf = new ConnectFrame();
		cH->setHost(parameters.at(1));
		int port = atoi(parameters.at(2).c_str());
		cH->setPort(port);

		 if (!cH->connect()) {
			        std::cerr << "Could not connect to server. Check your Internet connection, IP and port." << std::endl;
			    } else
			    {
			    	std::cout << "Connected successfully" << endl;
			    	UserNetworkingHandle* unh = new UserNetworkingHandle(2, cH);
			    	boost::thread* thUNH = new boost::thread(&UserNetworkingHandle::run, unh);
			    }
		cf->set_user(parameters.at(3));
		cf->set_code(parameters.at(4));
		cout << cf->toString() << endl;
		return cf;
	} else if (parameters.at(0) == "follow") {
		SubscribeFrame* sf = new SubscribeFrame();
		sf->set_id("1234"); //TODO need to generate unique
		sf->set_destination(parameters.at(1)); //user
		cout << sf->toString() << endl;
		return sf;
	} else if (parameters.at(0) == "unfollow") {
		UnsubscribeFrame* usf = new UnsubscribeFrame();
		usf->set_id("1234"); //TODO need to generate unique
		cout << usf->toString() << endl;
		return usf;
	}else if (parameters.at(0) == "tweet") {
		SendFrame* mf = new SendFrame();
		mf->setBody(parameters.at(1));
		mf->set_destination("/topic/user"); //TODO implement user "channel" (=profile tweets)
		cout << mf->toString() << endl;
		return mf;
	}
	cout << "Hey wtf is this cmd ?" << endl;
	return NULL;

}
CommandParser::~CommandParser() {
}

