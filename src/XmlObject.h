/*
 * XmlObject.h
 *
 *  Created on: 30 maj 2015
 *      Author: karol
 */

#ifndef XMLOBJECT_H_
#define XMLOBJECT_H_

#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;
class XmlObject
{
protected:
	string element;
	void set_elem(string);
public:
	XmlObject(string);

	virtual ~XmlObject();
	virtual string to_xml()=0;
	virtual void from_xml(ifstream&)=0;
	virtual string ret_elem()=0;
};

class XmlObject_string:public XmlObject
{

	string name;
public:
	XmlObject_string(string=NULL, string=NULL);
	string to_xml();
	void from_xml(ifstream&);
	string ret_elem();
	void set_elem(string);
	friend
	ifstream& operator >>(ifstream& File, XmlObject_string& x);
	friend
	ofstream& operator <<(ofstream& File, XmlObject_string x);
	friend
	ostream& operator <<(ostream& os, XmlObject_string x);
};

class XmlObject_int:public XmlObject
{
	int value;
public:
	XmlObject_int(string, int=0);
	virtual string to_xml();
	void from_xml(ifstream&);
	string ret_elem();
	int ret_value();
	void set_value(int);
	friend
	ifstream& operator >>(ifstream& File, XmlObject_int& x);
	friend
	ofstream& operator <<(ofstream& File, XmlObject_int x);
	friend
	ostream& operator <<(ostream& os, XmlObject_string x);
};

class XmlObject_char:public XmlObject
{
	char mark;
public:
	XmlObject_char(string, char=0);
	virtual string to_xml();
	void from_xml(ifstream&);
	string ret_elem();
	friend
	ifstream& operator >>(ifstream& File, XmlObject_char& x);
	friend
	ofstream& operator <<(ofstream& File, XmlObject_char x);
	friend
	ostream& operator <<(ostream& os, XmlObject_string x);
};

template <int size>
class XmlVect
{

	string element;
	XmlObject_int SIZE;

	int count;
	enum{empty, full, some_elements}state;
	XmlObject_string *Tab;
public:
	XmlVect();
	~XmlVect();
	void set_elem(string, string);
	bool push(XmlObject_string);
	bool remove(int);
	string to_xml();
	void from_xml(ifstream&);

};


#endif /* XMLOBJECT_H_ */
