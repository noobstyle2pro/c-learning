// 028Algorithms.cpp : The explanation why use the algorithm rather than make it ourself.
//					   & also demo how to switch beetween vector and list

#include "stdafx.h"
#include <vector>
#include <list>
#include <algorithm>
//#include <iostream>

using std::vector;
using std::list;

int main()
{
	//// populating a vector
	//vector<int> v;
	//for (int i = 0; i < 5; i++) { v.push_back(i); } // first way, can cause a silly error like accidently increment it in the body.

	//for (int i = 0; i < 5; ) { v.push_back(i++); }  // if not careful it will not get increment, & it just the loop that we memorize along time ago.
	//												// like mother phone number
	//int i = 0;									
	//std::generate_n(std::back_inserter(v), 5,	// more expressive if know the std lib
	//	[&]() { return i++; }
	//	);

	//// counting the number of 3's
	//int count1 = 0;
	//for (unsigned int i = 0; i < v.size(); i++)
	//{
	//	if (3 == v[i]) { count1++; } // v[i] access vector randomly / to the index
	//}

	//int count2 = 0;
	//for (auto it = begin(v); it != end(v); it++) // iterator can be invalid when we erase it for example
	//{
	//	if (3 == *it) { count2++; }
	//}

	//int count3 = std::count(begin(v), end(v), 3); // more expressive and more readable and also more short code

	//// removing the 3's
	//auto v2 = v;
	//for (unsigned int i = 0; i < v2.size(); i++)
	//{
	//	if (3 == v2[i]) { v2.erase(v2.begin() + i); } // actually it's a bug, do you spot it? in case if 0, 1, 3, 3, ... the 3 in row will only deleted one (because it get skipped when delete & i++)
	//}

	//auto v3 = v;
	//for (auto it = begin(v3); it != end(v3); it++)
	//{
	//	//if (3 == *it) { v3.erase(it); } // it cause the invalid container. container can become invalid when the "index" change
	//	if (3 == *it) { *it = -1; } // the only thing that we can do
	//}

	//auto v4 = v;
	//auto endv4 = std::remove_if(begin(v4), end(v4), // it don't remove the 3 yet, instead it move the thing want to delete to the back
	//	[](int elem) { return 3 == elem; }		    // and then delete it at the last, this is for the perfomance reason
	//	);
	////std::cout << *endv4 << std::endl;
	//v4.erase(endv4, end(v4));

	////v4.erase(std::remove_if(begin(v4), end(v4), [](int elem) { return 3 == elem; }), end(v4)); // almost people will write it in one line.

	// ==========================================
	// switch beetween vector n linked list demo
	// ==========================================

	// copy the code above then paste to below

	// populating a vector
	list<int> v; // only change the type to list, if use algorithm instead of []
	for (int i = 0; i < 5; i++) { v.push_back(i); } // first way, can cause a silly error like accidently increment it in the body.

	for (int i = 0; i < 5; ) { v.push_back(i++); }  // if not careful it will not get increment, & it just the loop that we memorize along time ago.
													// like mother phone number
	int i = 0;
	std::generate_n(std::back_inserter(v), 5,	// more expressive if know the std lib
		[&]() { return i++; }
	);

	// counting the number of 3's
	// can't do random access in linked list
	//int count1 = 0;
	//for (unsigned int i = 0; i < v.size(); i++)
	//{
	//	if (3 == v[i]) { count1++; } // v[i] access vector randomly / to the index
	//}

	int count2 = 0;
	for (auto it = begin(v); it != end(v); it++) // iterator can be invalid when we erase it for example
	{
		if (3 == *it) { count2++; }
	}

	int count3 = std::count(begin(v), end(v), 3); // more expressive and more readable and also more short code

	// removing the 3's
	// this is buggy n can't do random access in linked list
	//auto v2 = v;
	//for (unsigned int i = 0; i < v2.size(); i++)
	//{
	//	if (3 == v2[i]) { v2.erase(v2.begin() + i); } // actually it's a bug, do you spot it? in case if 0, 1, 3, 3, ... the 3 in row will only deleted one (because it get skipped when delete & i++)
	//}

	auto v3 = v;
	for (auto it = begin(v3); it != end(v3); it++)
	{
		//if (3 == *it) { v3.erase(it); } // it cause the invalid container. container can become invalid when the "index" change
		if (3 == *it) { *it = -1; } // the only thing that we can do
	}

	auto v4 = v;
	auto endv4 = std::remove_if(begin(v4), end(v4), // it don't remove the 3 yet, instead it move the thing want to delete to the back
		[](int elem) { return 3 == elem; }		    // and then delete it at the last, this is for the perfomance reason
	);
	//std::cout << *endv4 << std::endl;
	v4.erase(endv4, end(v4));

	//v4.erase(std::remove_if(begin(v4), end(v4), [](int elem) { return 3 == elem; }), end(v4)); // almost people will write it in one line.

    return 0;
}

