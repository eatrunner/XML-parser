/*
 * XmlObject.cpp
 *
 *  Created on: 30 maj 2015
 *      Author: karol
 */
#include "XmlObject.h"

XmlObject::XmlObject(string xelem):element(xelem){}

XmlObject::~XmlObject(){}

XmlObject_string::XmlObject_string(string xelem,string xname):XmlObject(xelem),name(xname){}

string XmlObject_string::to_xml()
{
	stringstream tmp;
	string strm;
	tmp<<'<'<<XmlObject::element<<'>'<<name<<"</"<<XmlObject::element<<'>';
	strm=tmp.str();
	return strm;
}

void XmlObject_string::from_xml(ifstream& File)
{
	int j=0;
	char c=0;
	string tmp='<'+element+'>';
	for(int i=0;i<tmp.length() && File>>c;i++)
	{
		if(tmp[i]!=c)
		{
			cerr<<"Blad pliku. Niepoprawny Xml.Element: "<<element<<endl;
			return;
		}
	}
	for(c=0; File>>c && c!='<';++j)
		name[j]=c;
	++j;
	name[j]=0;
	tmp="</"+element+'>';
	for(int i=1;i<tmp.length() && File>>c;i++)
	{
		if(tmp[i]!=c)
		{
			cerr<<"Blad pliku. Niepoprawny Xml.Element: "<<element<<endl;
			return;
		}
	}

}

string XmlObject_string::ret_elem()
{
	return XmlObject::element;
}

ifstream& operator >>(ifstream& File, XmlObject_string& x)
{
	if(!File.is_open())
		cerr<<"File not open";
	x.from_xml(File);
	return File;
}


ofstream& operator <<(ofstream& File, XmlObject_string x)
{
	if(!File.is_open())
		cerr<<"File not open";
	File<<x.to_xml();
	return File;
}

ostream& operator <<(ostream& os, XmlObject_string x)
{
	os<<x.to_xml();
	return os;
}

XmlObject_int::XmlObject_int(string xelem, int x):XmlObject(xelem), value(x){}

string XmlObject_int::to_xml()
{
	string strm;
	stringstream tmp;
	tmp<<'<'<<XmlObject::element<<'>'<<value<<"</"<<XmlObject::element<<'>';
	strm=tmp.str();
	return strm;
}

void XmlObject_int::from_xml(ifstream& File)
{
	value=0;
	char c=0;
	int j=0;
	string tmp='<'+element+'>';
	for(int i=0;i<tmp.length() && File>>c;i++)
	{
		if(tmp[i]!=c)
		{
			cerr<<"Blad pliku. Niepoprawny Xml.Element: "<<element<<endl;
			return;
		}
	}
	tmp.clear();
	for(j=0; File>>c && c!='<';++j)
	{
		tmp[j]=c;
	}
	for(int i=0; i<=j; ++i)
	{
		value+=pow(10,(j-i))*(int)tmp[i];
	}
	tmp="</"+element+'>';
	for(int i=1;i<tmp.length() && File>>c;i++)
	{
		if(tmp[i]!=c)
		{
			cerr<<"Blad pliku. Niepoprawny Xml.Element: "<<element<<endl;
			return;
		}
	}


}

string XmlObject_int::ret_elem()
{
	return XmlObject::element;
}

ifstream& operator >>(ifstream& File, XmlObject_int& x)
{
	if(!File.is_open())
		cerr<<"File not open";
	x.from_xml(File);
	return File;
}

ofstream& operator <<(ofstream& File, XmlObject_int x)
{
	if(!File.is_open())
		cerr<<"File not open";
	File<<x.to_xml();
	return File;
}

ostream& operator <<(ostream& os, XmlObject_int x)
{
	os<<x.to_xml();
	return os;
}

XmlObject_char::XmlObject_char(string xelem, char xmark):XmlObject(xelem), mark(xmark){}

string XmlObject_char::to_xml()
{
	string strm;
	stringstream tmp;
	tmp<<'<'<<XmlObject::element<<'>'<<mark<<"</"<<XmlObject::element<<'>';
	strm=tmp.str();
	return strm;
}

void XmlObject_char::from_xml(ifstream& File)
{

	char c=0;
	string tmp='<'+element+'>';
	for(int i=0;i<tmp.length() && File>>c;i++)
	{
		if(tmp[i]!=c)
		{
			cerr<<"Blad pliku. Niepoprawny Xml.Element: "<<element<<endl;
			return;
		}
	}
	File>>mark;
	tmp="</"+element+'>';
	for(int i=0;i<tmp.length() && File>>c;i++)
	{
		if(tmp[i]!=c)
		{
			cerr<<"Blad pliku. Niepoprawny Xml.Element: "<<element<<endl;
			return;
		}
	}
}

string XmlObject_char::ret_elem()
{
	return XmlObject::element;
}

ifstream& operator >>(ifstream& File, XmlObject_char& x)
{
	if(!File.is_open())
		cerr<<"File not open";
	x.from_xml(File);
	return File;
}

ofstream& operator <<(ofstream& File, XmlObject_char x)
{
	if(!File.is_open())
		cerr<<"File not open";
	File<<x.to_xml();
	return File;
}

ostream& operator <<(ostream& os, XmlObject_char x)
{
	os<<x.to_xml();
	return os;
}
