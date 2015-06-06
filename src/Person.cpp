/*
 * \file Person.cpp
 * \Zawiera definicje dunkcji skladowych klasy Person
 *
 *  Created on: 30 maj 2015
 *      Author: karol
 */
#include "Person.h"

Person::Person(string xname, string xsurnm, char xsex, int xId, int xwzrost, string xfriends,
		string vectElem, int size):
					XmlObject("person"),name("name",xname), surname("surname",xsurnm),
					sex("sex",xsex), pesel("pesel",xId), wzrost("wzrost",xwzrost),
					friends(xfriends, vectElem, size){}


string Person::to_xml()
{
	stringstream tmp;
	ofstream File;
	tmp<<"<person>";
	tmp<<name.to_xml()<<surname.to_xml()<<sex.to_xml()<<pesel.to_xml()
			<<wzrost.to_xml()<<friends.to_xml();
	tmp<<"</person>";
	string output=tmp.str();
	File.open("test.xml", fstream::out);
			File<<output;
	File.close();

	return output;

}

void Person::from_xml(ifstream& File)
{
	char c=0;
	string tmp='<'+element+'>';
	for(int i=0;i<tmp.length() && File>>c ;i++)
	{
		if(tmp[i]!=c)
		{
			cerr<<"Blad pliku. Niepoprawny Xml.Element: "<<element<<endl;
			return;
		}
	}
	name.from_xml(File);
	surname.from_xml(File);
	sex.from_xml(File);
	pesel.from_xml(File);
	wzrost.from_xml(File);
	tmp="</"+element+">";
	for(int i=0;i<tmp.length() && File>>c;i++)
	{
		if(tmp[i]!=c)
		{
			cerr<<"Blad pliku. Niepoprawny Xml.Element: "<<element<<endl;
			return;
		}
	}
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

string Person::ret_elem()
{
	return element;
}

void Person::add_pers(XmlObject_string no)
{
	friends.push(no);
}

ifstream& operator >>(ifstream& File, Person& p)
{
	if(!File.is_open())
		cerr<<"File not open";
	p.from_xml(File);
	return File;
}

ofstream& operator <<(ofstream& File, Person p)
{
	if(!File.is_open())
		cerr<<"File not open";
	File<<p.to_xml();
	return File;
}

ostream& operator <<(ostream& os, Person p)
{
	os<<p.to_xml();
	return os;
}
