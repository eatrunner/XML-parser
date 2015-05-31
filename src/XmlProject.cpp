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
	int id=123456, wzrost=196;
	Person ktos(imie, nazw, plec, id, wzrost);
	ktos.save_xml();
	ktos.wypisz();

	return 0;
}
