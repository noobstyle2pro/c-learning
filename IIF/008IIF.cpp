// 008IIF.cpp : Simple Implementation of Immediate IF.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x = 99;

	while (x > 0)
	{
		cout << "Enter a number, below 1 to quit" << endl;
		cin >> x;
		string sign = x > 0 ? "positive" : "0 or negative";
		cout << "your number is " << sign << endl;
	}

    return 0;
}

