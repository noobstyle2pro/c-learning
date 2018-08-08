#include "stdafx.h"
#include "Resource.h";
#include <iostream>;

using std::cout;
using std::endl;

Resource::Resource(std::string n) : name(n)
{
	cout << "constructing " << name << endl;
}

Resource::Resource(const Resource& r) : name(r.name)
{
	cout << "copy constructing " << name << endl;
}

Resource& Resource::operator=(const Resource& r)
{
	name = r.GetName();
	cout << "copy assigning " << name << endl;
	return *this;
}

Resource::~Resource()
{
	cout << "destructing " << name << endl;
}