// 020Collection.cpp : Implemention of vector, map from std lib example.
//

#include "stdafx.h"
#include "Person.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

void print(int i) { std::cout << i << " "; }

bool odd(int i) { return i % 2; }

int main()
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(6);
	v.push_back(9);
	v.push_back(2);

	for (auto i = v.begin(); i != v.end(); i++) { std::cout << *i << " "; } // auto is declare the type latter

	std::cout << std::endl;

	for (auto i = v.rbegin(); i != v.rend(); i++) { std::cout << *i << " "; }

	std::cout << std::endl;

	int j = v[2];

	std::cout << j << std::endl;

	std::vector<Person> vp;
	Person William("William", "Tansil", 123);
	Person Kate("Kate", "Gregory", 234);

	vp.push_back(William);
	vp.push_back(Kate);

	for (auto ip = vp.begin(); ip < vp.end(); ip++) { std::cout << ip->GetName() << " "; } // another way to do is (*ip).GetName()
	
	std::cout << std::endl << "------------------------" << std::endl; // course separator

	std::map<int, Person> people;
	people[William.GetNumber()] = William;
	people[Kate.GetNumber()] = Kate;

	//this is the long way to do the same thing like above
	Person third("Third", "Person", 124);
	std::pair<int, Person> p(third.GetNumber(), third);
	people.insert(p);

	for (auto ip = people.begin(); ip != people.end(); ip++)
	{
		std::cout << ip->first << " " << ip->second.GetName() << ". ";
	} // int map it is pair so it have the first content (key) & second (value)

	std::cout << std::endl;

	auto found = people.find(123); // the auto type is iterator
	std::cout << found->first << " " << found->second.GetName() << ". ";

	// this another way to find the people inside
	std::string who = people[124].GetName();
	std::cout << "person at 124 is " << who << std::endl;

	std::cout << std::endl << "------------------------" << std::endl; // course separator

	std::cout << "contents of v: ";
	std::for_each(v.begin(), v.end(), print); // the begin itarator, the n iterator, what to do (this function actually a function pointer)

	std::cout << std::endl;

	std::cout << "odd elements of v: ";
	auto o = std::find_if(v.begin(), v.end(), odd); // if didn't find anything it will return the same iterator as v.end()
	while (o != v.end()) // so if nothing more than don't go throught the loop
	{
		std::cout << *o << " ";
		o = find_if(++o, v.end(), odd); // find the next one from increment of the current position
	}

	std::cout << "contents of v: ";
	std::sort(v.begin(), v.end()); // the vector change permanently. copy to new and delete the old one
	std::for_each(v.begin(), v.end(), print);
	
	std::cout << std::endl << "------------------------" << std::endl; // course separator

	int length = third.GetName().size();
	std::string firstfour = third.GetName().substr(0, 4);
	std::cout << length << " " << third.GetName();

	std::cout << std::endl;

    return 0;
}

