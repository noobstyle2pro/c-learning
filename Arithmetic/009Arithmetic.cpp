// 009Arithmetic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Utility.h"

using namespace std;

int main()
{
	int i = 0;

	cout << "i " << i << endl;
	i += 2;
	cout << "i " << i << endl;
	i *= 3;
	cout << "i " << i << endl;
	i -= 2;
	cout << "i " << i << endl;
	i /= 4;
	cout << "i " << i << endl;

	int j = i++;

	cout << "i " << i << ", j " << j << endl;
	j = ++i;
	cout << "i " << i << ", j " << j << endl;
	j = i--;
	cout << "i " << i << ", j " << j << endl;
	j = --i;
	cout << "i " << i << ", j " << j << endl;

	i = 2;
	j = 0;
	
	while (i < 101) { j += IsPrime(i++) ? 1 : 0; }

	cout << "I found " << j << " prime up to 100" << endl; // show how many primes found between 2 & 100

    return 0;
}

