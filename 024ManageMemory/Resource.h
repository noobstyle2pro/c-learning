#pragma once
#include <string>

class Resource
{
public:
	Resource(std::string n);
	Resource(const Resource& r); // copy resource to make one resource from another
	Resource& operator=(const Resource& r); // copy assignment operator to set the values of one resource to another
	~Resource(void);
	std::string GetName() const { return name; }

private:
	std::string name;
};