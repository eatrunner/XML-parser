/**
 * \file Person.h
 * \Zawiera klase Person
 *
 *  Created on: 30 maj 2015
 *      Author: karol
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <vector>
#include <fstream>
#include "XmlObject.h"
//*************************************KLASA Person***************************************
/**Klasa Person dziedziczy po XmlObject.
 * Docelowa struktura sparsowania do formatu XML.
 * Posiada wszyskie funkcja do parsowania w formacie XML.
 * Zawiera takie informacje jak:imie, nazwisko, plec, nr pesel, wzrost, lista znajomych.
 */
class Person:XmlObject
{
	/**Zmienna name.
	 * Zawiera imie osoby.
	 */
	XmlObject_string name;
	/**Zmienna surname.
	 * Zawiera nazwisko osoby.
	 */
	XmlObject_string surname;
	/**Zmienna sex.
	 * Zawiera plec osoby(m - male/f - female).
	 */
	XmlObject_char sex;
	/**Zmienna pesel.
	 * Zawiera nr pesel osoby.
	 */
	XmlObject_int pesel;
	/**Zmienna wzrost.
	 * Zawiera wzrost osoby.
	 */
	XmlObject_int wzrost;
	/**Zmienna friends.
	 * Zawiera liste znajomych osoby.
	 */
	XmlVect friends;
public:
	/**Konstruktor.
	 * Pozwala ustawic wszystkie atrybuty osoby wedlug koljenosci ich wystepowania.
	 */
	Person(string, string, char=0, int=0, int=0, string="friends", string="friend");
	/**Funkcja to xml.
	 * Parsuje obiekt do formatu XML i zwraca w postaci napisu(string).
	 */
	string to_xml();
	/**Funkcja from xml.
	 * Wczytuje do obiektu z fomatu XML.
	 * Argumentem jest zmienna plikowa wskazujaca na OTWARTY plik.
	 */
	void from_xml(ifstream&);
	/**Funkcja wypisz.
	 * Wypisuje cala strukture Person w formacie XML.
	 */
	void wypisz();
	/**Funkcja return element.
	 * Zwraca wartosc element.
	 */
	string ret_elem();
	/**Funkcja add person.
	 * Pozwala dodac nowego przyjaciela do listy.
	 */
	void add_pers(XmlObject_string);
	/**Zaprzyjazniony operator.
	 * Umozliwia odczyt ze zmiennej plikowej (File) do obiektu (obiekt) uzywajac zapisu:
	 * File>>obiekt;
	 * Plik musi zawierac strukture w formacie XML.
	 */
	friend
	ifstream& operator >>(ifstream& , Person& );
	/**Zaprzyjazniony operator.
	 * Umozliwia parsowanie do zmiennej plikowej (File) z obiektu (obiekt) uzywajac zapisu:
	 * File<<obiekt;
	 */
	friend
	ofstream& operator <<(ofstream& , Person);
	/**Zaprzyjazniony operator.
	 * Umozliwia parsowanie do strumienia wyjsciowego (cout) z obiektu (obiekt) uzywajac zapisu:
	 * cout<<obiekt;
	 */
	friend
	ostream& operator <<(ostream&, Person);

};



#endif /* PERSON_H_ */
