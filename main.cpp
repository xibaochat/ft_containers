#include "Vector.hpp"

int main()
{
	ft::Vector<int> first;
	std::vector<int> scd;
	int foo [5] = { 1, 2, 77, 40, 12071 };
	int bar [5] = { 42, 888};

	std::cout << "start\n";
	first._arr = foo;
	std::cout << "start 1\n";
	first.insert(foo, 1, 10);
	std::cout << "start2\n";


}
