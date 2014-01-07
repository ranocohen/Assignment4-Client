/*

#include "CMPPHandler.h"
#include "STOMPHandler.h"
#include "ClientInfo.h"

#include "../test/TestClient.h"

#include <Poco/Thread.h>

#include <fstream>

int main(int argc,char* argv[])
{
	ClientInfo::getInstance()->connect(Poco::Net::SocketAddress("127.0.0.1",61613));
	if (argc>1)
	{
		std::ifstream ifile;
		ifile.open(argv[1]);
		TestClient c(ifile);
		c.run();
		return 0;
	}
	ClientInfo::getInstance()->setAckMode(true);
	Poco::Thread cmppthread,stompthread;
	Poco::Net::SocketInputStream inputsocket(ClientInfo::getInstance()->socket());
	STOMPHandler stomphandler(inputsocket);
	CMPPHandler cmpphandler(std::cin);
	cmppthread.start(cmpphandler);
	stompthread.start(stomphandler);
	cmppthread.join();
	stompthread.join();
	return 0;
}
*/
