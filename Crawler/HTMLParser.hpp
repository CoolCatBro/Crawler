#pragma once

#include <string>
#include <deque>

using std::string;
using std::deque;

class HTMLParser
{
public:
	deque<string> links;

	HTMLParser();

	void getLinks(string data);
};

