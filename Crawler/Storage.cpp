#include "Storage.hpp"

Storage::Storage(string targetDir)
{
	this->targetDir = targetDir;
	
	if (!validateDir(""))
		system(string("mkdir " + targetDir).c_str());
}

string Storage::getDirPath(string dirPath)
{
	return targetDir + "/" + dirPath;
}

bool Storage::validateDir(string dirPath)
{
	dirPath = getDirPath(dirPath);

	struct stat file;
	stat(dirPath.c_str(), &file);
	
	//Check macros in global.hpp
	if (!S_ISDIR(file.st_mode) && !S_ISWR(file.st_mtime)) 
	{
		return false;
	}

	return true;
}

void Storage::createDir(string dirName, string dirPath)
{
	dirPath = getDirPath(dirPath);
	system( string("cd " + dirPath + " && mkdir "+ dirName).c_str() );
}

string Storage::getFilePath(string dirPath, string fileName)
{
	return targetDir + "/" + dirPath + "/" + fileName + ".txt";
}

string  Storage::readFile(string dirPath,string fileName)
{
	//Store file in string temp
	string temp;
	if (validateDir(dirPath))
	{
		ifstream ifile(getFilePath(dirPath,fileName));
		assert(ifile);															//The file was opened successfully

		stringstream ss; 
		ss << ifile.rdbuf();												//read complete file in a string
		temp = ss.str();

		ifile.close();
	}
	return temp;
}

void Storage::storeFile(string dirPath, string fileName ,string fileData)
{
	//Save the file in target dir as new file
	if (validateDir(dirPath))
	{
		ofstream ofile(getFilePath(dirPath,fileName));
		assert(ofile);														//The file was opened successfully

		ofile << fileData;

		ofile.close();
	}
}