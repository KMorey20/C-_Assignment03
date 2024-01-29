#pragma once
#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>

//Spefification File
//Defines the class PhoneList and struct Directory
//Kara Morey

using namespace std;

//Struct
struct Directory
{
	string name; /*person or business*/
	int areaCode;
	int phoneNo;

	Directory* link;
};

//Base Class
class PhoneList {
public:
	PhoneList(string /*title*/);

	//Functions
	void showList(ostream& /*file or output*/);
	void addDirectory(string /*name*/, int /*areaCode*/, int /*phone number*/);
	void removeDirectory(string /*name*/);

	//Getters
	int getNoDirectory() { return noDirectories; }
	string getTitle() { return title; }

	//Destructor
	~PhoneList();

private:
	Directory* firstPtr;
	string title; /*title of the phone list*/
	int noDirectories;
};
