#include "../Vector.hpp"
#include "test.hpp"

void vector_iterator_test()
{
//	iterator_test();
	std::cout << RED << "------------SPLIT LINE-------------" << NC << std::endl;
	real_iterator();
}

void vector_reverse_iterator_test()
{
	// reverse_iterator_incrementers();
	// stl_reverse_iterator_incrementers();
	//reverse_iterator_arithmetics();
	//stl_reverse_iterator_arithmetics();
	reverse_iterator_bool_test();
	stl_reverse_iterator_bool_test();


}
int main()
{
//	vector_iterator_test();
	vector_reverse_iterator_test();


}
