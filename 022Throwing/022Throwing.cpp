// 022Throwing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include "Person.h"
#include "Noise.h"

using namespace std;

int main()
{
	Noise n1("beep 1"); // this lifetime is longer because it is not in the scope of the try
	try
	{
		vector<int> v;
		Noise n2("bloop 2"); // this will destructer when out of the try scope
		v.push_back(1);
		Person William("William", "Tansil", 0); // example for throw exception
		int j = v.at(99); // access element number 99
	}
	catch (out_of_range& e)
	{
		cout << "out of range exception " << e.what() << endl;
	}
	catch (exception& e) // the usage fo reference is to prevent the slicing and missiong of the information
	{
		cout << e.what() << endl;
	}
    return 0;
}

