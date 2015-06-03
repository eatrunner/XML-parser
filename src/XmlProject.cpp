//============================================================================
// Name        : XmlProject.cpp
// Author      : Karol
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Person.h"
using namespace std;


int main()
{
	string imie="Jan", nazw="Kowalski";
	char plec='f';
	int id=123456, wzrost=14;
	string file="test.xml";
	ifstream File;
	ofstream File2;
	Person ktos(imie, nazw, plec, id, wzrost);
	Person ktos2("stas", "nieczyj", 'm', 876, 123);
	//ktos.save_xml();

	File.open(file.c_str(), fstream::in);
	File>>ktos;
	cout<<ktos<<endl<<ktos2;;
	File.close();
	File2.open(file.c_str(), fstream::out);
	File2<<ktos2;
	File2.close();
	return 0;
}
