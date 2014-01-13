#include "../headers/UserNetworkingHandle.h"

UserNetworkingHandle::UserNetworkingHandle(int number, ConnectionHandler* cH) :
		_id(number) {
	this->connectionHandler = cH;

}

UserNetworkingHandle::~UserNetworkingHandle() {

}

void UserNetworkingHandle::run() {
	using namespace std;

	while (1) {
		cout << "Trying to fetch data from server" << endl;
		std::string answer;

		if (!connectionHandler->getFrameAscii(answer, '\0')) {
			std::cout << "Disconnected. Exiting...\n" << std::endl;
			break;
		}
		std::cout << "FROM SERVER !! : " << answer << endl;
	}
}

