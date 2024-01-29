#include "phoneList.h"

//Client Code
//Kara Morey

int main()
{
    PhoneList* book1 = new PhoneList("My Black Book");
    assert(book1);
    cout << book1->getTitle() << endl;

    book1->addDirectory("J.Doe", 613, 5445400);
    book1->addDirectory("B3444", 819, 2761888);
    book1->addDirectory("D.Kat", 613, 9876543);
    book1->addDirectory("Z.Jas", 765, 9886422);
    book1->addDirectory("E.Gra", 776, 8767787);

    book1->showList(cout);
    cout << "Number of Directories: " << book1->getNoDirectory() << endl;

    cout << endl;

    book1->removeDirectory("B3444");
    book1->removeDirectory("J.Daz");
    book1->removeDirectory("D.Kat");
    book1->removeDirectory("E.Gra");

    cout << endl;

    book1->showList(cout);

    delete book1;
    return 0;
}

/*
My Black Book
Name           Area Code      Phone Number

B3444          819            2761888
D.Kat          613            9876543
E.Gra          776            8767787
J.Doe          613            5445400
Z.Jas          765            9886422

Number of Directories: 5

B3444 Directory Removed
J.Daz was not found
D.Kat Directory Removed
E.Gra Directory Removed

Name           Area Code      Phone Number

J.Doe          613            5445400
Z.Jas          765            9886422
*/