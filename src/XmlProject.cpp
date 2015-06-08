//============================================================================
// Name        : XmlProject.cpp
// Author      : Karol
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Person.h"
#include "XmlObject.h"
using namespace std;


int main()
{
	string imie="Jan", nazw="Kowalski";
	char plec='f';
	int id=123456, wzrost=14;
	string file="test2.xml";
	ifstream File;
	ofstream File2;
	Person ktos(imie, nazw, plec, id, wzrost,"friends","friend");
	Person ktos2("stas", "nieczyj", 'm', 876, 123,"friends", "friend");
	XmlObject_string myfriend("friend","kowalski");
	ktos.add_pers(myfriend);
	ktos.add_pers(myfriend);
	ktos.add_pers(myfriend);
	ktos2.add_pers(myfriend);
	cout<<ktos2<<endl;
	File.open(file.c_str(), fstream::in);
	File>>ktos2;
	File.close();
	cout<<ktos<<endl<<ktos2;




	return 0;
}
