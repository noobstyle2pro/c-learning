// 012Max.cpp : Implementation of template function.
//

#include "stdafx.h"
#include <iostream>
#include "Person.h"
//#include "BankAccount.h"

using namespace std;

template <class T>
T max(T& t1, T& t2) { return t1 < t2 ? t2 : t1; }

int F(int& x) { return x; }

int main()
{
	int i, j;
	i = 33;
	j = 44;
	cout << "max of 33 and 44 is " << max(i, j) << endl;

	string s1 = "hello";
	string s2 = "world";
	cout << "max of " << s1 << " and " << s2 <<
		" is " << max(s1, s2) << endl;
	Person p1("William", "Tansil", 123);
	Person p2("Kate", "Gregory", 456);
	cout << "max of " << p1.GetName() << " and " << p2.GetName() <<
		" is " << max(p1, p2).GetName() << endl;

	// Template Error Demo
	// sometime the error can be opaque
	// because it doesn't tell that
	// the error in the template
	/*BankAccount b1;
	BankAccount b2;
	cout << "max of " << b1.GetHolderName() << " and " << b2.GetHolderName() <<
		" is " << max(b1, b2).GetHolderName() << endl;*/ // BankAccount doesn't overload the < operator
													   // for example
    return 0;
}

