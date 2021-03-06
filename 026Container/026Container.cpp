// 026Container.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Resource.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
	try
	{
		Resource r("local");
		cout << "----------------------------" << endl;
		vector<Resource> resources; // use vector to handle memory leak issue and for the fixed size issue
		resources.push_back(r);
		cout << "----------------------------" << endl;
		resources.push_back(Resource("first"));
		cout << "----------------------------" << endl;
		throw (std::bad_exception()); // if throw without catch it will go out the windows immediately
		resources.push_back(Resource("second"));
		cout << "----------------------------" << endl;
		resources.push_back(Resource("third"));
		cout << "----------------------------" << endl;
	}
	catch (std::exception& ex) // to prevent memory leak when throw execute.
	{						   // and also for longer the app lifetime
		// all will be destructed
	}

    return 0;
}

