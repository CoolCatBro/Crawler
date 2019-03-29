#pragma once

#include <string>
#include <fstream>
#include <cassert>
#include <sstream>
#include <iostream>

//file and directory perm
#include <sys/stat.h>

#include "Globals.hpp"

using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::cout;

class Storage
{
	string targetDir;
public:

	//set targetDir
	Storage(string targetDir);

	//return absolute dir path
	string getDirPath(string dirPath);

	//check if the target path and its permissions
	bool validateDir(string dirPath);
	
	//create a new dir
	void  createDir(string dirName, string dirPath);

	//return absolute file path
	string getFilePath(string dirPath,string fileName);

	//read a file to string
	string readFile(string dirPath,string fileName);

	//write a new file
	void storeFile(string dirPath, string fileName, string fileData);
};