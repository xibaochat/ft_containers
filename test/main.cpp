#include "../vector.hpp"
# include <sys/stat.h>
# include <sys/types.h>
# include <iostream>
# include <string>
# include <fstream>
# include "test.hpp"

template <class T>
std::string equalContent(
    const std::vector<T> & stl_vector,
    const ft::vector<T> & ft_vector
)
{
    typename ft::vector<T>::const_iterator ft_it;
    typename std::vector<T>::const_iterator stl_it;
    if (ft_vector.size() != stl_vector.size())
        return ("✘");
    stl_it = stl_vector.begin();
    for(ft_it = ft_vector.begin(); ft_it != ft_vector.end(); ft_it++)
    {
        if (*ft_it != *stl_it)
            return ("✘");
        stl_it++;
    }
    return ("✔");
}

template <class T>
std::string equal(const T& t1, const T& t2)
{
    return (t1 == t2 ? "✔" : "✘");
}

template <class T>
bool equalbool(const T& t1, const T& t2)
{
    return (t1 == t2 ? true : false);
}

template <class T>
bool printVectorAttributes(
    std::fstream& fs,
    std::vector<T>& stl_vector,
    ft::vector<T>& ft_vector
)
{
    /* STL Values */
    std::string stl_empty = ((stl_vector.empty() == 1) ? "true" : "false");
    size_t stl_size = stl_vector.size();
    size_t stl_max_size = stl_vector.max_size();
    size_t stl_capacity = stl_vector.capacity();

    /* FT Values */
    std::string ft_empty = ((ft_vector.empty() == 1) ? "true" : "false");
    size_t ft_size = ft_vector.size();
    size_t ft_max_size = ft_vector.max_size();
    size_t ft_capacity = ft_vector.capacity();

    /* FT Result compare values */
    bool empty = equalbool(ft_empty, stl_empty);
    bool size = equalbool(ft_size, stl_size);
    bool max_size = equalbool(ft_max_size, stl_max_size);
    bool capacity = equalbool(ft_capacity, stl_capacity);
    std::string content = equalContent(stl_vector, ft_vector);

	fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "Vectors attributes : \n";
    fs << "STL : \n";
    fs << "Empty       : " << stl_empty  << std::endl;
    fs << "Size        : " << stl_size  << std::endl;
    fs << "Max size    : " << stl_max_size  << std::endl;
    fs << "Capacity    : " << stl_capacity  << std::endl;
    fs << "Content     : [";

    typename std::vector<T>::const_iterator stl_it;
    for (stl_it = stl_vector.begin();  stl_it != stl_vector.end(); stl_it++)
    {
        fs << *stl_it;
        if (stl_it + 1 != stl_vector.end())
            fs << ", ";
    }
    fs << "]\n";
    fs << std::endl;

    fs << "FT : \n";
    fs << "Empty    [" << equal(ft_empty, stl_empty) << "]: " << ft_empty  << std::endl;
    fs << "Size     [" << equal(ft_size, stl_size) << "]: " << ft_size  << std::endl;
    fs << "Max size [" << equal(ft_max_size, stl_max_size) << "]: " << ft_max_size  << std::endl;
    fs << "Capacity [" << equal(ft_capacity, stl_capacity) << "]: " << ft_capacity  << std::endl;

    fs << "Content  [" << content << "]: [";

    typename ft::vector<T>::const_iterator ft_it;
    for(ft_it = ft_vector.begin(); ft_it != ft_vector.end(); ft_it++)
    {
        fs << *ft_it;
        if (ft_it + 1 != ft_vector.end())
            fs << ", ";
    }
    fs << "]\n";

    fs << "══════════════════════════════════════════════════════════════\n";

    /* Error case */
    if (empty == false)
        return (false);
    else if (size == false)
        return (false);
    else if (max_size == false)
        return (false);
    else if (capacity == false)
        return (false);
    else if (content == "✘")
        return (false);
    return (true);
}

template<class T>
void show_res(const char * str, const char *message, std::fstream &fs, std::vector<T> &s_v, ft::vector<T> &my_v)
{
	fs.open(str, std::fstream::in | std::fstream::out | std::fstream::trunc);
	std::cout << message << ((printVectorAttributes(fs, s_v, my_v) == true) ? "[OK]" : "[NOP]") << std::endl;
	fs.close();
}

