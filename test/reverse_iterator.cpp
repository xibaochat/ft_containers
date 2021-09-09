#include "../Vector.hpp"

void	reverse_iterator_incrementers()
{
	ft::Vector<int>				vec;
	ft::Vector<int>::reverse_iterator	it;
	ft::Vector<int>::const_reverse_iterator	c_it;
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
	c_it = vec.rbegin();
	it = vec.rbegin();

	std::cout << "it = vec.rend();" << std::endl;
	std::cout << "*it = " << *it << "     |   const_reverse_it *c_it = " << *c_it<<  std::endl;
	std::cout << "*(it++) = " << *(it++) << " |   const_reverse_it *(c_it++) = " << *(c_it++) << std::endl;
	std::cout << "*it = " << *it << "      |   const_reverse_it *c_it =" << *c_it << std::endl;
	std::cout << "*(it--) = " << *(it--) << "  |   const_reverse_it *(c_it--) =" << *(c_it--) << std::endl;
	std::cout << "*it = " << *it << "     |   const_reverse_it *c_it =" << *c_it << std::endl;
	std::cout << "*(++it) = " << *(++it) << "  |   const_reverse_it *(++c_it) =" << *(++c_it) << std::endl;
	std::cout << "*it = " << *it << "      |   const_reverse_it *c_it =" << *c_it << std::endl;
	std::cout << "*(--it) = " << *(--it) << " |   const_reverse_it *(--c_it) =" << *(--c_it) << std::endl;
	std::cout << "*it = " << *it << "     |   const_reverse_it *c_it =" << *c_it << std::endl << std::endl;
}

void stl_reverse_iterator_incrementers()
{
	std::vector<int>				vec;
	std::vector<int>::const_reverse_iterator	c_it;
	std::vector<int>::reverse_iterator          it;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(42);

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << BLUE << "Test std::vector i++ | ++i | --i | i-- :" << NC << std::endl;
	c_it = vec.rbegin();
	it = vec.rbegin();

	std::cout << "it = vec.rend();" << std::endl;
	std::cout << "*it = " << *it << "     |   const_reverse_it *c_it = " << *c_it<<  std::endl;
	std::cout << "*(it++) = " << *(it++) << " |   const_reverse_it *(c_it++) = " << *(c_it++) << std::endl;
	std::cout << "*it = " << *it << "      |   const_reverse_it *c_it =" << *c_it << std::endl;
	std::cout << "*(it--) = " << *(it--) << "  |   const_reverse_it *(c_it--) =" << *(c_it--) << std::endl;
	std::cout << "*it = " << *it << "     |   const_reverse_it *c_it =" << *c_it << std::endl;
	std::cout << "*(++it) = " << *(++it) << "  |   const_reverse_it *(++c_it) =" << *(++c_it) << std::endl;
	std::cout << "*it = " << *it << "      |   const_reverse_it *c_it =" << *c_it << std::endl;
	std::cout << "*(--it) = " << *(--it) << " |   const_reverse_it *(--c_it) =" << *(--c_it) << std::endl;
	std::cout << "*it = " << *it << "     |   const_reverse_it *c_it =" << *c_it << std::endl << std::endl;
}

void reverse_iterator_arithmetics()
{
	std::cout << std::endl;
	std::cout << BLUE << "Test reverse_iterator  i + | i - | i += | i -= | []:" << NC << std::endl;
	ft::Vector<char>				            v;
	ft::Vector<char>::const_reverse_iterator	c_it;
	ft::Vector<char>::reverse_iterator	        it;

	v.push_back('a');
	v.push_back('b');
	v.push_back('c');
	v.push_back('d');
	v.push_back('e');
	v.push_back('f');
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	it = v.rbegin();
	c_it = it;
	std::cout << "*it = " << *it << "       |   const_reverse_it *c_it = " << *c_it << std::endl;
	std::cout << "*(it + 2) = " << *(it+2) << " |   const_reverse_it *(c_it + 2) = " << *(c_it + 2) << std::endl;
	std::cout << "*(it += 3) " << *(it+=3) << "  |   const_reverse_it *(c_it += 3) " << *(c_it += 3) << std::endl;
	std::cout << "*it = " << *it << "       |   const_reverse_it *c_it = " << *c_it << std::endl;
	std::cout << "*(it - 1) = " << *(it-1) << " |   const_reverse_it *(c_it - 1) = " << *(c_it - 1) << std::endl;
	std::cout << "*(it -=2) " << *(it -= 2) << " |   const_reverse_it *(c_it -= 1) = " << *(c_it -= 2) << std::endl;
	it = v.rbegin();
	std::cout << "it[3] = " << it[3] << std::endl;
	std::cout << "it[1] = " << it[1] << std::endl;

}

