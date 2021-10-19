#include "test.hpp"

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
std::string equalContent(const std::set<T> & stl_set,const ft::set<T> & ft_set)
{
	typename ft::set<T>::const_iterator ft_it;
	typename std::set<T>::const_iterator stl_it;
	if (ft_set.size() != stl_set.size())
		return ("✘");
	stl_it = stl_set.begin();
	for(ft_it = ft_set.begin(); ft_it != ft_set.end(); ft_it++)
	{
		if (*ft_it != *stl_it)
			return ("✘");
		stl_it++;
	}
	return ("✔");
}

template <class T>
bool printSetAttributes(std::fstream& fs,std::set<T>& stl_set,	ft::set<T>& ft_set)
{
	/* STL Values */
	std::string stl_empty = ((stl_set.empty() == 1) ? "true" : "false");
	size_t stl_size = stl_set.size();
	size_t stl_max_size = stl_set.max_size();

	/* FT Values */
	std::string ft_empty = ((ft_set.empty() == 1) ? "true" : "false");
	size_t ft_size = ft_set.size();
	size_t ft_max_size = ft_set.max_size();

	/* FT Result compare values */
	bool empty = equalbool(ft_empty, stl_empty);
	bool size = equalbool(ft_size, stl_size);
	bool max_size = equalbool(ft_max_size, stl_max_size);
	std::string content = equalContent(stl_set, ft_set);

	fs << "\n══════════════════════════════════════════════════════════════\n";
	fs << "sets attributes : \n";
	fs << "STL : \n";
	fs << "Empty       : " << stl_empty  << std::endl;
	fs << "Size        : " << stl_size  << std::endl;
	fs << "Max size    : " << stl_max_size  << std::endl;
	fs << "Content     : [";

	typename std::set<T>::const_iterator stl_it;
	for (stl_it = stl_set.begin();  stl_it != stl_set.end(); stl_it++)
	{
		fs << "[";
		fs << *stl_it;
		fs << ", ";
	}
	fs << "]\n";

	fs << std::endl;

	fs << "FT : \n";
	fs << "Empty    [" << equal(ft_empty, stl_empty) << "]: " << ft_empty  << std::endl;
	fs << "Size     [" << equal(ft_size, stl_size) << "]: " << ft_size  << std::endl;
	fs << "Max size [" << equal(ft_max_size, stl_max_size) << "]: " << ft_max_size  << std::endl;

	fs << "Content  [" << content << "]: [";

	typename ft::set<T>::const_iterator ft_it;
	for(ft_it = ft_set.begin(); ft_it != ft_set.end(); ft_it++)
	{
		fs << "[";
		fs << *ft_it;
		fs << "]";
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
	else if (content == "✘")
		return (false);
	return (true);
}


template<class T>
bool printSingleValue(std::fstream& fs, const T& t1, const T& t2)
{
    fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "Value from :\n";
    fs << "STL    : " << t1 << "\n";
    fs << "FT  [" << equal(t1, t2) << "]: " << t2 << "\n";
    fs << "══════════════════════════════════════════════════════════════\n";
	if (t1 == t2)
		return true;
	else
		return false;
}

template<class T>
void show_res(std::fstream &fs, std::set<T>&his_map, ft::set<T>&my_map)
	{
		if (printSetAttributes(fs, his_map, my_map) == true)
			std::cout << GREEN << "[OK]\n" << NC;
		else
			std::cout << RED << "[NOP]\n" << NC;
		fs.close();
	}

void test_set()
{

	std::cout << UNDERLINE << "SET :\n" << NC ;

	mkdir("./set_output", 0777);

	std::fstream fs;

	/* Constructors */
	std::cout << "test_set_constructors ";

	/* Default constructor */
	{
		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		fs.open("./set_output/constructor_default", std::fstream::in | std::fstream::out | std::fstream::trunc);
		show_res(fs, stl_default_set, ft_default_set);
	}
	std::cout << "test_set_range_constructor ";
	/* Range constrcutor */
	{
		std::set<int> stl_set;
		ft::set<int> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(i);
			ft_set.insert(i);
		}
		fs.open("./set_output/constructor_range", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<int> stl_set_copy(stl_set.begin(), stl_set.end());
		ft::set<int> ft_set_copy(ft_set.begin(), ft_set.end());

		show_res(fs, stl_set_copy, ft_set_copy);
	}
	std::cout << "test_map_copy_constructor ";
	/* Copy constructor */
	{
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};
		std::set<std::string> stl_set;
		ft::set<std::string> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_str[i]);
			ft_set.insert(range_str[i]);
		}

		fs.open("./set_output/constructor_copy", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<std::string> stl_set_copy(stl_set);
		ft::set<std::string> ft_set_copy(ft_set);
		show_res(fs, stl_set_copy, ft_set_copy);
		fs.close();
	}

	std::cout << "test_set_operator= ";
	/* Assign operator */
	{
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};
		std::set<std::string> stl_set;
		ft::set<std::string> ft_set;
		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_str[i]);
			ft_set.insert(range_str[i]);
		}
		fs.open("./set_output/operator_assign", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<std::string> stl_set_copy = stl_set;
		ft::set<std::string> ft_set_copy = ft_set;
		show_res(fs, stl_set_copy, ft_set_copy);
		fs.close();
	}
	std::cout << "test_set_iterator_begin ";
	/* Begin */
	{
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};
		std::set<std::string> stl_set;
		ft::set<std::string> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_str[i]);
			ft_set.insert(range_str[i]);
		}
		fs.open("./set_output/begin", std::fstream::in | std::fstream::out | std::fstream::trunc);

		if (printSetAttributes(fs, stl_set, ft_set) == true &&
		printSingleValue(fs, *stl_set.begin(), *ft_set.begin()))
			std::cout << GREEN << "[OK]\n" << NC;
		else
			std::cout << RED << "[NOP]\n" << NC;
		fs.close();
	}
  	std::cout << "test_map_const_iterator_begin ";
	/* Const begin */
	{
		const int range_int[] = {48, 9, 12, 63, 99};

		std::set<int> stl_set;
		ft::set<int> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_int[i]);
			ft_set.insert(range_int[i]);
		}
		fs.open("./set_output/begin_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<int>::const_iterator stl_it = stl_set.begin();
		ft::set<int>::const_iterator ft_it = ft_set.begin();

		if (printSetAttributes(fs, stl_set, ft_set) == true &&
			printSingleValue(fs, *stl_it, *ft_it))
			std::cout << GREEN << "[OK]\n" << NC;
		else
			std::cout << RED << "[NOP]\n" << NC;
		fs.close();
	}

	std::cout << "test_map_iterator_end ";
	/* End */
	{
		const int range_int[] = {-99, 584, 965, 366, 77};
		std::set<int> stl_set;
		ft::set<int> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_int[i]);
			ft_set.insert(range_int[i]);
		}

		fs.open("./set_output/end", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<int>::iterator stl_it = stl_set.end();
		ft::set<int>::iterator ft_it = ft_set.end();

		--stl_it;
		--ft_it;

		if (printSetAttributes(fs, stl_set, ft_set) == true &&
			printSingleValue(fs, *stl_it, *ft_it))
			std::cout << GREEN << "[OK]\n" << NC;
		else
			 std::cout << RED << "[NOP]\n" << NC;
		fs.close();
	}

	std::cout << "test_set_const_iterator_end ";
	/* Const end */
	{
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};
		std::set<std::string> stl_set;
		ft::set<std::string> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_str[i]);
			ft_set.insert(range_str[i]);
		}

		fs.open("./set_output/end_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<std::string>::const_iterator stl_it = stl_set.end();
		ft::set<std::string>::const_iterator ft_it = ft_set.end();

		--stl_it;
		--ft_it;
		if (printSetAttributes(fs, stl_set, ft_set) == true
			&& printSingleValue(fs, (*stl_it), (*ft_it)))
			std::cout << GREEN << "[OK]\n" << NC;
		else
			std::cout << RED << "[NOP]\n" << NC;
		fs.close();
	}
	std::cout << "test_set_rebegin_test ";
	/* Reverse begin */
	{
		const int range_int[] = {1458, -985, 58, 632, 65};

		std::set<int> stl_set;
		ft::set<int> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_int[i]);
			ft_set.insert(range_int[i]);
		}
		fs.open("./set_output/reverse_begin", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<int>::reverse_iterator stl_it = stl_set.rbegin();
		ft::set<int>::reverse_iterator ft_it = ft_set.rbegin();

		if (!printSetAttributes(fs, stl_set, ft_set))
		{
			std::cout << RED << "[NOP]"  << NC << std::endl;
			fs.close();
		}
		else
		{
			++stl_it;
			++ft_it;
			if (printSingleValue(fs, *stl_it, *ft_it))
				std::cout << GREEN << "[OK]" << NC << std::endl;
			else
				std::cout << RED << "[NOP]"  << NC << std::endl;
			fs.close();
		}
	}
	std::cout << "const_reverse_begin ";
	/* Const reverse begin */
	{
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::set<std::string> stl_set;
		ft::set<std::string> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_str[i]);
			ft_set.insert(range_str[i]);
		}
		fs.open("./set_output/reverse_begin_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<std::string>::const_reverse_iterator stl_it = stl_set.rbegin();
		ft::set<std::string>::const_reverse_iterator ft_it = ft_set.rbegin();

		if (!printSetAttributes(fs, stl_set, ft_set))
		{
			std::cout << RED << "[NOP]"  << NC << std::endl;
			fs.close();
		}
		else
		{
			if (printSingleValue(fs, *stl_it, *ft_it) == true)
				std::cout << GREEN << "[OK]" << NC << std::endl;
			else
				std::cout << RED << "[NOP]"  << NC << std::endl;
			fs.close();
		}
	}
	std::cout << "test_set_reverse_end ";
	/* Reverse end */
	{
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};
		std::set<std::string> stl_set;
		ft::set<std::string> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_str[i]);
			ft_set.insert(range_str[i]);
		}

		fs.open("./set_output/reverse_end", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<std::string>::reverse_iterator stl_it = stl_set.rend();
		ft::set<std::string>::reverse_iterator ft_it = ft_set.rend();
		--stl_it;
		--ft_it;

		if (!printSetAttributes(fs, stl_set, ft_set)
			|| (printSingleValue(fs, *stl_it, *ft_it) == false))
			std::cout << RED << "[NOP]"  << NC << std::endl;
		else
			std::cout << GREEN << "[OK]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_const _reverse_end ";
	/* Const reverse end */
	{
		const int range_int[] = {-99, 584, 965, 366, 77};

		std::set<int> stl_set;
		ft::set<int> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_int[i]);
			ft_set.insert(range_int[i]);
		}

		fs.open("./set_output/reverse_end_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<int>::const_reverse_iterator stl_it = stl_set.rend();
		ft::set<int>::const_reverse_iterator ft_it = ft_set.rend();
		--(--stl_it);
		--(--ft_it);
		if (!printSetAttributes(fs, stl_set, ft_set))
			std::cout << RED << "[NOP]" << NC << std::endl;
		else if (printSingleValue(fs, *stl_it, *ft_it) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_empty_true ";
	/* Empty true */
	{
		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		fs.open("./set_output/empty_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printSetAttributes(fs, stl_default_set, ft_default_set) &&
	printBoolResult(fs, stl_default_set.empty(), ft_default_set.empty()))
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_empty_false ";
	/* Empty false */
	{
		const int range_int[] = {1452, 3651, -98, 84, 899};
		std::set<int> stl_set;
		ft::set<int> ft_set;
		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_int[i]);
			ft_set.insert(range_int[i]);
		}

		fs.open("./set_output/empty_false", std::fstream::in | std::fstream::out | std::fstream::trunc);

		if (printSetAttributes(fs, stl_set, ft_set)
			&& printBoolResult(fs, stl_set.empty(), ft_set.empty()))
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_size ";
	/* Size */
	{
		const int range_int[] = {9, -84, -45, -67, -9};
		std::set<int> stl_set;
		ft::set<int> ft_set;
		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_int[i]);
			ft_set.insert(range_int[i]);
		}
		fs.open("./set_output/size", std::fstream::in | std::fstream::out | std::fstream::trunc);
		stl_set.insert(666);
		ft_set.insert(666);
		if (printSetAttributes(fs, stl_set, ft_set) && printSingleValue(fs, stl_set.size(), ft_set.size()))
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}

	std::cout << "test_set_max_size ";
	/* Maximum size */
	{
		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		fs.open("./sets_output/max_size", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printSetAttributes(fs, stl_default_set, ft_default_set) && printSingleValue(fs, stl_default_set.max_size(), ft_default_set.max_size()))			 std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_insert_single ";
	/*insert single*/
	{
		std::set<int> stl_set;
		ft::set<int> ft_set;

		stl_set.insert(888);
		ft_set.insert(888);

		fs.open("./set_output/insert_single", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printSetAttributes(fs, stl_set, ft_set) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_insert_hint ";
	/*hint insert*/
	{
		const int range_int[] = {584, 96, 21, -54, 36};
		std::set<int> stl_set;
		ft::set<int> ft_set;
		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_int[i]);
			ft_set.insert(range_int[i]);
		}
		fs.open("./set_output/insert_hint", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printSetAttributes(fs, stl_set, ft_set);

		stl_set.insert(++(stl_set.begin()), 666);
		ft_set.insert(++(ft_set.begin()), 666);

		if (printSetAttributes(fs, stl_set, ft_set) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_insert_range ";
	/* Insert Range */
	{
		const int range_int[] = {754, -985, 58, 999, 5};

		std::set<int> stl_set_one;
		ft::set<int> ft_set_one;
		std::set<int> stl_set_two;
		ft::set<int> ft_set_two;

		for (int i = 0; i < 5; i++)
		{
			stl_set_one.insert(range_int[i]);
			ft_set_one.insert(range_int[i]);
			stl_set_two.insert(range_int[i] + 100);
			ft_set_two.insert(range_int[i] + 100);
		}

		fs.open("./set_output/insert_range", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printSetAttributes(fs, stl_set_one, ft_set_one);
		printSetAttributes(fs, stl_set_two, ft_set_two);

		stl_set_one.insert(stl_set_two.begin(), stl_set_two.end());
		ft_set_one.insert(ft_set_two.begin(), ft_set_two.end());

		if (printSetAttributes(fs, stl_set_one, ft_set_one) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	/* Erase iterator position*/
	std::cout << "test_set_erase_iterator_position ";
	{
		const int range_int[] = {-9, -84, -77, 24, 56};

		std::set<int> stl_set;
		ft::set<int> ft_set;

		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_int[i]);
			ft_set.insert(range_int[i]);
		}

		fs.open("./set_output/erase_iterator_position", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printSetAttributes(fs, stl_set, ft_set);

		stl_set.erase(stl_set.begin());
		ft_set.erase(ft_set.begin());

		if (printSetAttributes(fs, stl_set, ft_set) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	/* Erase value */
	std::cout << "test_set_erase_value";
	{
		const int range_int[] = {1452, 3651, -98, 84, 899};
		std::set<int> stl_set;
		ft::set<int> ft_set;
		for (int i = 0; i < 5; i++)
		{
			stl_set.insert(range_int[i]);
			ft_set.insert(range_int[i]);
		}

		fs.open("./set_output/erase_value", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printSetAttributes(fs, stl_set, ft_set);
		stl_set.erase(-98);
		ft_set.erase(-98);

		if (printSetAttributes(fs, stl_set, ft_set) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_erase_range";
	/* Erase range */
	{
        const int range_int[] = {-854, 1, 965, -9, 755};
		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

        for (int i = 0; i < 5; i++)
        {
            stl_default_set.insert(range_int[i]);
			ft_default_set.insert(range_int[i]);
        }

		fs.open("./set_output/erase_range", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printSetAttributes(fs, stl_default_set, ft_default_set);

		std::set<int, std::string>::iterator stl_it_beg = stl_default_set.begin();
		ft::set<int, std::string>::iterator ft_it_beg = ft_default_set.begin();
		std::set<int, std::string>::iterator stl_it_end = stl_default_set.end();
		ft::set<int, std::string>::iterator ft_it_end = ft_default_set.end();

		for (int i = 0; i < 2; i++)
		{
			stl_it_beg++;
			ft_it_beg++;
		}
		stl_it_end--;
		ft_it_end--;

        stl_default_set.erase(stl_it_beg, stl_it_end);
        ft_default_set.erase(ft_it_beg, ft_it_end);

		if (printSetAttributes(fs, stl_default_set, ft_default_set) == true)
            std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_map_swap ";
	/* Swap */
	{
		const int range_int[] = {489, 851, 32, -98, 8};
		std::set<int> stl_default_set_one;
		ft::set<int> ft_default_set_one;
		std::set<int> stl_default_set_two;
		ft::set<int> ft_default_set_two;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set_one.insert(range_int[i]);
			ft_default_set_one.insert(range_int[i]);
			stl_default_set_two.insert(range_int[i] + 120);
			ft_default_set_two.insert(range_int[i] + 120);
		}
		fs.open("./set_output/swap", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printSetAttributes(fs, stl_default_set_one, ft_default_set_one);
		printSetAttributes(fs, stl_default_set_two, ft_default_set_two);

		stl_default_set_one.swap(stl_default_set_two);
		ft_default_set_one.swap(ft_default_set_two);

		if (printSetAttributes(fs, stl_default_set_one, ft_default_set_one) == true
			&& printSetAttributes(fs, stl_default_set_two, ft_default_set_two) == true)
			 std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_set_clear ";
	/* Clear */
	{
		const int range_int[] = {148, 9874, -987, 52, 96};

		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set.insert(range_int[i]);
			ft_default_set.insert(range_int[i]);
		}

		fs.open("./set_output/clear", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printSetAttributes(fs, stl_default_set, ft_default_set);

		stl_default_set.clear();
		ft_default_set.clear();

		if (printSetAttributes(fs, stl_default_set, ft_default_set) == true)
			 std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_key_comp";
	/* Key comp */
	{
		std::set<int>::key_compare stl_key = std::set<int>().key_comp();
		ft::set<int>::key_compare ft_key = ft::set<int>().key_comp();

		bool stl_res = stl_key(42, 99);
		bool ft_res = ft_key(42, 99);

		fs.open("./set_output/key_comp", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printBoolResult(fs, stl_res, ft_res))
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_set_key_comp";
	/* Value comp */
	{
		std::set<int>::value_compare stl_key = std::set<int>().value_comp();
		ft::set<int>::value_compare ft_key = ft::set<int>().value_comp();

		bool stl_res = stl_key(888, 666);
		bool ft_res = ft_key(888, 666);

		fs.open("./sets_output/key_comp_2", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printBoolResult(fs, stl_res, ft_res) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	 std::cout << "test_set_find_key_not_exist ";
	/* Find exist */
	{
		const int range_int[] = {954, 12, -965, 42, 1000};
		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set.insert(range_int[i]);
			ft_default_set.insert(range_int[i]);
		}

		fs.open("./set_output/find_exist", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<int>::iterator stl_it = stl_default_set.find(42);
		ft::set<int>::iterator ft_it = ft_default_set.find(42);

		printSetAttributes(fs, stl_default_set, ft_default_set);
		if (printSingleValue(fs, *stl_it, *ft_it) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_find_key_exist ";
	/* Find not exist*/
	{
		const int range_int[] = {14, 985, 578, -23, 47};

		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set.insert(range_int[i]);
			ft_default_set.insert(range_int[i]);
		}

		fs.open("./set_output/find_not_exist", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<int, std::string>::iterator stl_it = stl_default_set.find(42);
		ft::set<int, std::string>::iterator ft_it = ft_default_set.find(42);

		printSetAttributes(fs, stl_default_set, ft_default_set);
		if (printBoolResult(fs, (stl_it == stl_default_set.end()), (ft_it == ft_default_set.end())) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	 std::cout << "test_set_const_find_key_exist ";
	/* Const it Find */
	{
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::set<std::string> stl_default_set;
		ft::set<std::string> ft_default_set;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set.insert(range_str[i]);
			ft_default_set.insert(range_str[i]);
		}

		fs.open("./set_output/find_const_exist", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::set<std::string>::const_iterator stl_it = stl_default_set.find("One");
		ft::set<std::string>::const_iterator ft_it = ft_default_set.find("One");

		printSetAttributes(fs, stl_default_set, ft_default_set);
		if (printSingleValue(fs, *stl_it, *ft_it) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_set_count ";
	/* Count */
	{
		const int range_int[] = {842, 654, 95, -98, -8};

		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set.insert(range_int[i]);
			ft_default_set.insert(range_int[i]);
		}

		fs.open("./set_output/count", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printSetAttributes(fs, stl_default_set, ft_default_set);
		if (printBoolResult(fs, (stl_default_set.count(-98) > 0), (ft_default_set.count(-98) > 0)) == true
			&& printBoolResult(fs, (stl_default_set.count(42) > 0), (ft_default_set.count(42) > 0)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_lower_bound ";
	/* Lower bound */
	{
		const int range_int[] = {351, -999, 5, 76, 61};
		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set.insert(range_int[i]);
			ft_default_set.insert(range_int[i]);
		}

		fs.open("./set_output/lower_bound", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printSetAttributes(fs, stl_default_set, ft_default_set);

		std::set<int, std::string>::iterator stl_it = stl_default_set.lower_bound(80);
		ft::set<int, std::string>::iterator ft_it = ft_default_set.lower_bound(80);
		if (printSingleValue(fs, *stl_it, *ft_it)== true)
			  std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_set_const_lower_bound ";
	/* Const it Lower bound */
	{
		const int range_int[] = {554, 62, 345, 98, -77};

		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set.insert(range_int[i]);
			ft_default_set.insert(range_int[i]);
		}

		fs.open("./set_output/lower_bound_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printSetAttributes(fs, stl_default_set, ft_default_set);

		std::set<int, std::string>::const_iterator stl_it = stl_default_set.lower_bound(80);
		ft::set<int, std::string>::const_iterator ft_it = ft_default_set.lower_bound(80);
		if (printSingleValue(fs, *stl_it, *ft_it) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_upper_bound ";
	/* Upper bound */
	{
		const int range_int[] = {45, -84, 957, 966, 3};

		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set.insert(range_int[i]);
			ft_default_set.insert(range_int[i]);
		}

		fs.open("./set_output/upper_bound", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printSetAttributes(fs, stl_default_set, ft_default_set);

		std::set<int>::iterator stl_it = stl_default_set.upper_bound(950);
		ft::set<int>::iterator ft_it = ft_default_set.upper_bound(950);
		if (printSingleValue(fs, *stl_it, *ft_it) == true)
            std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_set_const_upper_bound ";
	/* Const it Upper bound */
	{
		const int range_int[] = {963, 654, 789, -9, 85};

		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set.insert(range_int[i]);
			ft_default_set.insert(range_int[i]);
		}
		fs.open("./set_output/upper_bound_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printSetAttributes(fs, stl_default_set, ft_default_set);

		std::set<int, std::string>::const_iterator stl_it = stl_default_set.upper_bound(950);
		ft::set<int, std::string>::const_iterator ft_it = ft_default_set.upper_bound(950);

		if (printSingleValue(fs, *stl_it, *ft_it) == true)
            std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_set_equal range ";
	/* Equal range */
	{
		const int range_int[] = {-741, 520, 65, -84, -1};

		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;

		for (int i = 0; i < 5; i++)
		{
			stl_default_set.insert(range_int[i]);
			ft_default_set.insert(range_int[i]);
		}
		fs.open("./set_output/equal_range_const", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printSetAttributes(fs, stl_default_set, ft_default_set);
		if (printSingleValue(fs, *stl_default_set.equal_range(65).first, *ft_default_set.equal_range(65).first)
			 && printSingleValue(fs, *stl_default_set.equal_range(65).second, *ft_default_set.equal_range(65).second))
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_set_compare: ";
	/*compare*/
	{
		ft::set<int> foo,bar;
		foo.insert(10);
		bar.insert(20);
		bar.insert(30);
		foo.insert(40);

		std::set<int> a,b;
		a.insert(10);
		b.insert(20);
		a.insert(30);
		b.insert(40);

		if ((foo==bar) == (a==b))
			std::cout << "test_set_operator==" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "test_set_operator==" << RED << "[NOP]" << NC << std::endl;

		if ((foo!=bar) == (a!=b))
			std::cout << "test_set_operator!=" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "test_set_operator!=" << RED << "[NOP]" << NC << std::endl;

		if ((foo<bar) == (a<b))
			std::cout << "test_set_operator<" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "test_set_operator<" << RED << "[NOP]" << NC << std::endl;

		if ((foo>bar) == (a>b))
			std::cout << "test_set_operator>" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "test_set_operator>" << RED << "[NOP]" << NC << std::endl;

		if ((foo>bar) == (a>b))
			std::cout << "test_set_operator<" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "test_set_operator<" << RED << "[NOP]" << NC << std::endl;
		if ((foo<=bar) == (a<=b))
			std::cout << "test_set_operator<=" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "test_set_operator<=" << RED << "[NOP]" << NC << std::endl;

		if ((foo>bar) == (a>=b))
			std::cout << "test_set_operator<=" << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << "test_set_operator<=" << RED << "[NOP]" << NC << std::endl;
	}
	std::cout << "test_map_balancy: ";
	{
		std::set<int> stl_default_set;
		ft::set<int> ft_default_set;
		for(int i=0; i < 1000; i++)
		{
			stl_default_set.insert(i);
			ft_default_set.insert(i);
		}
		fs.open("./set_output/test_balance", std::fstream::in | std::fstream::out | std::fstream::trunc);

		if (printSetAttributes(fs, stl_default_set, ft_default_set))
			    std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "\n";
}