void test_vector()
{
	mkdir("./vectors_output", 0777);
	std::vector<int> stl_v;
	ft::vector<int>  my_v;
	std::fstream fs;

	// {
	// 	fs.open("./vectors_output/constructor_default", std::fstream::in | std::fstream::out | std::fstream::trunc);
	// std::cout << "test_vector_construct(): " << ((printVectorAttributes(fs, stl_v, my_v) == true) ? "[OK]" : "[NOP]") << std::endl;
	// fs.close();
	// }
	// {std::vector<int> *p = new std::vector<int>;
	// ft::vector<int>  *my_p = new ft::vector<int>;
	// fs.open("./vectors_output/constructor_default_ptr", std::fstream::in | std::fstream::out | std::fstream::trunc);
	// std::cout << "test_vector_constructor_ptr(): " << ((printVectorAttributes(fs, *p, *my_p) == true) ? "[OK]" : "[NOP]") << std::endl;
	// fs.close();
	// delete p;
	// delete my_p;
	// }
	// {
	// 	std::vector<int> stl_vector_fill(8);
	// 	ft::vector<int>  my_vector_fill(8);
	// 	fs.open("./vectors_output/constructor_fill_no_val", std::fstream::in | std::fstream::out | std::fstream::trunc);
	// 	std::cout << "test_vector_constructor_fill_no_val(): " << ((printVectorAttributes(fs, stl_vector_fill, my_vector_fill) == true) ? "[OK]" : "[NOP]") << std::endl;
	// 	fs.close();
	// }
	// {
	// 	std::vector<int> stl_vector_fill_v(4, 8);
	// 	ft::vector<int> my_vector_fill_v(4, 8);
	// 	fs.open("./vectors_output/constructor_fill_with_val", std::fstream::in | std::fstream::out | std::fstream::trunc);
	// 	std::cout << "test_vector_constructor_fill_with_val(): " << ((printVectorAttributes(fs, stl_vector_fill_v, my_vector_fill_v) == true) ? "[OK]" : "[NOP]") << std::endl;
	// 	fs.close();
	// }
	// {
	// 	std::vector<int> stl_vector_fill_v(4, 8);
	// 	std::vector<int> stl_vector_range(stl_vector_fill_v.begin(), stl_vector_fill_v.end());
	// 	ft::vector<int> my_vector_range(stl_vector_fill_v.begin(), stl_vector_fill_v.end());
	// 	fs.open("./vectors_output/constructor_range", std::fstream::in | std::fstream::out | std::fstream::trunc);
	// 	std::cout << "test_vector_constructor_range(): " << ((printVectorAttributes(fs, stl_vector_range, my_vector_range) == true) ? "[OK]" : "[NOP]") << std::endl;
	// 	fs.close();
	// }
	// {
	// 	std::vector<int> stl_vector(4, 8);
	// 	ft::vector<int> my_vector(stl_vector.begin(), stl_vector.end());
	// 	ft::vector<int>my_v(my_vector);
	// 	fs.open("./vectors_output/constructor_copy", std::fstream::in | std::fstream::out | std::fstream::trunc);
	// 	std::cout << "test_vector_constructor_copy(): " << ((printVectorAttributes(fs, stl_vector, my_v) == true) ? "[OK]" : "[NOP]") << std::endl;
	// 	fs.close();
	// }
	// {
	// 	int arr[5] = {1, 3, 42, 88, 100};
	// 	std::vector<int> stl_vector(arr, arr + 5);
	// 	ft::vector<int> my_vector(arr, arr + 5);
	// 	fs.open("./vectors_output/constructor_from_arr", std::fstream::in | std::fstream::out | std::fstream::trunc);
	// 	std::cout << "test_vector_constructor_from_arr(): " << ((printVectorAttributes(fs, stl_vector, my_vector) == true) ? "[OK]" : "[NOP]") << std::endl;
	// 	fs.close();
	// }
	// {
	// 	int arr[5] = {1, 3, 42, 88, 100};
	// 	std::vector<int> stl_vector(arr, arr + 5);
	// 	std::vector<int>::iterator it = stl_vector.begin();
	// 	ft::vector<int> my_v(it, it + 5);
	// 	show_res("./vectors_output/constructor_range_iterator", "test_vector_constructor_range_iterator(): ", fs, stl_vector, my_v);
	// }
	// {
	// 	std::vector<int> stl_vector(4, 8);
	// 	ft::vector<int> my_vector(stl_vector.begin(), stl_vector.end());
	// 	ft::vector<int>my_v = my_vector;
	// 	show_res("./vectors_output/constructor_assign", "test_vector_constructor_assign(): ", fs, stl_vector, my_v);
	// }
	// // {
    // //      std::vector<int> stl_filled(100000);
    // //      ft::vector<int> ft_filled(100000);

	// // 	 show_res("./vectors_output/size_big", "test_vector_fill_big_nb", fs, stl_filled, ft_filled);
	// // 	 fs.close();
	// // }
	// {
	// 	std::vector<int> stl_v(12);
	// 	ft::vector<int>  my_v(12);
	// 	stl_v.resize(15);
	// 	my_v.resize(15);
	// 	show_res("./vectors_output/test_resize_larger", "test_resize_larger", fs, stl_v, my_v);
	// 	stl_v.resize(2);
	// 	my_v.resize(2);
	// 	show_res("./vectors_output/test_resize_smaller", "test_resize_smaller", fs, stl_v, my_v);
	// }
	{
		std::vector<int> stl_v(10);
		ft::vector<int>  my_v(10);
		stl_v.push_back(42);
		stl_v.push_back(17);
		my_v.push_back(42);
		my_v.push_back(17);
		std::cout << "\n" ;
		stl_v.insert(stl_v.begin(), stl_v.begin() + 2, stl_v.end() - 3);
		my_v.insert(my_v.begin(), my_v.begin() + 2, my_v.end() -3);
		// show_res("./vectors_output/test_capacity_0", "test_capacity_0", fs, stl_v, my_v);
	}
	// {


	// }

}

// void vector_iterator_test()
// {
// 	iterator_test();
// 	std::cout << RED << "------------SPLIT LINE-------------" << NC << std::endl;
// 	real_iterator();
// }

// void vector_reverse_iterator_test()
// {
// 	// reverse_iterator_incrementers();
// 	// stl_reverse_iterator_incrementers();
// 	//reverse_iterator_arithmetics();
// 	//stl_reverse_iterator_arithmetics();
//	reverse_iterator_bool_test();
//	stl_reverse_iterator_bool_test();
//}

int main()
{
//	vector_iterator_test();
//	vector_reverse_iterator_test();
	test_vector();

}
