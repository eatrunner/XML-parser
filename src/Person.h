/*
 * person.h
 *
 *  Created on: 30 maj 2015
 *      Author: karol
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <vector>
#include <fstream>
#include "XmlObject.h"

class Person:XmlObject
{
	XmlObject_string name;
	XmlObject_string surname;
	XmlObject_char sex;
	XmlObject_int pesel;
	XmlObject_int wzrost;
public:
	Person(string, string, char=0, int=0, int=0);
	Person(string);
	string to_xml();
	void from_xml(ifstream&);
	void wypisz();
	string ret_elem();
	friend
	ifstream& operator >>(ifstream& , Person& );
	friend
	ofstream& operator <<(ofstream& , Person);
	friend
	ostream& operator <<(ostream&, Person);

};



#endif /* PERSON_H_ */
