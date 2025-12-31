#pragma once

#include <iostream>

template <typename T>
void	iter(T *arr, const size_t &n, void (*foo)(T &))
{
	#if DEBUG 
		std::cout << "\n.........NoN-Const .........\n" << std::endl;
	#endif

	for (size_t i = 0; i < n; ++i)
		foo(arr[i]);
}


template <typename T>
void	iter(T *arr, const size_t &n, void (*foo)(T const &))
{
	#if DEBUG 
		std::cout << "\n......... Const .........\n" << std::endl;
	#endif

	for (size_t i = 0; i < n; ++i)
		foo(arr[i]);
}



// template <typename T, typename func>
// void	iter(T *arr, const size_t &n, func f)
// {
// 	for (size_t i = 0; i < n; ++i)
// 		f(arr[i]);
// }


// iter(arr, 4, _print<int>);
