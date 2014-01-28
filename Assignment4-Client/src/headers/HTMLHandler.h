#ifndef HTMLHANDLER_H_
#define HTMLHANDLER_H_

#include <string>
#include <fstream>

using std::string;
using namespace std;

class HTMLHandler {
public:
	ofstream html_file;

	HTMLHandler();
	virtual ~HTMLHandler();
	void addTweetTag(string user, string tweet,string time);
	void sealHTMLFile();
};

#endif /* HTMLHANDLER_H_ */
