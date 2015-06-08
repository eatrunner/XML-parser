/**
 * \file XmlObject.h
 * \Zawiera klase XmlObject i jej pochodne
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
#include <vector>
using namespace std;
//*************************************KLASA XmlObject***************************************
/**
 * Klasa XmlObject jest interfejsem.
 *
 */
class XmlObject
{
protected:
	/**element zawiera informacje i nazwie uzywanej struktury.
	 *
	 */
	string element;
	/**Funckja set element.
	 *  Pozwala ustawić nowa wartosc zmiennej element.
	 */
	void set_elem(string);
public:
	/**Kostruktor.
	 *
	 */
	XmlObject(string);
	/**Wirtualny destruktor.
	 *
	 */

	virtual ~XmlObject()=0;
	/**Funkcja to xml.
	 * Sluzy do parsowania obiektu do formatu XML
	 */
	virtual string to_xml()=0;
	/**Funkcja from xml.
	 * Sluzy do odczytu struktury z formatu XML.
	 * Jako argument przyjmuje zmienna plikowa
	 */
	virtual void from_xml(ifstream&)=0;
	/**Funkcja retrun element.
	 * Zwraca wartosc zmienna element.
	 */
	virtual string ret_elem()=0;
};
//*************************************KLASA XmlObject_string*********************************
/**Klasa XmlObject_string i dziedziczy po klasie XmlObject.
 * Przechowuje napisy.
 * Zawiera zmienna klasy string i wszystkie metody sluzace parsowaniu jej do formatu XML.
 */
class XmlObject_string:public XmlObject
{
	/**Zmienna name.
	 * Zawiera napis elementu struktury.
	 */
	string name;
public:
	/**Kostruktor.
	 * Jego argumenty zawieraja wartosci zmiennych kolejno:element, name.
	 * Domyślnie ustawiane sa na wskazniki zerowe.
	 */
	XmlObject_string(string="\0", string="\0");
	/**Destruktor klasy XmlObject_string.
	 *
	 */
	~XmlObject_string();
	/**Funkcja to xml.
	 * Nie przyjmuje argumentow.
	 * Parsuje obiekt do formatu XML (<element>name</element>)
	 */
	string to_xml();
	/**Funkcja from xml.
	 * Wczytuje zawartosc struktury z formatu XML.
	 * Jak argument przyjmuje zmienna plikowa wskazujaca na OTWARTY plik.
	 */
	void from_xml(ifstream&);
	/**Funkcja return element.
	 * Zwraca wartosc zmiennaj element.
	 */
	string ret_elem();
	/**Funkcja set element.
	 * Ustawia wartosc element na wartosc podana w argumencie.
	 */
	void set_elem(string);
	/**
	 * Zaprzyjazniony operator.
	 * Umozliwia odczyt ze zmiennej plikowej (File) do obiektu (obiekt) uzywajac zapisu:
	 * File>>obiekt;
	 * Plik musi zawierac strukture w formacie XML.
	 */
	friend
	ifstream& operator >>(ifstream& File, XmlObject_string& x);
	/**
	 * Zaprzyjazniony operator.
	 * Umozliwia parsowanie do zmiennej plikowej (File) z obiektu (obiekt) uzywajac zapisu:
	 * File<<obiekt;
	 * Zapisywanie jest do formatu XML.
	 */
	friend
	ofstream& operator <<(ofstream& File, XmlObject_string x);
	/**
	 * Zaprzyjazniony operator.
	 * Umozliwia parsowanie do strumienia wyjsciowego (cout) z obiektu (obiekt) uzywajac zapisu:
	 * cout<<obiekt;
	 */
	friend
	ostream& operator <<(ostream& os, XmlObject_string x);
};
//*************************************KLASA XmlObject_int**************************************
/**Klasa XmlObject_int dziedziczy po XmlObject.
 * Przechowuje liczby calkowite.
 * Posiada wszytkie metody potrzebne do parsowania do XML i odczytu.
 */
