#include "../containers/vector.hpp"

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

template<class T>
void printSingleValue(std::fstream& fs, const T& t1, const T& t2)
{
    fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "Value from :\n";
    fs << "STL    : " << t1 << "\n";
    fs << "FT  [" << equal(t1, t2) << "]: " << t2 << "\n";
    fs << "══════════════════════════════════════════════════════════════\n";
	if (t1 == t2)
		std::cout << GREEN << "[OK]" << NC;
	else
		std::cout << RED << "[NOP]" << NC;
	fs.close();
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
	std::cout << message;
	if (printVectorAttributes(fs, s_v, my_v) == true)
		std::cout << GREEN << "[OK]";
	else
		std::cout << RED << "[NOP]";
	std::cout << NC << std::endl;
	fs.close();
}

void test_vector()
{
	mkdir("./vectors_output", 0777);
	std::vector<int> stl_v;
	ft::vector<int>  my_v;
	std::fstream fs;

	{
		show_res("./vectors_output/constructor_default", "test_vector_construct ", fs, stl_v, my_v);
	}
	{std::vector<int> *p = new std::vector<int>;
	ft::vector<int>  *my_p = new ft::vector<int>;
	show_res("./vectors_output/constructor_default_ptr", "test_vector_constructor_ptr ", fs, *p, *my_p);
	delete p;
	delete my_p;
	}
	{
		std::vector<int> stl_vector_fill(8);
		ft::vector<int>  my_vector_fill(8);
		show_res("./vectors_output/constructor_fill_no_val", "test_vector_constructor_fill_no_val", fs, stl_vector_fill, my_vector_fill);
	}
	{
		std::vector<int> stl_vector_fill_v(4, 8);
		ft::vector<int> my_vector_fill_v(4, 8);
		show_res("./vectors_output/constructor_fill_with_val", "test_vector_constructor_fill_with_val", fs, stl_vector_fill_v, my_vector_fill_v);
	}
	{
		std::vector<int> stl_vector_fill_v(4, 8);
		std::vector<int> stl_vector_range(stl_vector_fill_v.begin(), stl_vector_fill_v.end());
		ft::vector<int> my_vector_range(stl_vector_fill_v.begin(), stl_vector_fill_v.end());
		show_res("./vectors_output/constructor_range", "test_vector_constructor_range", fs, stl_vector_range, my_vector_range);
	}
	{
		std::vector<int> stl_vector(4, 8);
		ft::vector<int> my_vector(stl_vector.begin(), stl_vector.end());
		ft::vector<int>my_v(my_vector);
		show_res("./vectors_output/constructor_copy", "test_vector_constructor_copy", fs, stl_vector, my_v);
	}
	{
		int arr[5] = {1, 3, 42, 88, 100};
		std::vector<int> stl_vector(arr, arr + 5);
		ft::vector<int> my_vector(arr, arr + 5);
		show_res("./vectors_output/constructor_from_arr", "test_vector_constructor_from_arr ", fs, stl_vector, my_vector);
	}
	{
		int arr[5] = {1, 3, 42, 88, 100};
		std::vector<int> stl_vector(arr, arr + 5);
		std::vector<int>::iterator it = stl_vector.begin();
		ft::vector<int> my_v(it, it + 5);
		show_res("./vectors_output/constructor_range_iterator", "test_vector_constructor_range_iterator ", fs, stl_vector, my_v);
	}
	{
		std::vector<int> stl_vector(4, 8);
		ft::vector<int> my_vector(stl_vector.begin(), stl_vector.end());
		ft::vector<int>my_v = my_vector;
		show_res("./vectors_output/constructor_assign", "test_vector_constructor_assign(): ", fs, stl_vector, my_v);
	}
	// {
    //      std::vector<int> stl_filled(100000);
    //      ft::vector<int> ft_filled(100000);

	// 	 show_res("./vectors_output/size_big", "test_vector_fill_big_nb", fs, stl_filled, ft_filled);
	// 	 fs.close();
	// }
	/*resize*/
	{
		std::vector<int> stl_v(12);
		ft::vector<int>  my_v(12);
		stl_v.resize(15);
		my_v.resize(15);
		show_res("./vectors_output/test_resize_larger", "test_resize_larger", fs, stl_v, my_v);
		stl_v.resize(2);
		my_v.resize(2);
		show_res("./vectors_output/test_resize_smaller", "test_resize_smaller", fs, stl_v, my_v);
	}
	/*insert*/
	{
		std::vector<int> stl_v(10, 42);
		ft::vector<int>  my_v(10, 42);
		stl_v.push_back(42);
		stl_v.push_back(17);
		my_v.push_back(42);
		my_v.push_back(17);
		std::cout << "\n" ;
		stl_v.insert(stl_v.begin(), stl_v.begin() + 2, stl_v.end() - 3);
		my_v.insert(my_v.begin(), my_v.begin() + 2, my_v.end()- 3);
		show_res("./vectors_output/test_insert_range_0", "test_insert_range_0", fs, stl_v, my_v);
	}
	{
		std::vector<int> stl(110, 2);
		std::vector<int> stl_v(100);
		ft::vector<int>  my_v(100);
		stl_v.insert(stl_v.begin(), stl.begin(), stl.end());
		my_v.insert(my_v.begin(), stl.begin(), stl.end());
		show_res("./vectors_output/test_insert_range_1", "test_insert_range_1", fs, stl_v, my_v);
	}
	{
		std::vector<int> stl(1, 42);
		std::vector<int> stl_v(100);
		ft::vector<int>  my_v(100);
		stl_v.insert(stl_v.begin(), stl.begin(), stl.end());
		my_v.insert(my_v.begin(), stl.begin(), stl.end());
		show_res("./vectors_output/test_insert_range_2", "test_insert_range_2", fs, stl_v, my_v);
	}
	{
		std::vector<int> stl_v(100, 42);
		ft::vector<int> my_v(100, 42);
		for(int i=0; i < 150; i++)
		{
			stl_v.push_back(i);
			my_v.push_back(i);
		}
		show_res("./vectors_output/test_push_back0", "test_push_back0", fs, stl_v, my_v);
	}
	{
		std::vector<int> stl_v;
		ft::vector<int> my_v;
		stl_v.push_back(1);
		my_v.push_back(1);
		show_res("./vectors_output/test_push_back_1", "test_push_back_1", fs, stl_v, my_v);
	}/*insert filler*/
	{
		std::vector<int> stl_v(99, 42);
        ft::vector<int> my_v(99, 42);
		stl_v.insert(stl_v.begin(), 150, 1);
		my_v.insert(my_v.begin(), 150, 1);
		show_res("./vectors_output/test_insert_filler_3", "test_insert_filler_3", fs, stl_v, my_v);
	}
	/*insert 1 elem*/
	{
		 std::vector<int> stl_v(99, 42);
		 ft::vector<int> my_v(99, 42);
		 stl_v.insert(stl_v.begin() + 15, 888);
		 my_v.insert(my_v.begin() + 15, 888);
		 show_res("./vectors_output/test_insert_single_ele_4", "test_insert_single_ele_4", fs, stl_v, my_v);
	}
	/*iterator and const iterator*/
	{
		int range_array[] = { -89, 561, 874, 7777 , 987, -6 };
		std::vector<int>::iterator it(range_array);
		std::vector<int>::const_iterator c_it(range_array);
		std::vector<int>::const_iterator c_it2(c_it);
		std::vector<int> stl_v(c_it, c_it + 6);
		ft::vector<int>  my_v(c_it, c_it + 6);
		ft::vector<int>  my_v2(c_it2, c_it2 + 6);
		show_res("./vectors_output/test_const_it_0", "test_const_it0", fs, stl_v, my_v);
		show_res("./vectors_output/test_const_it_1", "test_const_it1", fs, stl_v, my_v);
	}

	/*push_back*/
	{
		std::vector<int> stl_v(42);
		ft::vector<int>  my_v(42);
		stl_v.push_back(888);
		stl_v.push_back(24);
		my_v.push_back(888);
		my_v.push_back(24);
		std::cout << "\n" ;
		show_res("./vectors_output/test_push_back_2", "test_push_back_2", fs, stl_v, my_v);
	}
	/*test operator= */
	{
		int range_array[] = { -89, 561, 874, 7777 , 987, -6 };
		std::vector<int>::iterator it(range_array);
		std::vector<int> stl_v(it, it + 6);
        ft::vector<int> my_v(it, it + 6);
		ft::vector<int> tmp = my_v;
		show_res("./vectors_output/test_assign_operator=", "test_assign_operator=", fs, stl_v, tmp);
	}/*end()*/
	{
		int range_array[] = { 48, 967, 52, -45, -9, 956551, 44};
        std::vector<int>::iterator stl_iterator(&(range_array[0]));
        ft::vector<int>::iterator ft_iterator(&(range_array[0]));

        std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 7);
        ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 7);
        int from_stl = *(stl_range_vector.end() - 1);
        int from_ft = *(ft_range_vector.end() - 1);

		fs.open("./vectors_output/test_end", std::fstream::in | std::fstream::out | std::fstream::app);
		std::cout << "test_end() ";
		printSingleValue(fs, from_stl, from_ft);
	}
	 /* Const iteratorbegin(), end(),  rbegin(), rend() */
	{
		int range_array[] = { 48, 967, 52, -45, -9, 956551, 44};
        std::vector<int>::const_iterator stl_iterator(&(range_array[0]));
        ft::vector<int>::const_iterator ft_iterator(&(range_array[0]));

        std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 7);
        ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 7);
		int stl_begin = *stl_range_vector.begin();
		int v_begin = *ft_range_vector.begin();
        int stl_end = *(stl_range_vector.end() - 1);
        int v_end = *(ft_range_vector.end() - 1);
		int stl_rbegin =  *stl_range_vector.rbegin();
		int v_rbegin = *ft_range_vector.rbegin();
		int stl_rend = *(stl_range_vector.rend() -1);
		int v_rend = *(ft_range_vector.rend() - 1);
		fs.open("./vectors_output/test_const_begin_end_rbegin_rend", std::fstream::in | std::fstream::out | std::fstream::app);
		std::cout << "test_const_begin_end_rbegin_rend const_iterator begin";
		printSingleValue(fs, stl_begin, v_begin);
		fs.open("./vectors_output/test_const_begin_end_rbegin_rend", std::fstream::in | std::fstream::out | std::fstream::app);
		std::cout << "last value";
		printSingleValue(fs, stl_end, v_end);
		fs.open("./vectors_output/test_const_begin_end_rbegin_rend", std::fstream::in | std::fstream::out | std::fstream::app);
		std::cout << "rbegin value";
		printSingleValue(fs, stl_rbegin, v_rbegin);
		fs.open("./vectors_output/test_const_begin_end_rbegin_rend", std::fstream::in | std::fstream::out | std::fstream::app);
		std::cout << "rend value";
		printSingleValue(fs, stl_rend, v_rend);
		std::vector<int>::reverse_iterator stl_it = stl_range_vector.rbegin();
		for(ft::vector<int>::reverse_iterator ft_it = ft_range_vector.rbegin(); ft_it != ft_range_vector.rend(); ft_it++)
		{
			if (*ft_it != *stl_it)
				std::cout << RED << "[NOP]";
			stl_it++;
		}
		std::cout << "elements compare" << GREEN << "[OK]" << NC << std::endl;
	}/*empty*/
	{
		std::vector<int> stl_v;
        ft::vector<int> my_v;
		if (stl_v.empty() != my_v.empty())
			std::cout << "empty test " << RED << "[NOP]" << NC << std::endl;
		stl_v.push_back(1);
		my_v.push_back(1);
		if (stl_v.empty() != my_v.empty())
			std::cout << "empty test " << RED << "[NOP]" << NC << std::endl;
		else
			std::cout << "empty test " << GREEN << "[OK]" << NC << std::endl;
	}/*resize*/
	{
		std::vector<int> stl_v(10);
        ft::vector<int> my_v(10);
		stl_v.push_back(1);
		my_v.push_back(1);
		stl_v.resize(5);
		my_v.resize(5);
		show_res("./vectors_output/resize_test", "test_resize", fs, stl_v, my_v);
	}/*[]*/
	{
		std::vector<int> myvector (10);   // 10 zero-initialized elements
		std::vector<int>::size_type sz = myvector.size();
		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;
		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
			int temp;
			temp = myvector[sz-1-i];
			myvector[sz-1-i]=myvector[i];
			myvector[i]=temp;
		}
		ft::vector<int> ft_v (10);   // 10 zero-initialized elements
		ft::vector<int>::size_type f_sz = ft_v.size();
		// assign some values:
		for (unsigned i=0; i<f_sz; i++) ft_v[i]=i;
		for (unsigned i=0; i<f_sz/2; i++)
		{
			int temp;
			temp = ft_v[f_sz-1-i];
			ft_v[f_sz-1-i]=ft_v[i];
			ft_v[i]=temp;
		}
		show_res("./vectors_output/[]_test", "test_[]", fs, myvector, ft_v);
	}
	/*at test*/
	{
		std::cout << "test_at";
		std::vector<int> stl_v (10);   // 10 zero-initialized ints
		for (unsigned i=0; i<stl_v.size(); i++)
			stl_v.at(i)=i;
		std::vector<int> my_v(10);
		for (unsigned int i=0; i<my_v.size(); i++)
			my_v.at(i)=i;
		for(unsigned int i = 0; i < 10; i++)
			if (stl_v.at(i) != my_v.at(i))
				std::cout << RED << "[NOP]" << NC << std::endl;
		std::cout << GREEN << "[OK]" << NC << std::endl;
	}
	/*front and back*/
	{
		std::vector<int> stl_v;
		stl_v.push_back(78);
		stl_v.push_back(16);
		stl_v.front() -= stl_v.back();
		ft::vector<int> my_v;
		my_v.push_back(78);
		my_v.push_back(16);
		my_v.front() -= my_v.back();
		std::cout << "front and back test0";
		if ((my_v.front() != stl_v.front()) || my_v.back() != stl_v.back())
			std::cout << RED << "[NOP]" << NC << std::endl;
		else
			std::cout << GREEN << "[OK]" << NC << std::endl;
	}
	/*assign*/
	{
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;
		std::vector<int> forth(10);
		first.assign (7,100);             // 7 ints with a value of 100
		std::vector<int>::iterator it;
		it=first.begin()+1;
		second.assign (it,first.end()-1); // the 5 central values of first
		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.
		forth.assign(42, 10);

		ft::vector<int> my_fst;
		ft::vector<int> my_scd;
		ft::vector<int> my_thd;
		ft::vector<int> my_forth(10);
		my_fst.assign (7,100);             // 7 ints with a value of 100
		ft::vector<int>::iterator ft_it;
		ft_it=my_fst.begin()+1;
		my_scd.assign (ft_it,my_fst.end()-1); // the 5 central values of my_fst
		my_thd.assign (myints,myints+3);   // assigning from array.
		my_forth.assign(42, 10);
		show_res("./vectors_output/assign_test_0", "test_assign_0", fs, first, my_fst);
		show_res("./vectors_output/assign_test_1", "test_assign_1", fs, second, my_scd);
		show_res("./vectors_output/assign_test_2", "test_assign_2", fs, third, my_thd);
		show_res("./vectors_output/assign_test_3", "test_assign_3", fs, forth, my_forth);
	}
	/*pop test*/
	{
		std::vector<int> stl_v;
		ft::vector<int>  my_v;
		int sum0 = 0;
		int sum1 = 0;
		for(int i=0;i< 150; i++)
		{
			stl_v.push_back(i);
			my_v.push_back(i);
		}
		while (!stl_v.empty())
		{
			sum0 += stl_v.back();
			stl_v.pop_back();
		}
		while(!my_v.empty())
		{
			sum1 += my_v.back();
			my_v.pop_back();
		}
		if (sum0 != sum1)
			std::cout << sum0 << " " << sum1 << RED << "[NOP]" << NC << std::endl;
		show_res("./vectors_output/pop_back_test", "test_pop_back", fs, stl_v, my_v);
	}
	/*erase test*/
	{
		std::vector<int> stl_v;
		for (int i=1; i<=10; i++)
			stl_v.push_back(i);
		stl_v.erase (stl_v.begin() + 5);
		stl_v.erase (stl_v.begin(), stl_v.begin() + 3);

		ft::vector<int> my_v;
		for (int i=1; i<=10; i++)
			my_v.push_back(i);
		my_v.erase (my_v.begin()+5);
		my_v.erase (my_v.begin(), my_v.begin() + 3);
		show_res("./vectors_output/erase_test_0", "test_erase_0", fs, stl_v, my_v);
	}
	/*erase test*/
	{
		int array[] = {454, -5424, 12, 565, 54, 893, 12, 85, 78, -123, 2333};
		std::vector<int>::iterator stl_it(array);
		ft::vector<int>::iterator my_v_it(array);
		std::vector<int> stl_v(stl_it, stl_it + 11);
		ft::vector<int>  my_v(my_v_it, my_v_it + 11);
		stl_v.erase(stl_v.begin() + 2, stl_v.end() - 3);
		my_v.erase(my_v.begin() + 2, my_v.end() - 3);
        show_res("./vectors_output/erase_test_1", "test_erase_1", fs, stl_v, my_v);
	}
	/*swap*/
	{
		std::vector<char> foo (3,'a');   // three ints with a value of 100
		std::vector<char> bar (5, 'b');   // five chars with a value of 200
		foo.swap(bar);
		ft::vector<char> my_foo(3, 'a');
		ft::vector<char> my_bar (5, 'b');   // five chars with a value of 200
		my_foo.swap(my_bar);
		show_res("./vectors_output/swap_0", "test_swap_0", fs, foo, my_foo);
	}
	{
		int range_array_one[] = {144, 335, 5, 0, -54};
        int range_array_two[] = {47, -98, 58, 611, -4};

        std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));
        std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));
        ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));
        ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));

        std::vector<int> stl_swap_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);
        std::vector<int> stl_swap_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);
        ft::vector<int> ft_swap_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);
        ft::vector<int> ft_swap_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);
        std::swap(stl_swap_one, stl_swap_two);
        ft::swap(ft_swap_one, ft_swap_two);
		show_res("./vectors_output/swap_1", "test_swap_1", fs, stl_swap_one, ft_swap_one);
	}
	/*clear*/
	{
		std::vector<int> stl_v;
		stl_v.push_back (100);
		stl_v.push_back (200);
		stl_v.push_back (300);
		stl_v.clear();
		stl_v.push_back (1101);
		stl_v.push_back (2202);
		ft::vector<int> my_v;
		my_v.push_back (100);
		my_v.push_back (200);
		my_v.push_back (300);
		my_v.clear();
		my_v.push_back (1101);
		my_v.push_back (2202);
		show_res("./vectors_output/clear", "test_clear", fs, stl_v, my_v);
	}
