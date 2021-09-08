#include "../Vector.hpp"

template<typename T>
void show_ele_in_v(ft::Vector<T> &v, ft::VectorIterator<T> it)
{
	for(it = v.begin(); it < v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void iterator_test()
{
	ft::Vector<int> v;
	ft::Vector<int>::iterator it;

	for(int i = 0; i < 10; i++)
		v.push_back(i);
	it = v.begin();
	std::cout << RED << "[My vector]" << NC << " Before element in vector are:" << std::endl;
	it = v.begin();
	show_ele_in_v(v, it);
	*it = 11;
	std::cout << RED << "[My vector]" << NC << " After assignment element in vector are:" << std::endl;
	show_ele_in_v(v, it);
	std::cout << YELLOW << "Test increment && decrement i++ | ++i | --i | i-- :" << NC << std::endl;

	it = v.begin();
    std::cout << "it = vec.begin();" << std::endl;
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*(it++) = " << *(it++) << std::endl;
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*(it--) = " << *(it--) << std::endl;
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*(++it) = " << *(++it) << std::endl;
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*(--it) = " << *(--it) << std::endl;
    std::cout << "*it = " << *it << std::endl << std::endl;

	std::cout << YELLOW << "Test arithmetics i + | i - | i += | i -= :" << NC << std::endl;
    it = v.begin();
    std::cout << "it = vec.begin();" << std::endl;
    std::cout << "*(it + 0) = " << *(it + 0) << std::endl;
    std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
    std::cout << "*(it + 5) = " << *(it + 5) << std::endl << std::endl;

    it = v.end() - 1;
    std::cout << "it = v.end() - 1;" << std::endl;
    std::cout << "*(it - 0) = " << *(it - 0) << std::endl;
    std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
    std::cout << "*(it - 5) = " << *(it - 5) << std::endl << std::endl;

    std::cout << "(*it += 2) = " << (*it += 2) << std::endl;
    std::cout << "(*it -= 1) = " << (*it -= 1) << std::endl << std::endl;

	std::cout << YELLOW << "Test bool < | > | <= | >= | == | !=" << NC << std::endl;
	ft::Vector<int>::iterator   it_beg = v.begin();
    ft::Vector<int>::iterator   it_end = v.end();

    std::cout << "it_beg = v.begin()"  << std::endl;
    std::cout << "it_end = v.end()"  << std::endl << std::endl;

    std::cout << "it_beg < it_end is " << std::boolalpha << (it_beg < it_end) << std::endl;
    std::cout << "it_end < it_beg is " << std::boolalpha << (it_end < it_beg) << std::endl;
    std::cout << "it_beg > it_end is " << std::boolalpha << (it_beg > it_end) << std::endl;
    std::cout << "it_end > it_beg is " << std::boolalpha << (it_end > it_beg) << std::endl << std::endl;

    std::cout << "it_beg <= it_end is " << std::boolalpha << (it_beg <= it_end) << std::endl;
    std::cout << "it_end <= it_beg is " << std::boolalpha << (it_end <= it_beg) << std::endl;
    std::cout << "it_end <= it_end is " << std::boolalpha << (it_end <= it_end) << std::endl;
    std::cout << "it_beg >= it_end is " << std::boolalpha << (it_beg >= it_end) << std::endl;
    std::cout << "it_end >= it_beg is " << std::boolalpha << (it_end >= it_beg) << std::endl;
    std::cout << "it_end >= it_end is " << std::boolalpha << (it_end >= it_end) << std::endl << std::endl;

    std::cout << "it_beg == it_end is " << std::boolalpha << (it_beg == it_end) << std::endl;
    std::cout << "it_beg == it_beg is " << std::boolalpha << (it_beg == it_beg) << std::endl;
    std::cout << "it_beg != it_end is " << std::boolalpha << (it_beg != it_end) << std::endl;
    std::cout << "it_beg != it_beg is " << std::boolalpha << (it_beg != it_beg) << std::endl << std::endl;

	std::cout << YELLOW << "Test dereference" << NC << std::endl;
	for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
	std::cout << std::endl;
	v[0] = 0;
	for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
	std::cout << std::endl;

}

void real_iterator()
{
	std::vector<int> v;
	std::vector<int>::iterator it;
	for(int i = 0; i < 10; i++)
		v.push_back(i);
	it = v.begin();
	std::cout << BLUE << "[REAL Vector]" << NC << " Before element in vector are:" << std::endl;
	for(it = v.begin(); it < v.end(); it++)
		std::cout << *it << " " ;
	it = v.begin();
	*it = 11;
	std::cout << BLUE << "\n[REAL Vector]" << NC << "After assignment element in vector are:" << std::endl;
	for(it = v.begin(); it < v.end(); it++)
	 	std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << YELLOW << "Test increment && decrement i++ | ++i | --i | i-- :" << NC << std::endl;
    it = v.begin();
    std::cout << "it = vec.begin();" << std::endl;
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*(it++) = " << *(it++) << std::endl;
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*(it--) = " << *(it--) << std::endl;
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*(++it) = " << *(++it) << std::endl;
    std::cout << "*it = " << *it << std::endl;
    std::cout << "*(--it) = " << *(--it) << std::endl;
    std::cout << "*it = " << *it << std::endl << std::endl;

	std::cout << YELLOW << "Test arithmetics i + | i - | i += | i -= :" << NC << std::endl;
    it = v.begin();
    std::cout << "it = vec.begin();" << std::endl;
    std::cout << "*(it + 0) = " << *(it + 0) << std::endl;
    std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
    std::cout << "*(it + 5) = " << *(it + 5) << std::endl << std::endl;

    it = v.end() - 1;
    std::cout << "it = v.end() - 1;" << std::endl;
    std::cout << "*(it - 0) = " << *(it - 0) << std::endl;
    std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
    std::cout << "*(it - 5) = " << *(it - 5) << std::endl << std::endl;

    std::cout << "(*it += 2) = " << (*it += 2) << std::endl;
    std::cout << "(*it -= 1) = " << (*it -= 1) << std::endl << std::endl;

	std::vector<int>::iterator   it_beg = v.begin();
    std::vector<int>::iterator   it_end = v.end();

    std::cout << "it_beg = v.begin()"  << std::endl;
    std::cout << "it_end = v.end()"  << std::endl << std::endl;

    std::cout << "it_beg < it_end is " << std::boolalpha << (it_beg < it_end) << std::endl;
    std::cout << "it_end < it_beg is " << std::boolalpha << (it_end < it_beg) << std::endl;
    std::cout << "it_beg > it_end is " << std::boolalpha << (it_beg > it_end) << std::endl;
    std::cout << "it_end > it_beg is " << std::boolalpha << (it_end > it_beg) << std::endl << std::endl;

    std::cout << "it_beg <= it_end is " << std::boolalpha << (it_beg <= it_end) << std::endl;
    std::cout << "it_end <= it_beg is " << std::boolalpha << (it_end <= it_beg) << std::endl;
    std::cout << "it_end <= it_end is " << std::boolalpha << (it_end <= it_end) << std::endl;
    std::cout << "it_beg >= it_end is " << std::boolalpha << (it_beg >= it_end) << std::endl;
    std::cout << "it_end >= it_beg is " << std::boolalpha << (it_end >= it_beg) << std::endl;
    std::cout << "it_end >= it_end is " << std::boolalpha << (it_end >= it_end) << std::endl << std::endl;

    std::cout << "it_beg == it_end is " << std::boolalpha << (it_beg == it_end) << std::endl;
    std::cout << "it_beg == it_beg is " << std::boolalpha << (it_beg == it_beg) << std::endl;
    std::cout << "it_beg != it_end is " << std::boolalpha << (it_beg != it_end) << std::endl;
    std::cout << "it_beg != it_beg is " << std::boolalpha << (it_beg != it_beg) << std::endl << std::endl;

	std::cout << YELLOW << "Test dereference" << NC << std::endl;
	for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
	std::cout << std::endl;
	v[0] = 0;
	for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
	std::cout << std::endl;


}
