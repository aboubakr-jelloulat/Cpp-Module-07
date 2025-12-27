#pragma once

#include <iostream>

template <typename T>
void	iter(T *arr, const size_t &n, void (*foo)(T &element))
{
	for (size_t i = 0; i < n; ++i)
		foo(arr[i]);
}

template <typename T>
void	iter(T *arr, const size_t &n, void (*foo)(T const &element))
{
	for (size_t i = 0; i < n; ++i)
		foo(arr[i]);
}
/*
    Note on _increment:

    In C++98/07, function templates cannot be passed directly as function pointers
    when calling another function template (like iter) that expects a concrete
    pointer type. This would cause an ambiguity between the const and non-const
    overloads of iter, because the compiler cannot deduce the exact type of the
    function template.

    To avoid this, _increment is implemented as a normal (non-template) function
    with a concrete type (int&). This ensures that iter can correctly select the
    mutable overload and modify the elements. Using a template for _increment
    would cause compilation errors in this context, even though it could work
    in other C++ versions with more advanced template deduction.

    This is a common limitation of C++98 function template pointers.
*/
