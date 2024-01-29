#include "phoneList.h"

//Implimentation File
//Specifies what the PhoneList functions will do
//Kara Morey

//Non-Default Constructor
PhoneList::PhoneList(string passedTitle)
{
	title = (passedTitle != "") ? passedTitle : "No Name";
	noDirectories = 0;
	firstPtr = NULL;
}

//Deconstructor
PhoneList::~PhoneList()
{
	Directory* walker = firstPtr;

	while (walker != NULL)
	{
		Directory* next = walker->link;
		delete walker;
		walker = next;
	}
}

void PhoneList::showList(ostream& out)
{
	Directory* walker = firstPtr;

	cout << "Name " << setw(20) 
		 << "Area Code " << setw(18) 
		 << "Phone Number " << endl;

	cout << endl;

	while (walker != NULL)
	{
		cout << walker->name << setw(13) 
			 << walker->areaCode << setw(19) 
			 << walker->phoneNo << endl;

		walker = walker->link;
	}

	cout << endl;
}

void PhoneList::addDirectory(string newName, int newCode, int newPhoneNo)
{
	Directory* walker = firstPtr, * stalker = NULL;

	while (walker != NULL)
	{
		if (walker->name >= newName)
			break;

		stalker = walker;
		walker = walker->link;
	}

	if (walker != NULL && newName == walker->name)
	{
		cout << "Person/Business already exists " << endl;
	}
	else
	{
		Directory* builder = new Directory;
		assert(builder);

		builder->name = newName;
		builder->areaCode = newCode;
		builder->phoneNo = newPhoneNo;

		builder->link = walker;

		if (walker == firstPtr)
			firstPtr = builder;
		else
			stalker->link = builder;

		noDirectories++;
	}
}


void PhoneList::removeDirectory(string passedName)
{
	Directory* walker = firstPtr, * stalker = NULL;

	if (firstPtr == NULL)
	{
		cout << "List Empty" << endl;
	}
	else
	{
		while (walker != NULL)
		{
			if (walker->name == passedName)
			{
				stalker = walker;
				break;
			}

			stalker = walker;
			walker = walker->link;
		}

		if (walker == NULL)
		{
			cout << passedName << " was not found " << endl;
		}
		else
		{
			if (walker == firstPtr)
			{
				firstPtr = firstPtr->link;
			}
			else
			{
				stalker->link = walker->link;
			}

			delete walker;
			cout << passedName << " Directory Removed " << endl;
		}
	}
}

