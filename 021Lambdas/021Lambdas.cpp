// 021Lambdas.cpp : Simple Implementation of Lambdas.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; ++i) { v.push_back(i); }

	std::for_each(v.begin(), v.end(), [](int n) {cout << n << " "; });
	cout << endl;

	cout << endl << "-----------------------" << endl;

	std::for_each(v.begin(),						// this lambda version is 
				  v.end(),							// more easy to debug
				  [](int n)
					{
						cout << n << " ";
					}
				);
	cout << endl;

	cout << endl << "-----------------------" << endl;

	std::for_each(v.begin(), v.end(), [](int n) {
		cout << n;
		if (n % 2 == 0) { cout << " even " << endl; }
		else { cout << " odd " << endl; }
	});
	cout << endl;

	cout << endl << "-----------------------" << endl;

	std::vector<int> v2;
	std::transform(v.begin(), v.end(), std::back_inserter(v2), [](int n) {return n * n * n; });
	std::for_each(v2.begin(), v2.end(), [](int n) { cout << n << " "; });
	// another way to print it out
	//for (auto n : v2) { cout << n << " "; }
	cout << endl;

	cout << endl << "-----------------------" << endl;

	std::vector<double> dv;
	std::transform(v.begin(), v.end(), std::back_inserter(dv), [](int n) -> double { // specify the return type
		if (n * 2 == 0) { return n * n * n; }	// transform() is for transform element to another output, back_inserter() is to insert element from back of a container
		else { return n / 2.0; }				// some container have front_inserter()
	});
	std::for_each(dv.begin(), dv.end(), [](double x) { cout << x << " "; });
	// another way to print it out
	//for (auto x : dv) { cout << x << " "; }
	cout << endl;

	cout << endl << "-----------------------" << endl;

	int x = 3;
	int y = 7;
	cout << "printing elements between " << x << " and " << y << " inclusive" << endl;
	for_each(v.begin(), v.end(), [x, y](int n) {
		if (n >= x && n <= y) { cout << n << " "; }
	});
	cout << endl;
	std::for_each(v.begin(), v.end(), [](int n) { cout << n << " "; }); // the v still doesn't change
	cout << endl;

	cout << endl << "-----------------------" << endl;

	x = 2;
	y = 9;
	cout << "printing elements between " << x << " and " << y << " inclusive" << endl;
	for_each(v.begin(), v.end(), [=](int n) {
		if (n >= x && n <= y) { cout << n << " "; }
	});
	cout << endl;
	std::for_each(v.begin(), v.end(), [](int n) { cout << n << " "; }); // the v still doesn't change
	cout << endl;

	cout << endl << "-----------------------" << endl;

	x = 1;
	y = 1;
	for_each(v.begin(), v.end(), [=](int& r) mutable { // by default everything captured is const
		const int old = r;							   // by say mutable its tell compiler you want
		r *= 2;										   // to the captured will be able to be modified
		x = y;		// this line will compile because there is a mutable keyword
		y = old;	// x & y doesn't change because this is capture by value [=] and lambda only change the local copy of x & y
	});

	cout << "doubling " << endl;
	std::for_each(v.begin(), v.end(), [](int n) { cout << n << " "; }); // the v still doesn't change
	cout << endl;
	cout << "x,y: " << x << ", " << y << endl;

	cout << endl << "-----------------------" << endl;

	v.clear(); // empty the vector v
	for (int i = 0; i < 10; i++) { v.push_back(i); }
	std::for_each(v.begin(), v.end(), [&x, &y](int& r) { // capturing by reference
		const int old = r;
		r *= 2;
		x = y;
		y = old;
	});

	cout << "doubling & changing " << endl;
	std::for_each(v.begin(), v.end(), [](int n) { cout << n << " "; }); // the v still doesn't change
	cout << endl;
	cout << "x,y: " << x << ", " << y << endl;

	cout << endl << "-----------------------" << endl;

	v.clear(); // empty the vector v
	int i = 0;
	std::generate_n(std::back_inserter(v), 10, [&] { return i++; }); // capture everything in scope by reference
	cout << "initializing" << endl;
	std::for_each(v.begin(), v.end(), [](int n) { cout << n << " "; });
	cout << endl;
	cout << "i: " << i << endl;

	cout << endl << "-----------------------" << endl;

    return 0;
}