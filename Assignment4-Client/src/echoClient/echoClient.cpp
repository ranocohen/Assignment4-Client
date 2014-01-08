#include <stdlib.h>
#include <boost/locale.hpp>
#include "connectionHandler.h"
#include "../encoder/utf8.h"
#include "../encoder/encoder.h"
#include "ConnectFrame.h"
/**
* This code assumes that the server replies the exact text the client sent it (as opposed to the practical session example)
*/
int main (int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " host port" << std::endl << std::endl;
        return -1;
    }
    std::string host = argv[1];
    //int port = atoi(argv[2]);
    int port = 1234;

    ConnectionHandler connectionHandler(host, port);
    if (!connectionHandler.connect()) {
        std::cerr << "(BOOST) Cannot connect to " << host << ":" << port << std::endl;
        return 1;
    }




	// We will send now  A Greek string encoded in UTF-8 to the server and get it back. We will play with this string a little:
	// A Greek string encoded in UTF-8
	// 20 = space                   = 0020
	// ce ba = kappa                = 03baa
	// cf 83 = sigma                = 03c3
	// ce bc = mu                   = 03bc
	// ce b5 = epsilon              = 03b5
	// a = new line					= 000a
	unsigned char greek[] = {0x20, 0xce, 0xba, 0xe1, 0xbd, 0xb9, 0xcf,
								 0x83, 0xce, 0xbc, 0xce, 0xb5, 0x0a, 0x00};


	Encoder encoder;


	ConnectFrame cf;


	//std::cout << cf.toString();
		//send the string to the server:
			if (!connectionHandler.sendBytes(encoder.toBytes(cf.toString()),strlen(cf.toString().c_str()))) {
					std::cout << "Sending connect to server..\n" << std::endl;
					return 1;
			}
			string a;
			std::string utf8g (encoder.fromBytes(a.c_str()));

			//get the echo back from the server as simple bytes:
			char greekEcho[256];
			if (!connectionHandler.getBytes(greekEcho, strlen(utf8g.c_str()))) {
					std::cout << "Disconnected. Exiting...\n" << std::endl;
					return 1;
			}
    while (1) {
        const short bufsize = 1024;
        char buf[bufsize];
        std::cin.getline(buf, bufsize);
		std::string line(buf);
		int len=line.length();
        if (!connectionHandler.sendLine(line)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }
		// connectionHandler.sendLine(line) appends '\n' to the message. Therefor we send len+1 bytes.
        std::cout << "Sent " << len+1 << " bytes to server" << std::endl;


        // We can use one of three options to read data from the server:
        // 1. Read a fixed number of characters
        // 2. Read a line (up to the newline character using the getline() buffered reader
        // 3. Read up to the null character
        std::string answer;
        // Get back an answer: by using the expected number of bytes (len bytes + newline delimiter)
        // We could also use: connectionHandler.getline(answer) and then get the answer without the newline char at the end
        if (!connectionHandler.getLine(answer)) {
            std::cout << "Disconnected. Exiting...\n" << std::endl;
            break;
        }

		len=answer.length();
		// A C string must end with a 0 char delimiter.  When we filled the answer buffer from the socket
		// we filled up to the \n char - we must make sure now that a 0 char is also present. So we truncate last character.
        answer.resize(len-1);
        std::cout << "Reply: " << answer << " " << len << " bytes " << std::endl << std::endl;
        if (answer == "bye") {
            std::cout << "Exiting...\n" << std::endl;
            break;
        }
    }




    return 0;
}
