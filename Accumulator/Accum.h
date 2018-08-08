#pragma once
template <class T>
class Accum
{
public:
	Accum(T start) : total(start) {};
	T operator+=(const T& t) { return total = total + t; } // create overload for += operator
	T GetTotal() { return total; }

private:
	T total;
};

// Template Specialization Example
template <>
class Accum<Person> // This template will handle Person type
{
public:
	Accum(int start) : total(start) {};
	int operator+=(Person& t) { return total = total + t.GetNumber(); } // create overload for += operator
	int GetTotal() { return total; }

private:
	int total;
};