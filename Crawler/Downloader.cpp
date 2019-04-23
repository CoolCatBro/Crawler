#include "Downloader.hpp"


Downloader::Downloader(Storage* storage)
					:storage(storage), count(1)
{
	validLinks = 0;
	depth = 0;
	timeToDepthIncrease = 0;
}

bool Downloader::validateUrl(string url)
{
	//restrict the host
	for (int i = 0; i < SEED_URL.length(); i++)
	{
		if (SEED_URL[i] != url[i])
			return false;
	}

	//check if the page exsist
	if (  system ( string("wget --spider -q " + url) .c_str())  )
		return false;

	return true;
}

void Downloader::getPage(string url)
{
	if (!mp[url])
	{
		cout << "url: " << url << std::endl;
		mp[url] = true;
		if (!storage->validateDir("temp"))
			storage->createDir("temp", "");

		system(string("wget -q -O " + storage->getFilePath("temp", "temp") + " " + url).c_str());

		string data = storage->readFile("temp", "temp");
		parser.getLinks(data);

		while (!parser.links.empty())
		{

			if (!mp[parser.links.front()] && validateUrl(parser.links.front()))
			{
				validLinks++;
				downloadQue.push_back(parser.links.front());
			}

			parser.links.pop_front();
		}

		if (!timeToDepthIncrease)
		{
			timeToDepthIncrease = validLinks;
			validLinks = 0;
			depth++;
		}

		storage->storeFile("", "file" + std::to_string(count), data);
		cout << "created file : " << "file"<<count<<std::endl;
		count++;
	}
	//recursive call

	downloadQue.pop_front();
	timeToDepthIncrease--;

	cout << "Depth is : " << depth << std::endl;

	if (!downloadQue.empty()) {
		getPage(downloadQue.front());
	}
	else
	{
		cout << "Fetched";
	}
}
