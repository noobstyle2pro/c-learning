// 014PointerAndReference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
	int a = 3;
	cout << "a is " << a << endl;
	int *pA = &a;
	*pA = 4;
	cout << "a is " << a << endl;
	int b = 100;
	pA = &b;
	(*pA)++;
	cout << "a " << a << ", *pA " << *pA << endl;

	Person William("William", "Tansil", 123);
	Person* pWilliam = &William;
	(*pWilliam).SetNumber(456);
	cout << "Kate: " << William.GetName() << " " << William.GetNumber() << endl;
	cout << "pKate: " << pWilliam->GetName() << " " << pWilliam->GetNumber() << endl;

	// Reference Example
	int& rA = a;
	rA = 5;
	cout << "a is " << a << endl;

	Person& rWilliam = William;
	rWilliam.SetNumber(789);
	cout << "rKate: " << rWilliam.GetName() << " " << rWilliam.GetNumber() << endl;

	/*int* badPointer;
	*badPointer = 3;
	cout << *badPointer << endl;*/
	// to fix this
	int* badPointer = nullptr;
	if (badPointer) // to test
	{
		*badPointer = 3;
		cout << "*badPointer" << *badPointer << endl;
	}

	/*int& badReference;		
	badReference = 3;				
	cout << badReference << endl;*/

    return 0;
}

