// 019Casting.cpp : Casting Implamantation Example.
//

#include "stdafx.h"
#include "Person.h"
#include "Tweeter.h"
#include "Resource.h"
#include <iostream>

using namespace std;

int main()
{
	Tweeter t("William", "Tansil", 123, "@wt");
	Person* p = &t;
	//Tweeter* pt = (Tweeter*)p; // not a good pratice & can hurt
	// to fix this, use template static_cast<typename>(identifier)
	// instead of (typename)identifier cast
	Tweeter* pt = static_cast<Tweeter*>(p);
	cout << pt->GetName() << endl;

	// compiler dont tell there is something not good at the commented line
	// because this way tell the compiler that I know what I'm doing
	// so compiler proceed even it will end up boom
	//int i = 3;
	//Tweeter* pi = (Tweeter*)&i; // this will end bad
	//Tweeter* pi = static_cast<Tweeter*>(&i); // this is safer to do
	Resource f("local");
	Tweeter* pi = dynamic_cast<Tweeter*>(&f); // it will complain or crash in the run time
	if (pi) { cout << pi->GetName() << endl; } // so this need to check so it won't blow up
	else { cout << "resource can't be cast to tweeter" << endl; } // and this (if nullptr) is the good practice so it can tell what was wrong

    return 0;
}

