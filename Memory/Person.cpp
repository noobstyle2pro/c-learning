#include "stdafx.h"
#include <iostream>
#include "Person.h"
#include "Resource.h"

using namespace std;

Person::Person(std::string first,
	std::string last,
	int arbitrary) : firstname(first), lastname(last),
	arbitrarynumber(arbitrary), pResource(nullptr)
{
}

Person::~Person()
{
	delete pResource;
}

string Person::GetName() const { return firstname + " " + lastname; }

bool Person::operator<(const Person& p) const { return arbitrarynumber < p.arbitrarynumber; }

bool Person::operator<(int i) const { return arbitrarynumber < i; }

bool operator<(int i, const Person& p) { return i < p.arbitrarynumber; }

void Person::AddResource() {
	/*Resource r("hello"); // pResource will be delete when
	pResource = &r;*/	   // out of the function scope
	// to fix. use code below instead
	pResource = new Resource("Resource for " + GetName());
}