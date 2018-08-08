#pragma once
#include <string>

class Resource
{
public:
	Resource(std::string n);
	~Resource(void);
	virtual std::string GetName() const { return name; }

private:
	std::string name;
};