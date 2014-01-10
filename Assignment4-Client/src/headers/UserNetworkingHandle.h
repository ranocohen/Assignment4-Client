

#ifndef USERNETWORKINGHANDLE_H_
#define USERNETWORKINGHANDLE_H_

#include <string>
#include <ostream>
#include <iostream>
#include "connectionHandler.h"
class UserNetworkingHandle {
public:
	UserNetworkingHandle(int number, ConnectionHandler* cH);
	void run();
	virtual ~UserNetworkingHandle();


private:

	int _id;
	ConnectionHandler* connectionHandler;
};

#endif /* USERNETWORKINGHANDLE_H_ */
