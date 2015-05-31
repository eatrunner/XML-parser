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

class Person
{
	XmlObject_string name;
	XmlObject_string surname;
	XmlObject_char sex;
	XmlObject_int pesel;
	XmlObject_int wzrost;
public:
	Person(string, string, char=0, int=0, int=0);
	void save_xml();
	void read_xml();
	void wypisz();

};



#endif /* PERSON_H_ */
