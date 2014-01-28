/*
 * HTMLHandler.cpp
 *
 *  Created on: Jan 28, 2014
 *      Author: ran
 */

#include "../headers/HTMLHandler.h"
#include <stdio.h>

HTMLHandler::HTMLHandler() {

	html_file.open("tweets.html");

	html_file << "<!DOCTYPE html> \n <html> \n\t <head> \n "
			"\t\t <title>Tweets</title> \n <link rel='stylesheet' href='table.css' type='text/css'/> <div class='CSSTableGenerator' >\t</head> \n <body> \t<table>\n";

	html_file << "<tr><td>User</td><td>Tweet</td><td>Time</td></tr>\n";

	html_file.close();
}

HTMLHandler::~HTMLHandler() {
// TODO Auto-generated destructor stub
}

void HTMLHandler::addTweetTag(string user, string tweet, string time) {

	ofstream logging;

	html_file.open("tweets.html", std::ios_base::app);

	//add single tweet
	html_file << "<tr><td>" + user +"</td><td>" + tweet +"</td><td>" + time +"</td></tr>\n";
	html_file.close();

}

void HTMLHandler::sealHTMLFile() {
	ofstream logging;

		html_file.open("tweets.html", std::ios_base::app);
		html_file << "</table>\n</div>	</body>\n </html>";
		html_file.close();

}

