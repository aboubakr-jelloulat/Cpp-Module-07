#pragma once
#include <iostream>

template<typename T>
class Array
{
	unsigned int 	_n;
	T				*_arr;

public:
	Array();
	Array(const unsigned int &n);
	Array(const Array &src);
	Array &operator=(const Array &src);
	virtual ~Array();


	unsigned int size() const;


	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;

};

#include "Array.tpp"
/*
	Because C++ templates must have their full implementation visible at the point where they are used
		otherwise the compiler cannot generate code.
*/