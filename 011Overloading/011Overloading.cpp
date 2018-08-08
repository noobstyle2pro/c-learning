// 011Overloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Person p1("William", "Tansil", 123);
	Person p2("Kate", "Gregory", 456);
	
	cout << "p1 is ";
	if (!(p1 < p2)) { cout << "not "; }
	cout << "less than p2" << endl;

	cout << "p1 is ";
	if (!(p1 < 300)) { cout << "not "; }
	cout << "less than 300" << endl;

	cout << "300 is ";
	if (!(300 < p1)) { cout << "not "; }
	cout << "less than p1" << endl;

    return 0;
}