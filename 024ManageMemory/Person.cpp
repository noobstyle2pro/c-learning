#include "stdafx.h"
#include "Person.h"

using std::string;
using std::make_shared;

Person::Person(string first, string last,
	int arbitrary) : firstname(first), lastname(last),
	arbitrarynumber(arbitrary)
{
}

//Person::Person(const Person& p) : firstname(p.firstname), lastname(p.lastname),
//	arbitrarynumber(p.arbitrarynumber)
//{
//	pResource.reset(new Resource(p.GetResourceName()));
//}

Person::~Person()
{
}

//Person& Person::operator=(const Person& p) // this to allow the copy assign feature
//{
//	firstname = p.firstname;
//	lastname = p.lastname;
//	arbitrarynumber = p.arbitrarynumber;
//	pResource.reset(new Resource(p.GetResourceName())); // it will clear the old value in the free store
//
//	return *this;
//}

string Person::GetName() const { return firstname + lastname; }

int Person::GetNumber() const { return arbitrarynumber; }


void Person::SetResource(string resourcename)
{
	//Resource newResource(resourcename);
	/*pResource = newResource;*/ // copy assignment statement (overload
							 // in the resource) this is 
							 // wasteful behaviour
	//pResource.reset(new Resource(resourcename)); // in unique_ptr scenario
	pResource = make_shared<Resource>(resourcename);
}