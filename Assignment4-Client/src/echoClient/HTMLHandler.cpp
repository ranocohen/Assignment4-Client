/*
 * HTMLHandler.cpp
 *
 *  Created on: Jan 28, 2014
 *      Author: ran
 */

#include "../headers/HTMLHandler.h"
#include <stdio.h>

HTMLHandler::HTMLHandler() {

}

HTMLHandler::~HTMLHandler() {
// TODO Auto-generated destructor stub
}

void HTMLHandler::addTweetTag(string profile,string user, string tweet, string time) {

	ofstream logging;

	string fname = profile+".html";
	html_file.open(fname.c_str(), std::ios_base::app);

	//add single tweet
	html_file << "<tr><td>" + user +"</td><td>" + tweet +"</td><td>" + time +"</td></tr>\n";
	html_file.close();

}

void HTMLHandler::openHTMLFile(string profileName) {
	string fname = profileName+".html";
	html_file.open(fname.c_str());

	html_file << "<!DOCTYPE html> \n <html> \n\t <head> \n "
			"\t\t <title>Tweets</title> \n <link rel='stylesheet' href='table.css' type='text/css'/> <div class='CSSTableGenerator' >\t</head> \n <body> \t<table>\n";

	html_file << "<tr><td>User</td><td>Tweet</td><td>Time</td></tr>\n";

	html_file.close();
}

void HTMLHandler::sealHTMLFile() {
	ofstream logging;

		html_file.open("tweets.html", std::ios_base::app);
		html_file << "</table>\n</div>	</body>\n </html>";
		html_file.close();

}

