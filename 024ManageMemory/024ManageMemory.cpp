// 024ManageMemory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.h"

using std::string;

int main()
{
	Person William("William", "Tansil", 123);
	William.SetResource("William Resource");
	William.SetResource("William Second Resource");
	// this 2 lines usage of unique_ptr not allow the default copy feature
	Person William2 = William; // copy constructing William Second Resource
	William = William2; // copy assignment William Second Resource without destructing it
						// because the resource is reference so it will not too wasteful
	string s1 = William.GetResourceName();

    return 0;
}