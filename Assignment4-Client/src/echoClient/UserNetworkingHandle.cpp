#include "../headers/UserNetworkingHandle.h"


	UserNetworkingHandle::UserNetworkingHandle(int number, ConnectionHandler* cH) :
		_id(number) , connectionHandler(cH){}


	UserNetworkingHandle::~UserNetworkingHandle() {
	}


		void UserNetworkingHandle::run() {
using namespace std;
			while (1) {
			std::string answer;
				if (!connectionHandler->getFrameAscii(answer,'\0')) {
					std::cout << "Disconnected. Exiting...\n" << std::endl;
					break;
				}
				std::cout << answer << endl;
			}
		}



