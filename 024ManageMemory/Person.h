#pragma once
#include "Resource.h"
#include <memory>
#include <string>

class Person
{
public:
	Person(std::string first,
		std::string last,
		int arbitrary);
	~Person();
	// this scenario is when copy & assign was allowed for unique_ptr
	//Person(const Person&);
	//Person& operator=(const Person&);

	std::string GetName() const;
	int GetNumber() const;
	void SetNumber(int number) { arbitrarynumber = number; }
	void SetFirstName(std::string first) { firstname = first; }
	
	void SetResource(std::string resourcename);
	std::string GetResourceName() const { return pResource->GetName(); }

private:
	std::string firstname;
	std::string lastname;
	int arbitrarynumber;
	//std::unique_ptr<Resource> pResource;
	std::shared_ptr<Resource> pResource;

	// this scenario is when copy & assign was not allowed
	/*Person(const Person&);*/			  // this 2 lines are to diable
	/*Person& operator=(const Person&);*/ // the usage of copy constructor
									  // and copy assignment feature. this used
									  // because old compiler dont give the exact
									  // error that cause by assign unique_ptr
};