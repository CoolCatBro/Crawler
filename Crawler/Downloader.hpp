//It use wget to download a web page

#pragma once

#include <string>
#include <deque>
#include <map>

#include "Globals.hpp"
#include "Storage.hpp"
#include "HTMLParser.hpp"

using std::string;
using std::deque;
using std::map;

class Downloader
{
	Storage *storage;
	HTMLParser parser;
	
	deque<string> downloadQue;
	map<string, bool> mp;


	int count;
	int validLinks;

	int depth;
	int timeToDepthIncrease;

public:

	//constructor 
	Downloader(Storage* storage);

	//validate a url
	bool validateUrl(string url);

	//Get web page
	void getPage(string url);
};

