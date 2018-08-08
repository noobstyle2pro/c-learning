// Person.cpp is the class that define a person object
//
#include "stdafx.h"
#include "Person.h"
#include <iostream>
#include <exception>
#include "Noise.h"

using namespace std;

Person::Person(string first, string last,
	int arbitrary) : firstname(first), lastname(last),
	arbitrarynumber(arbitrary)
{
	Noise np("Speaking");

	if (arbitrarynumber == 0)
	{
		throw invalid_argument("Arbitrary number for a Person cannot be zero.");
	}
}

Person::Person() : firstname(""), lastname(""),
arbitrarynumber(0)
{
}

int Person::ratio()
{
	string fullname = GetName();
	int lengthwithoutspace = fullname.length() - 1;
	return arbitrarynumber / lengthwithoutspace;
}

Person::~Person()
{
	//cout << "destructing " << GetName() << endl;
}

string Person::GetName() const
{
	return firstname + " " + lastname;
}