void stl_reverse_iterator_arithmetics()
{
	std::cout << std::endl;
	std::cout << BLUE << "Test reverse_iterator  i + | i - | i += | i -= | []: " << NC << std::endl;
	std::vector<char>				            v;
	std::vector<char>::const_reverse_iterator	c_it;
	std::vector<char>::reverse_iterator	        it;


	v.push_back('a');
	v.push_back('b');
	v.push_back('c');
	v.push_back('d');
	v.push_back('e');
	v.push_back('f');
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	it = v.rbegin();

	c_it = it;
	std::cout << "*it = " << *it << "       |   const_reverse_it *c_it = " << *c_it << std::endl;
	std::cout << "*(it + 2) = " << *(it+2) << " |   const_reverse_it *(c_it + 2) = " << *(c_it + 2) << std::endl;
	std::cout << "*(it += 3) " << *(it+=3) << "  |   const_reverse_it *(c_it += 3) " << *(c_it += 3) << std::endl;
	std::cout << "*it = " << *it << "       |   const_reverse_it *c_it = " << *c_it << std::endl;
	std::cout << "*(it - 1) = " << *(it-1) << " |   const_reverse_it *(c_it - 1) = " << *(c_it - 1) << std::endl;
	std::cout << "*(it -=2) " << *(it -= 2) << " |   const_reverse_it *(c_it -= 1) = " << *(c_it -= 2) << std::endl;
	it = v.rbegin();
	std::cout << "it[3] = " << it[3] << std::endl;
	std::cout << "it[1] = " << it[1] << std::endl;
}

void reverse_iterator_bool_test()
{
	ft::Vector<int>             vec;
	ft::Vector<int>::reverse_iterator   it, tmp;
	ft::Vector<int>::const_reverse_iterator   c_it;
	std::cout << BLUE << "Test reverse_iterator bool == | != | < | <= | > | >=" << NC << std::endl;
	vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(42);
    it = vec.rbegin();
	tmp = vec.rend();
    c_it = it;
	std::cout << "it==c_it ? " << std::boolalpha << (it==c_it) << std::endl;
	c_it++;
	std::cout << "c_it++" << std::endl;
	std::cout << "it==c_it ? " << std::boolalpha << (it==c_it) << std::endl;
	std::cout << "it!=c_it ? " << std::boolalpha << (it!=c_it) << std::endl;
	std::cout << "it < c_it ? " << std::boolalpha << (it < c_it) << std::endl;
	std::cout << "it <= c_it ? " << std::boolalpha << (it <= c_it) << std::endl;
	std::cout << "c_it <= it ? " << std::boolalpha << (c_it <= it) << std::endl;
	std::cout << "c_it > it ? " << std::boolalpha << (c_it > it) << std::endl;
	std::cout << "it > c_it ? " << std::boolalpha << (it > c_it) << std::endl;
	std::cout << "c_it >= it ? " << std::boolalpha << (c_it >= it) << std::endl;
	std::cout << "it >= c_it ? " << std::boolalpha << (it >= c_it) << std::endl;
	std::cout <<"*(2 + it): " << *(2 + it) << std::endl;
	std::cout << "c_it - vec.rend() distance " << c_it - tmp << std::endl;
	ft::Vector<int>::reverse_iterator   test_it(it);
	ft::Vector<int>::const_reverse_iterator   test_it2 = it;
	std::cout << "test_it==c_it ? " << std::boolalpha << (test_it==c_it) << std::endl;
	std::cout << "test_it2==c_it ? " << std::boolalpha << (test_it2==c_it) << std::endl;
	std::cout << "test_it==test_it2 ? " << std::boolalpha << (test_it==test_it2) << std::endl;
	std::cout << "test_it<test_it2 ? " << std::boolalpha << (test_it<test_it2) << std::endl;
	std::cout << "test_it<=test_it2 ? " << std::boolalpha << (test_it<=test_it2) << std::endl;
	std::cout << "test_it>=test_it2 ? " << std::boolalpha << (test_it>=test_it2) << std::endl;
	std::cout << "test_it>(test_it2 + 2) ? " << std::boolalpha << (test_it>=test_it2 + 2) << std::endl;
	std::cout << "(test_it+2)>(test_it2 + 2) ? " << std::boolalpha << ((test_it+2)>=(test_it2 + 2)) << std::endl;
	std::cout << "*it == *c_it ? " << std::boolalpha << (*it == *c_it) << std::endl;
}

