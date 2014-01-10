#include "../headers/UserNetworkingHandle.h"


	UserNetworkingHandle::UserNetworkingHandle(int number, ConnectionHandler* cH) :
		_id(number) {
		this->connectionHandler = cH;

	}


	UserNetworkingHandle::~UserNetworkingHandle() {

	}


		void UserNetworkingHandle::run() {
using namespace std;
cout << "Trying to fetch data from server" << endl;
cout << "HOST" << connectionHandler->getHost() << endl;
			while (1) {

			std::string answer;
			cout << "HOST" << connectionHandler->getHost() << endl;
				if (!connectionHandler->getFrameAscii(answer,'\0')) {
					std::cout << "Disconnected. Exiting...\n" << std::endl;
					break;
				}
				std::cout << answer << endl;
			}
		}