class XmlObject_int:public XmlObject
{
	/**Zmienna value.
	 * Zawiera liczbe calkowita elementu struktury.
	 */
	int value;
public:
	/**Konstruktor.
	 * Argumenty: wartosc docelowa element, wartosc docelowa value.
	 * Value domyslnie ustawiane na 0.
	 */
	XmlObject_int(string, int=0);
	/**Funkcja to xml.
	 * Parsuje obiekt do formatu XML i zwraca w postaci napisu(string).
	 */
	virtual string to_xml();
	/**Funkcja from xml.
	 * Wczytuje do obiektu z fomatu XML.
	 * Argumentem jest zmienna plikowa wskazujaca na OTWARTY plik.
	 */
	void from_xml(ifstream&);
	/**Funkcja return element.
	 * Zwraca wartosc element.
	 */
	string ret_elem();
	/**Funkcja return value.
	 * Zwraca wartosc zmiennej value.
	 */
	int ret_value();
	/**Funkcja set value.
	 * Ustawia wartosc value na ta podane w argumencie.
	 */
	void set_value(int);
	/**Zaprzyjazniony operator.
	 * Umozliwia odczyt ze zmiennej plikowej (File) do obiektu (obiekt) uzywajac zapisu:
	 * File>>obiekt;
	 * Plik musi zawierac strukture w formacie XML.
	 */
	friend
	ifstream& operator >>(ifstream& File, XmlObject_int& x);
	/**Zaprzyjazniony operator.
	 * Umozliwia parsowanie do zmiennej plikowej (File) z obiektu (obiekt) uzywajac zapisu:
	 * File<<obiekt;
	 */
	friend
	ofstream& operator <<(ofstream& File, XmlObject_int x);
	/**Zaprzyjazniony operator.
	 * Umozliwia parsowanie do strumienia wyjsciowego (cout) z obiektu (obiekt) uzywajac zapisu:
	 * cout<<obiekt;
	 *
	 */
	friend
	ostream& operator <<(ostream& os, XmlObject_string x);
};
//*************************************KLASA XmlObject_char**************************************

/**Klasa XmlObject_char dziedziczy po XmlObject.
 * Przechowuje znaki.
 * Posiada wszytkie metody potrzebne do parsowania do XML i odczytu.
 */

class XmlObject_char:public XmlObject
{
	/**Zmienna mark.
	 * Zawiera znak elementu struktury.
	 */
	char mark;
public:
	/**Konstruktor.
	 * Argumenty: wartosc docelowa element, wartosc docelowa mark.
	 * Mark domyslnie ustawiane na 0.
	 */
	XmlObject_char(string, char=0);
	/**Funkcja to xml.
	 * Parsuje obiekt do formatu XML i zwraca w postaci napisu(string).
	 */
	virtual string to_xml();
	/**Funkcja from xml.
	 * Wczytuje do obiektu z fomatu XML.
	 * Argumentem jest zmienna plikowa wskazujaca na OTWARTY plik.
	 */
	void from_xml(ifstream&);
	/**Funkcja return element.
	 * Zwraca wartosc element.
	 */
	string ret_elem();
	/**Zaprzyjazniony operator.
	 * Umozliwia odczyt ze zmiennej plikowej (File) do obiektu (obiekt) uzywajac zapisu:
	 * File>>obiekt;
	 * Plik musi zawierac strukture w formacie XML.
	 */
	friend
	ifstream& operator >>(ifstream& File, XmlObject_char& x);
	/**Zaprzyjazniony operator.
	 * Umozliwia parsowanie do zmiennej plikowej (File) z obiektu (obiekt) uzywajac zapisu:
	 * File<<obiekt;
	 */
	friend
	ofstream& operator <<(ofstream& File, XmlObject_char x);
	/**Zaprzyjazniony operator.
	 * Umozliwia parsowanie do strumienia wyjsciowego (cout) z obiektu (obiekt) uzywajac zapisu:
	 * cout<<obiekt;
	 */
	friend
	ostream& operator <<(ostream& os, XmlObject_string x);
};
//*************************************KLASA XmlVect**************************************

/**Klasa XmlVect dziedzieczy po XmlObject.
 * Zawiera tablice obiektow XmlObject_string.
 * Posiada wszytkie metody potrzebne do parsowania do XML i odczytu.
 * Zapis ma forme:
 * <element>
 * 	<SIZE>...</SIZE>
 * 	<Tab[0].element>Tab[0].name</Tab[0].element>
 * 	.
 * 	.
 * 	<Tab[n].element>Tab[n].name</Tab[n].element>
 * </element>
 */
class XmlVect:public XmlObject
{
	/**Kontener obiektow typu XmlObject_string.
	 *
	 */
	vector<XmlObject_string> tab;
public:
	/**Kostruktor.
	 * Argumenty:wartosc docelowa zmiennej element,
	 * wartosc docelowa zmienne element elementow listy,
	 * wielkosc tablicy elementow.
	 */
	XmlVect(string, string);
	/**Destruktor
	 * Zwalnie pamiec przydzielona na tablice.
	 */
	~XmlVect();
	void set_elem(string, string);
	/**Funkcja return element.
	 * Zwraca wartosc element.
	 */
	string ret_elem();
	/**Funkcja push.
	 * Pozwala dodac nowy obiekt XmlObject_string na koncu tablicy(O ile jest jeszcze miejsce).
	 */
	void push(XmlObject_string);
	/**Funkcja remove.
	 * Pozwala usunac obiekt XmlObject_string na koncu tablicy(O ile tablica nie jest pusta).
	 */
	void remove();
	/**Funkcja to xml.
	 * Parsuje obiekt do formatu XML i zwraca w postaci napisu(string).
	 */
	string to_xml();
	/**Funkcja from xml.
	 * Wczytuje do obiektu z fomatu XML.
	 * Argumentem jest zmienna plikowa wskazujaca na OTWARTY plik.
	 */
	void from_xml(ifstream&);

};


#endif /* XMLOBJECT_H_ */
