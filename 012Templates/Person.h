#pragma once
#include <string>

class Person
{
public:
	Person(std::string first,
		std::string last,
		int arbitrary);
	~Person(void);
	std::string GetName();
	int GetNumber() { return arbitraryNumber; }
	void SetNumber(int number) { arbitraryNumber = number; }
	bool operator<(Person& p);
	bool operator<(int i);
	friend bool operator<(int i, Person& p); // give previlege, so it can access 
											 // the private member instead of
private:									 // use GetName(), etc...
	std::string firstname;
	std::string lastname;
	int arbitraryNumber;
};
bool operator<(int i, Person& p);