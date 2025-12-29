#include "Array.h"

template <typename T>
Array<T>::Array() : _n(0), _arr(NULL)
{
}


template <typename T>
Array<T>::Array(const unsigned int &n) : _n(n), _arr(new T[n])
{
}

template <typename T>
Array<T>::Array(const Array &src) : _n(src.size()), _arr(new T[src.size()])
{
	for (unsigned int i = 0; i < src.size(); i++)
		_arr[i] = src[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
	std::cout << "this address :  " << this << std::endl;
	std::cout << "&src address :  " << src << std::endl;
	if (this == &src)
		return *this;

	if (_arr)
		delete[] _arr;

	_n = src.size();

	_arr = new T[src.size()];

	for (unsigned int i = 0; i < src.size(); i++)
		_arr[i] = src[i];

	return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _n;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	#ifdef DEBUG
		std::cout << "Hej im non const" << std::endl;
	#endif

	if (i >= _n)
		throw std::out_of_range("Index out of bounds");
	return _arr[i];
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	#ifdef DEBUG
		std::cout << "Hej im const !!!!!!" << std::endl;
	#endif

	if (i >= _n)
		throw std::out_of_range("Index out of bounds");
	return _arr[i];
}


template <typename T>
Array<T>::~Array()
{
}