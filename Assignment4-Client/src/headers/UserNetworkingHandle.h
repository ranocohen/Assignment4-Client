

#ifndef USERNETWORKINGHANDLE_H_
#define USERNETWORKINGHANDLE_H_

#include <string>
#include <ostream>
#include <iostream>
#include "stomp/StompFrame.h"
#include "connectionHandler.h"
class UserNetworkingHandle {
public:
	UserNetworkingHandle(int number, ConnectionHandler* cH);
	void run();
	virtual ~UserNetworkingHandle();
	StompFrame* getFrame(string packetstring);

private:

	int _id;
	ConnectionHandler* connectionHandler;
};

#endif /* USERNETWORKINGHANDLE_H_ */
