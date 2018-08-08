// Person.cpp is the class that define a person object
//
#include "stdafx.h"
#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(string first, string last,
	int arbitrary) : firstname(first), lastname(last),
	arbitraryNumber(arbitrary)
{
	cout << "constructing " << GetName() << endl;
}

Person::~Person()
{
	cout << "destructing " << GetName() << endl;
}

string Person::GetName() { return firstname + " " + lastname; }

//comparison operator overload example
bool Person::operator<(Person& p) { return arbitraryNumber < p.arbitraryNumber; }

bool Person::operator<(int i) { return arbitraryNumber < i; }

bool operator<(int i, Person& p) { return i < p.arbitraryNumber; }