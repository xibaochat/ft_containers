#include "../Vector.hpp"

void	reverse_iterator_incrementers()
{
	ft::Vector<int>				vec;
	ft::Vector<int>::const_reverse_iterator	it;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(42);

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << BLUE << "Test ft::vector i++ | ++i | --i | i-- :" << NC << std::endl;
	it = vec.rbegin();
	std::cout << "it = vec.rend();" << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it++) = " << *(it++) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it--) = " << *(it--) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(++it) = " << *(++it) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(--it) = " << *(--it) << std::endl;
	std::cout << "*it = " << *it << std::endl << std::endl;

}

void stl_reverse_iterator_incrementers()
{
	std::vector<int>				vec;
	std::vector<int>::reverse_iterator	it;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(42);

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << BLUE << "Test ft::vector i++ | ++i | --i | i-- :" << NC << std::endl;
	it = vec.rbegin();
	std::cout << "it = vec.rend();" << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it++) = " << *(it++) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(it--) = " << *(it--) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(++it) = " << *(++it) << std::endl;
	std::cout << "*it = " << *it << std::endl;
	std::cout << "*(--it) = " << *(--it) << std::endl;
	std::cout << "*it = " << *it << std::endl << std::endl;
}

// void reverse_iterator_arithmetics()
// {
// 	std::cout << std::endl;
// 	std::cout << BLUE << "Test reverse_iterator  i + | i - | i += | i -= :" << NC << std::endl;
// 	ft::Vector<char>				vec;
// 	ft::Vector<char>::const_reverse_iterator	it;

// 	vec.push_back('a');
// 	vec.push_back('b');
// 	vec.push_back('c');
// 	vec.push_back('d');
// 	vec.push_back('e');
// 	vec.push_back('f');
// //	it = vec.rbegin();
// }
