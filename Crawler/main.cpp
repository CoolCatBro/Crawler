#include "Storage.hpp"
#include "Downloader.hpp"
#include "HTMLParser.hpp"

//The main function

int main(int argc,char** argv)  // argument count and argument vector
{
	//set up the target
	Storage store("karan");
	Downloader d(&store);
	d.getPage(SEED_URL);
	system("pause");
	return 0;
}