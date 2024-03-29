#ifndef CONNECTION_HANDLER__
#define CONNECTION_HANDLER__

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

using boost::asio::ip::tcp;
using namespace std;
class ConnectionHandler {
private:

	boost::mutex * _mutex;
	std::string host;
	int port;
	boost::asio::io_service io_service;   // Provides core I/O functionality
	tcp::socket socket;
	string user;

public:
	ConnectionHandler(boost::mutex* mutex);
	virtual ~ConnectionHandler();

	// Connect to the remote machine
	bool connect();

	// Read a fixed number of bytes from the server - blocking.
	// Returns false in case the connection is closed before bytesToRead bytes can be read.
	bool getBytes(char bytes[], unsigned int bytesToRead);

	// Send a fixed number of bytes from the client - blocking.
	// Returns false in case the connection is closed before all the data is sent.
	bool sendBytes(const char bytes[], int bytesToWrite);

	// Read an ascii line from the server
	// Returns false in case connection closed before a newline can be read.
	bool getLine(std::string& line);

	// Send an ascii line from the server
	// Returns false in case connection closed before all the data is sent.
	bool sendLine(std::string& line);

	// Get Ascii data from the server until the delimiter character
	// Returns false in case connection closed before null can be read.
	bool getFrameAscii(std::string& frame, char delimiter);

	// Send a message to the remote host.
	// Returns false in case connection is closed before all the data is sent.
	bool sendFrameAscii(const std::string& frame, char delimiter);

	// Close down the connection properly.
	void close();

	// Set the host
	void setHost(string host);

	// Set the port
	void setPort(int port);

	// Get the host
	string getHost();
	// Get the host
	string getUser();

	void setUser(string user);
};
//class ConnectionHandler

#endif
