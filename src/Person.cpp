/*
 * person.cpp
 *
 *  Created on: 30 maj 2015
 *      Author: karol
 */
#include "Person.h"

Person::Person(string xname, string xsurnm, char xsex, int xId, int xwzrost):
					name("name",xname), surname("surname",xsurnm), sex("sex",xsex),
					pesel("pesel",xId), wzrost("wzrost",xwzrost){}

void Person::save_xml()
{
	stringstream tmp;
	string output;
	ofstream File;
	tmp<<"<person>";
	tmp<<name.to_xml()<<surname.to_xml()<<sex.to_xml()<<pesel.to_xml()
			<<wzrost.to_xml();
	tmp<<"</person>";
	output=tmp.str();
	File.open("test.xml", fstream::out);
			File<<output;
	File.close();

}

void Person::read_xml()
{

}

void Person::wypisz()
{
	stringstream tmp;
	string output;
	ofstream File;
	tmp<<"<person>";
	tmp<<name.to_xml()<<surname.to_xml()<<sex.to_xml()<<pesel.to_xml()<<wzrost.to_xml();
	tmp<<"</person>";
	output=tmp.str();
	cout<<output;
}

