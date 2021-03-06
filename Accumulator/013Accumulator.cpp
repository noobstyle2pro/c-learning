// 013Accumulator.cpp : Implementation of template class.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Person.h"
#include "Accum.h"

using namespace std;

int main()
{
	Accum<int> integers(0);
	integers += 3;
	integers += 7;
	cout << integers.GetTotal() << endl;

	Accum<string> strings("");
	strings += "hello";
	strings += " world";
	cout << strings.GetTotal() << endl;

	// Example for template type safety
	/*integers += "testing";
	strings += 4;*/

	Accum<Person> people(0);
	Person p1("William", "Tansil", 123);
	Person p2("Kate", "Gregory", 456);
	people += p1; // this operator overloading has been handle
	people += p2; // in template specialization for person
	cout << people.GetTotal() << endl;

    return 0;
}

