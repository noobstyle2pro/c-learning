// 002ClassesAndObjects.cpp : Implement object .
//

#include "stdafx.h"
#include "Person.h"
#include "Tweeter.h"
//#include "Status.h" struct
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, _TCHAR* argv[])
{
	Person p1("William", "Tansil", 123); 
	{
		Tweeter t1("Kate", "Gregory", 234, "@kate_gregory"); // in scope
	}
	cout << "after innermost block" << endl;
	cout << "p1: " << p1.GetName() << " " << p1.GetNumber() << endl;
	p1.SetNumber(124);
	cout << "p1: " << p1.GetName() << " " << p1.GetNumber() << endl;

	// struct
	/*Status s = Pending;
	s = Approved;*/

    return 0;
}