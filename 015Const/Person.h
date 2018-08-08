#pragma once
#include <string>

class Person
{
public:
	Person(std::string first,
		std::string last,
		int arbitrary);
	~Person(void);
	std::string GetName() const;
	int GetNumber() const { return arbitraryNumber; }
	void SetNumber(int number) { arbitraryNumber = number; }
	bool operator<(const Person& p) const;
	bool operator<(int i) const;
	friend bool operator<(int i,const  Person& p); // the friend is the free function 
												   // so it can't have a const
private:
	std::string firstname;
	std::string lastname;
	int arbitraryNumber;
};
bool operator<(int i, const Person& p);