void stl_reverse_iterator_bool_test()
{
	std::vector<int>             vec;
	std::vector<int>::reverse_iterator   it, tmp;
	std::vector<int>::const_reverse_iterator   c_it;
	std::cout << BLUE << "Test reverse_iterator bool == | != | < | <= | > | >=" << NC << std::endl;
	vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(42);
    it = vec.rbegin();
	tmp = vec.rend();
    c_it = it;
	std::cout << "it==c_it ? " << std::boolalpha << (it==c_it) << std::endl;
	c_it++;
	std::cout << "c_it++" << std::endl;
	std::cout << "it==c_it ? " << std::boolalpha << (it==c_it) << std::endl;
	std::cout << "it!=c_it ? " << std::boolalpha << (it!=c_it) << std::endl;
	std::cout << "it < c_it ? " << std::boolalpha << (it < c_it) << std::endl;
	std::cout << "it <= c_it ? " << std::boolalpha << (it <= c_it) << std::endl;
	std::cout << "c_it <= it ? " << std::boolalpha << (c_it <= it) << std::endl;
	std::cout << "c_it > it ? " << std::boolalpha << (c_it > it) << std::endl;
	std::cout << "it > c_it ? " << std::boolalpha << (it > c_it) << std::endl;
	std::cout << "c_it >= it ? " << std::boolalpha << (c_it >= it) << std::endl;
	std::cout << "it >= c_it ? " << std::boolalpha << (it >= c_it) << std::endl;
	std::cout <<"*(2 + it): " << *(2 + it) << std::endl;
	std::cout << "c_it - vec.rend() distance " << c_it - tmp << std::endl;
	std::vector<int>::reverse_iterator   test_it(it);
	std::cout << "test_it==c_it ? " << std::boolalpha << (test_it==c_it) << std::endl;
	std::vector<int>::const_reverse_iterator   test_it2 = it;
	std::cout << "test_it2==c_it ? " << std::boolalpha << (test_it2==c_it) << std::endl;
	std::cout << "test_it==test_it2 ? " << std::boolalpha << (test_it==test_it2) << std::endl;
	std::cout << "test_it<test_it2 ? " << std::boolalpha << (test_it<test_it2) << std::endl;
	std::cout << "test_it<=test_it2 ? " << std::boolalpha << (test_it<=test_it2) << std::endl;
	std::cout << "test_it>=test_it2 ? " << std::boolalpha << (test_it>=test_it2) << std::endl;
	std::cout << "test_it>(test_it2 + 2) ? " << std::boolalpha << (test_it>=test_it2 + 2) << std::endl;
	std::cout << "(test_it+2)>(test_it2 + 2) ? " << std::boolalpha << ((test_it+2)>=(test_it2 + 2)) << std::endl;
	std::cout << "*it == *c_it ? " << std::boolalpha << (*it == *c_it) << std::endl;
}
