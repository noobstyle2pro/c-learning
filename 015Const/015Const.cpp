// 015Const.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.h"

using namespace std;

int DoubleIt(const int& x) { return x * 2; }

int main()
{
	int i = 3;
	const int ci = 3;
	i = 4;
	//ci = 4

	int j = 10;
	int DoubleJ = DoubleIt(j);
	int DoubleTen = DoubleIt(10);

	Person William("William", "Tansil", 123);
	William.SetNumber(234);
	const Person cWilliam = William;
	//cWilliam.SetNumber(346);
	int WilliamNumber = cWilliam.GetNumber();

	int* pI = &i;
	const int* pII = &ci;

	Person* pWilliam = &William;
	Person Kate("Kate", "Gregory", 456);

	const int * pcI = pI; // pointer to a const
	//*pcI = 4;
	pcI = &j;

	int * const cpI = pI; // const pointer
	*cpI = 4;
	//cpI = &j;

	const int * const crazy = pI; // const pointer to a const
	//*crazy = 4;
	//crazy = &j
	int k = *crazy;

    return 0;
}

