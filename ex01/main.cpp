#include "iter.h"

template<typename T>
void	_print(T const &value)
{
	std::cout << value << " ";
}

void	_increment(int &index)
{
	++index;
}

void	_int()
{
	int arr[] = {1, 2, 3, 4};

	std::cout << "elements :  ";
	iter(arr, 4, _print);

	std::cout << "\nincrement :" << std::endl;
	iter(arr, 4, _increment);

	std::cout << "elements :  ";
	iter(arr, 4, _print);

}



void	_to_upper(char &c)
{
	c = toupper(c);
}

void	_str()
{
	std::string str = "Hej! grooking comunity";
	// iter(str.c_str(), 21, _print); // return const cahr so our tmp must be take const char *arr
	std::cout << "str  : ";
	iter(&str[0], 21, _print);

	std::cout << "\nto_upper: " << std::endl;;
	iter(&str[0], 21, _to_upper);

	std::cout << "str  : ";
	iter(&str[0], 21, _print);
}




int main(void)
{
	::_int();

	std::cout << "\n\n* * str * * \n\n";

	::_str();

	return 0;
}
