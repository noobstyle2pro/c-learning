// 010Comparison.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Utility.h" // Include To Project from Project 007Function

using namespace std;

//int foo(string s);
//int something();

int main()
{
	int i = 2;
	if (i == 3) { cout << "i is 3" << endl; }
	cout << "i " << i << endl;
	if (i = 3) { cout << "i is 3" << endl; } // Mistake example
	cout << "i " << i << endl;
	i = 4;
	if (3 == i) { cout << "i is 3" << endl; }
	cout << "i " << i << endl;

	// example to make comparison to result as well as assigning
	// in the most cpp way
	/*int p;
	if (p = foo("whatever")) { something(); }*/

	cout << "enter a number " << endl;
	cin >> i;

	cout << i << " is ";
	if (!IsPrime(i)) { cout << "not "; }
	cout << "prime." << endl;

	int j;
	cout << "enter a second number " << endl;
	cin >> j;

	cout << i << " is ";
	if (j && (i % j)) { cout << "not "; }
	cout << "a multiple of " << j << endl;

    return 0;
}

