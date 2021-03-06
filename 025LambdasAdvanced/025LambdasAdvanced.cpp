// 025LambdasAdvanced.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

int main()
{
	int x = 0;
	int y = 0;
	std::vector<int> v;
	auto print = [&]() { cout << "x: " << x << " y: " << y << endl; }; // this is capture by ref because the x & y is throught the code
	//auto print = [=]() { cout << "x: " << x << " y: " << y << endl; }; // this will capture x & y in the first initialize (x & y above)

	for (int i = 0; i < 5; i++) { v.push_back(i); };

	// all by value
	std::for_each(v.begin(), v.end(), [=] (int element) mutable {
		x += element;
		y += element;
	});

	print();
	x = y = 0;

	// x by value, rest by ref
	std::for_each(v.begin(), v.end(), [&, x](int element) mutable {
		x += element;
		y += element;
	});

	print();
	x = y = 0;

	// x by ref, rest by value
	std::for_each(v.begin(), v.end(), [=, &x](int element) mutable {
		x += element;
		y += element;
	});

	print();
	x = y = 0;

	// all by ref
	std::for_each(v.begin(), v.end(), [&](int element) {
		x += element;
		y += element;
	});

	print();

	std::vector<int> doubledV(v.size());
	int factor = 2;
	std::transform(begin(v), end(v), begin(doubledV),
		[=](int element) { return element * factor; }
	);

    return 0;
}

