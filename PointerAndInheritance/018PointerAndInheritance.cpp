// 018PointerAndInheritance.cpp : Polymophic & Slicing Implementation Example.
//

#include "stdafx.h"
#include "Person.h"
#include "Tweeter.h"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
	Person* William = new Person("William", "Tansil", 123);
	Tweeter* WilliamTansil = new Tweeter("William", "Tansil",23455,"@wt");

	Person* pWilliamTansil = WilliamTansil;

	cout << William->GetName() << endl;
	cout << WilliamTansil->GetName() << endl;
	cout << pWilliamTansil->GetName() << endl;

	delete WilliamTansil;

	// auto can detect the type automaticly
	//auto spWilliam = make_shared<Person>("SWilliam", "PTansil", 126);
	// another way to declaring & initialing the shared ptr
	//shared_ptr<Person> spWilliam(new Person("William", "Tansil", 123));
	// polymorphic example
	// the reason to store the base class in the derived and vice versa with the ptr is to handle the missing thing issue
	shared_ptr<Person> spWilliam = make_shared<Tweeter>("SWilliam", "PTansil", 126,"@spwt"); // GetName() can called in many form
	cout << spWilliam->GetName() << endl;

	Person localP("Local", "Person", 333);
	//Tweeter localT = localP;

	Tweeter localT2("Local", "Tweeter", 444, "@local");
	Person& localP2 = localT2;
	cout << localP2.GetName();
	// another way
	//Person *localP2 = &localT2;
	//cout << localP2->GetName();

    return 0;
}

