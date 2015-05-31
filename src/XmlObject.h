/*
 * XmlObject.h
 *
 *  Created on: 30 maj 2015
 *      Author: karol
 */

#ifndef XMLOBJECT_H_
#define XMLOBJECT_H_

#include <sstream>
#include <iostream>
using namespace std;
class XmlObject
{
protected:
	string element;
public:
	XmlObject(string);
	virtual ~XmlObject();
	virtual string to_xml()=0;
	virtual string ret_elem()=0;

};

class XmlObject_string:public XmlObject
{

	string name;
public:
	XmlObject_string(string, string=NULL);
	virtual string to_xml();
	string ret_elem();
};

class XmlObject_int:public XmlObject
{
	int value;
public:
	XmlObject_int(string, int=0);
	virtual string to_xml();
	string ret_elem();

};

class XmlObject_char:public XmlObject
{
	char mark;
public:
	XmlObject_char(string, char=0);
	virtual string to_xml();
	string ret_elem();
};

#endif /* XMLOBJECT_H_ */
