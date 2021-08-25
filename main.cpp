#include "Vector.hpp"

int main()
{
	ft::Vector<int> first(1);
	int foo [5] = { 16, 2, 77, 40, 12071 };
	int bar [5] = { 42, 888};

	ft::VectorIterator<int> iter(foo);
	ft::VectorIterator<int> iter1(bar);
	ft::VectorIterator<int> it = iter;
	for (iter=foo; iter != foo+5; iter++)
		std::cout << *iter << std::endl;
	iter = foo;
	if (iter==iter1)
		std::cout << "equel\n";
	else
		std::cout << "no equel\n";
	iter1 = iter;
	if (iter!=iter1)
		std::cout << "not equel\n";
	else
		std::cout << "equel\n";
	iter+=3;
	std::cout << *iter << std::endl;
	iter-=1;
	std::cout << *iter << std::endl;
	std::cout << iter - it << std::endl;
	iter = foo;
	std::cout << "[]" << std::endl;
	for(int i=0;i <= 4; i++)
		std::cout << iter[i] << std::endl;
}
