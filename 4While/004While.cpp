// 004While.cpp : Find out is the number is prime or not use while(){}.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int x;

	cout << "Enter a number" << endl;
	cin >> x;

	bool prime = true;
	int i = 2;

	while (i <= x / i) // (&& prime) can also used too
	{
		int factor = x / i;
		if (factor * i == x)
		{
			cout << "factor found: " << factor << endl;
			prime = false;
			break;
		}
		i = i + 1; // i++; can also used too
	}

	cout << x << " is ";

	if (prime) { cout << "prime" << endl; }
	else { cout << "not prime" << endl; }

    return 0;
}