/*get_allocator()*/
	{
		std::vector<int> myvector;
		int * p;
		unsigned int i;
		p = myvector.get_allocator().allocate(5);
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		ft::vector<int> my_v;
		int * my_p;
		unsigned int my_i;
		my_p = my_v.get_allocator().allocate(5);
		for (my_i=0; my_i<5; my_i++) my_v.get_allocator().construct(&my_p[my_i], my_i);
		for (my_i=0; my_i<5; my_i++) my_v.get_allocator().destroy(&my_p[my_i]);
		show_res("./vectors_output/get_allocator", "test_get_allocator", fs, myvector, my_v);
		my_v.get_allocator().deallocate(my_p,5);
		myvector.get_allocator().deallocate(p,5);
	}
	/*operator compare*/
	{
		std::cout << YELLOW << "operator tester == != < <= > >=" << NC << std::endl;
		ft::vector <int> v1, v2;
		if (v1==v2 && !(v1!=v2) && !(v1<v2) && v1<=v2 && !(v1>v2) && v1>=v2)
			std::cout << "empty vector" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "empty vector" << RED << "[NOP]" << NC << std::endl;
	}
	{
		ft::vector <int> v1, v2;
		v1.push_back( 1 );
		v2.push_back( 2 );
		if (!(v1==v2) && (v1!=v2) && (v1<v2) && v1<=v2 && !(v1>v2) && !(v1>=v2))
			std::cout << "non empty vector_0" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "non empty vector_0" << RED << "[NOP]" << NC << std::endl;
	}
	{
		ft::vector <int> v1, v2;
		v1.push_back( 1 );
		v1.push_back( 2 );
		v1.push_back( 4 );

		v2.push_back( 1 );
		v2.push_back( 3 );

		if (!(v1==v2) && (v1!=v2) && (v1<v2) && v1<=v2 && !(v1>v2) && !(v1>=v2))
			std::cout << "non empty vector_1" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "non empty vector_1" << RED << "[NOP]" << NC << std::endl;
	}
	{
		ft::vector <int> v1, v2;
		v1.push_back( 1 );
		v1.push_back( 2 );
		v1.push_back( 4 );

		v2.push_back( 1 );
		v2.push_back( 3 );

		if (!(v1==v2) && (v1!=v2) && (v2 > v1) && (v2 >= v1) && (v1<v2) && !(v2<=v1))
			std::cout << "non empty vector_2" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "non empty vector_2" << RED << "[NOP]" << NC << std::endl;
	}
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
//	test_vector();
	const int size = 5;
	ft::vector<int> vct(size);
	ft::vector<int>::reverse_iterator it = vct.rbegin();
	ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;



}
