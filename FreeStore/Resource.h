#pragma once
#include <string>

class Resource
{
public:
	Resource(std::string n);
	~Resource(void);
	std::string GetName() const { return name; }

private:
	std::string name;
};