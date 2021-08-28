#include "Vector.hpp"
#include "iterator.hpp"
#include "const_iterator.hpp"
#include "Utility.hpp"

int main()
{
	ft::Vector<int> v;
	int foo [5] = { 1, 2, 77, 40, 12071 };
	ft::const_iterator<int> it;
	v._arr = foo;
	it = v.begin();
	std::cout << *it << " " << *v.begin() << "\n";


}
