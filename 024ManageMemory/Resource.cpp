#include "stdafx.h"
#include "Resource.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Resource::Resource(string n) : name(n)
{
	cout << "constructing " << name << endl;
}

Resource::Resource(const Resource&r) : name(r.name)
{
	cout << "copy constructing " << name << endl;
}

Resource::~Resource(void)
{
	cout << "destructing " << name << endl;
}

Resource& Resource::operator=(const Resource& r)
{
	// note we assign the value to the existing class
	// so we must check clean the old(existing) value 
	// in this resource before setting the new one
	name = r.name;
	cout << "copy assignment " << name << endl;
	return *this; // copy assignment must return something
}
