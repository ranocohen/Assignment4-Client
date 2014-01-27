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

CommandParser::CommandParser(string command) : uniqueId(0){
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
			std::cerr
					<< "Could not connect to server. Check your Internet connection, IP and port."
					<< std::endl;
		} else {
			std::cout << "Connected successfully" << endl;
			UserNetworkingHandle* unh = new UserNetworkingHandle(2, cH);
			boost::thread* thUNH = new boost::thread(&UserNetworkingHandle::run,
					unh);
		}
		cf->set_accept_version("1.2");
		cf->set_host(parameters.at(1));
		cf->set_user(parameters.at(3));
		cf->set_code(parameters.at(4));

		cout << cf->toString() << endl;
		return cf;
	} else if (parameters.at(0) == "follow") {
		SubscribeFrame* sf = new SubscribeFrame();

		string uId = getUniqueId(); //generate unique id for this subscription
		sf->set_id(uId);

		//get the destination (user to follow)
		string destTopic = parameters.at(1);

		//save the unique id in a map with this user name (later to be used for un-follow)
		following.insert(std::pair<string,string>(destTopic,uId));
		sf->set_destination(destTopic); //user

		cout << sf->toString() << endl;
		return sf;
	} else if (parameters.at(0) == "unfollow") {
		UnsubscribeFrame* usf = new UnsubscribeFrame();

		cout << usf->toString() << endl;
		return usf;
	} else if (parameters.at(0) == "tweet") {
		SendFrame* mf = new SendFrame();
		mf->set_destination(cH->getUser());
		mf->setBody(parameters.at(1));
		cout << mf->toString() << endl;
		return mf;
	}
	cout << "Hey wtf is this cmd ?" << endl;
	return NULL;

}
CommandParser::~CommandParser() {

}
//incrementing unique id function
string CommandParser::getUniqueId() {
	uniqueId++;
	ostringstream s;
	s << uniqueId;
	string ans = s.str();
	return ans;
}
