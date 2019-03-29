#include "HTMLParser.hpp"



HTMLParser::HTMLParser()
{
}

void HTMLParser::getLinks(string data)
{
	bool tag,anchor,href;
	tag = anchor = href = false;

	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] == '<' && data[i+1] != '/')
			tag = true;

		if (tag && data[i] == 'a')
			anchor = true;

		if (tag && anchor && data[i] == 'h')
		{
			if (data.substr(i, 4) == "href")
				href = true;
		}
		
		if (tag && anchor && href && data[i] == '\"')
		{
			i++;
			string url;
			while (data[i] != '\"')
			{
				url.push_back(data[i]);
				i++;
			}
			links.push_back(url);
			href = false;
		}

		if (tag && data[i] == '>')
		{
			tag = false; anchor = false; href = false;
		}
	}
}