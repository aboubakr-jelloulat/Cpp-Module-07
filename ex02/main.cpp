#include "Array.h"
#include <cassert>

template<typename T>
void	display(T const &arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
	try
	{
		std::cout << "arr["<< i << "] = " << arr[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	_out_of_range()
{
	Array<int> arr(3);

	arr[0] = 1337;
	arr[1] = 42;
	arr[2] = 19;

	try
	{
		std::cout << "arr[10] = " << arr[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	_char()
{
	Array<char> str(3);
	
	str[0] = 'H';
	str[1] = 'e';
	str[2] = 'j';
	
	display(str);
}

void	_int()
{
	Array<int> arr(3);

	arr[0] = 1337;
	arr[1] = 42;
	arr[2] = 19;

	assert(arr.size() == 3);
	assert(arr[0] == 1337);
	assert(arr[1] == 42);
	assert(arr[2] == 19);
	
	try
	{
		arr[1337];
	}
	catch(std::exception &ex){ assert(std::string(ex.what())  == "Index out of bounds"); }
	
	display(arr);
}

void	_const()
{
	Array<int> arr(3);

	arr[0] = 1337;
	arr[1] = 42;
	arr[2] = 19;

	const Array<int> data(arr); // cpc

	assert(data.size() == 3);
	// std::cout << "data elements : " << std::endl;
	// display(data);


	const Array<int> arr2 = data; // = op

	// std::cout << "arr2 elements : " << std::endl;
	// display(arr2);

}

int main(void)
{
	// _out_of_range();

	// _char();

	// _int();

	_const();

	system("leaks -q array");
	return 0;
}
