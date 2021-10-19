#include "test.hpp"

bool printBoolResult(std::fstream& fs, bool stl_bool, bool ft_bool)
{
    fs << "\nBool result : \n";
    fs << " - STL : " << (stl_bool ? "true" : "false") << std::endl;
    fs << " - FT  : " << (ft_bool ? "true" : "false") << std::endl;

    return (stl_bool == ft_bool);
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

template <class Ta, class Tb>
std::string equalContent(
	const std::map<Ta, Tb> & stl_map,
	const ft::map<Ta, Tb> & ft_map
)
{
	typename ft::map<Ta, Tb>::const_iterator ft_it;
	typename std::map<Ta, Tb>::const_iterator stl_it;
	if (ft_map.size() != stl_map.size())
		return ("✘");
	stl_it = stl_map.begin();
	for(ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++)
	{
		if ((*ft_it).first != (*stl_it).first || (*ft_it).second != (*stl_it).second)
			return ("✘");
		stl_it++;
	}
	return ("✔");
}

template <class Ta, class Tb>
bool printMapAttributes(
	std::fstream& fs,
	std::map<Ta, Tb>& stl_map,
	ft::map<Ta, Tb>& ft_map
)
{
	/* STL Values */
	std::string stl_empty = ((stl_map.empty() == 1) ? "true" : "false");
	size_t stl_size = stl_map.size();
	size_t stl_max_size = stl_map.max_size();

	/* FT Values */
	std::string ft_empty = ((ft_map.empty() == 1) ? "true" : "false");
	size_t ft_size = ft_map.size();
	size_t ft_max_size = ft_map.max_size();

	/* FT Result compare values */
	bool empty = equalbool(ft_empty, stl_empty);
	bool size = equalbool(ft_size, stl_size);
	bool max_size = equalbool(ft_max_size, stl_max_size);
	std::string content = equalContent(stl_map, ft_map);

	fs << "\n══════════════════════════════════════════════════════════════\n";
	fs << "maps attributes : \n";
	fs << "STL : \n";
	fs << "Empty       : " << stl_empty  << std::endl;
	fs << "Size        : " << stl_size  << std::endl;
	fs << "Max size    : " << stl_max_size  << std::endl;
	fs << "Content     : [";

	typename std::map<Ta, Tb>::const_iterator stl_it;
	for (stl_it = stl_map.begin();  stl_it != stl_map.end(); stl_it++)
	{
		fs << "[";
		fs << (*stl_it).first;
		fs << ", ";
		fs << (*stl_it).second;
		fs << "]";
		fs << ", ";
	}
	fs << "]\n";

	fs << std::endl;

	fs << "FT : \n";
	fs << "Empty    [" << equal(ft_empty, stl_empty) << "]: " << ft_empty  << std::endl;
	fs << "Size     [" << equal(ft_size, stl_size) << "]: " << ft_size  << std::endl;
	fs << "Max size [" << equal(ft_max_size, stl_max_size) << "]: " << ft_max_size  << std::endl;

	fs << "Content  [" << content << "]: [";

	typename ft::map<Ta, Tb>::const_iterator ft_it;
	for(ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++)
	{
		fs << "[";
		fs << (*ft_it).first;
		fs << ", ";
		fs << (*ft_it).second;
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

template<class T, class U>
void show_res(std::fstream &fs, std::map<T, U>&his_map, ft::map<T, U>&my_map)
	{
		if (printMapAttributes(fs, his_map, my_map) == true)
			std::cout << GREEN << "[OK]\n" << NC;
		else
			std::cout << RED << "[NOP]\n" << NC;
		fs.close();
	}

void test_map()
{

	std::cout << UNDERLINE << "MAP :\n" << NC ;

	mkdir("./maps_output", 0777);

	std::fstream fs;

	/* Constructors */
	std::cout << "test_map_constructors ";

	/* Default constructor */
	{
		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		fs.open("./maps_output/constructor_default", std::fstream::in | std::fstream::out | std::fstream::trunc);
		show_res(fs, stl_default_map, ft_default_map);
	}
	std::cout << "test_map_range_constructor ";
	/* Range constrcutor */
	{
		const int range_int[] = {-652, -4, 98, 54, -210};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}
		fs.open("./maps_output/constructor_range", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string> stl_map_copy(stl_map.begin(), stl_map.end());
		ft::map<int, std::string> ft_map_copy(ft_map.begin(), ft_map.end());

		show_res(fs, stl_map_copy, ft_map_copy);
	}
	std::cout << "test_map_copy_constructor ";
	/* Copy constructor */
	{
		const int range_int[] = {842, 695, -98, -2, -4};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/constructor_copy", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string> stl_map_copy(stl_map);
		ft::map<int, std::string> ft_map_copy(ft_map);
		show_res(fs, stl_map_copy, ft_map_copy);
		fs.close();
	}

	std::cout << "test_map_operator= ";
	/* Assign operator */
	{
		const int range_int[] = {478, 952, 12, -96, -9};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/operator_assign", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string> stl_map_copy = stl_map;
		ft::map<int, std::string> ft_map_copy = ft_map;
		show_res(fs, stl_map_copy, ft_map_copy);
		fs.close();
	}

	std::cout << "test_map_iterator_begin ";
	/* Begin */
	{
		const int range_int[] = {1485, 5, 89, 652, -94};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/begin", std::fstream::in | std::fstream::out | std::fstream::trunc);

		if (printMapAttributes(fs, stl_map, ft_map) == true &&
			printSingleValue(fs, (*stl_map.begin()).first, (*ft_map.begin()).first) &&
			printSingleValue(fs, (*stl_map.begin()).second, (*ft_map.begin()).second))
			std::cout << GREEN << "[OK]\n" << NC;
		else
			std::cout << RED << "[NOP]\n" << NC;
		fs.close();
	}

	 std::cout << "test_map_const_iterator_begin ";
	/* Const begin */
	{
		const int range_int[] = {48, 9, 12, 63, 99};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/begin_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string>::const_iterator stl_it = stl_map.begin();
		ft::map<int, std::string>::const_iterator ft_it = ft_map.begin();

		if (printMapAttributes(fs, stl_map, ft_map) == true &&
			printSingleValue(fs, (*stl_it).first, (*ft_it).first) &&
			printSingleValue(fs, (*stl_it).second, (*ft_it).second))
			std::cout << GREEN << "[OK]\n" << NC;
		else
			std::cout << RED << "[NOP]\n" << NC;
		fs.close();
	}

	std::cout << "test_map_iterator_end ";
	/* End */
	{
		const int range_int[] = {-99, 584, 965, 366, 77};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/end", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string>::iterator stl_it = stl_map.end();
		ft::map<int, std::string>::iterator ft_it = ft_map.end();

		--stl_it;
		--ft_it;

		if (printMapAttributes(fs, stl_map, ft_map) == true &&
			printSingleValue(fs, (*stl_it).first, (*ft_it).first) &&
			printSingleValue(fs, (*stl_it).second, (*ft_it).second))
			std::cout << GREEN << "[OK]\n" << NC;
		else
			 std::cout << RED << "[NOP]\n" << NC;
		fs.close();
	}

	std::cout << "test_map_const_iterator_end ";
	/* Const end */
	{
		const int range_int[] = {154, 966, 3, -84, 75};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/end_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string>::const_iterator stl_it = stl_map.end();
		ft::map<int, std::string>::const_iterator ft_it = ft_map.end();

		--stl_it;
		--ft_it;
		if (printMapAttributes(fs, stl_map, ft_map) == true &&
			printSingleValue(fs, (*stl_it).first, (*ft_it).first) &&
			printSingleValue(fs, (*stl_it).second, (*ft_it).second))
			std::cout << GREEN << "[OK]\n" << NC;
		else
			std::cout << RED << "[NOP]\n" << NC;
		fs.close();
	}

	std::cout << "test_map_rebegin_test ";
	/* Reverse begin */
	{
		const int range_int[] = {1458, -985, 58, 632, 65};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/reverse_begin", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string>::reverse_iterator stl_it = stl_map.rbegin();
		ft::map<int, std::string>::reverse_iterator ft_it = ft_map.rbegin();

		if (!printMapAttributes(fs, stl_map, ft_map))
		{
			std::cout << RED << "[NOP]"  << NC << std::endl;
			fs.close();
		}

		else
		{
			++stl_it;
			++ft_it;
			if (printSingleValue(fs, (*stl_it).first, (*ft_it).first) &&
				printSingleValue(fs, (*stl_it).second, (*ft_it).second))
				std::cout << GREEN << "[OK]" << NC << std::endl;
			else
				std::cout << RED << "[NOP]"  << NC << std::endl;
			fs.close();
		}
	}

	std::cout << "const_reverse_begin ";
	/* Const reverse begin */
	{
		const int range_int[] = {859, 99, -325, -65, -98};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/reverse_begin_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string>::const_reverse_iterator stl_it = stl_map.rbegin();
		ft::map<int, std::string>::const_reverse_iterator ft_it = ft_map.rbegin();

		if (!printMapAttributes(fs, stl_map, ft_map))
		{
			std::cout << RED << "[NOP]"  << NC << std::endl;
			fs.close();
		}
		else
		{
			if (printSingleValue(fs, (*stl_it).first, (*ft_it).first) == true &&
				printSingleValue(fs, (*stl_it).second, (*ft_it).second) == true)
				std::cout << GREEN << "[OK]" << NC << std::endl;
			else
				std::cout << RED << "[NOP]"  << NC << std::endl;
			fs.close();
		}
	}
	std::cout << "test_map_reverse_end ";
	/* Reverse end */
	{
		const int range_int[] = {325, -657, -942, -8, 66};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/reverse_end", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string>::reverse_iterator stl_it = stl_map.rend();
		ft::map<int, std::string>::reverse_iterator ft_it = ft_map.rend();
		--stl_it;
		--ft_it;

		if (!printMapAttributes(fs, stl_map, ft_map))
		{
			std::cout << RED << "[NOP]"  << NC << std::endl;
			fs.close();
		}
		else
		{
			if (printSingleValue(fs, (*stl_it).first, (*ft_it).first) == true &&
				printSingleValue(fs, (*stl_it).second, (*ft_it).second) == true)
				std::cout << GREEN << "[OK]" << NC << std::endl;
			else
				std::cout << RED << "[NOP]"  << NC << std::endl;
			fs.close();
		}
	}
	std::cout << "test_map_const _reverse_end ";
	/* Const reverse end */
	{
		const int range_int[] = {-99, 584, 965, 366, 77};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/reverse_end_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string>::const_reverse_iterator stl_it = stl_map.rend();
		ft::map<int, std::string>::const_reverse_iterator ft_it = ft_map.rend();
		--(--stl_it);
		--(--ft_it);
		if (!printMapAttributes(fs, stl_map, ft_map))
			std::cout << RED << "[NOP]" << NC << std::endl;
		else if (printSingleValue(fs, (*stl_it).first, (*ft_it).first) == true
			&& printSingleValue(fs, (*stl_it).second, (*ft_it).second) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_empty_true ";
	/* Empty true */
	{
		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		fs.open("./maps_output/empty_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printMapAttributes(fs, stl_default_map, ft_default_map) && printBoolResult(fs, stl_default_map.empty(), ft_default_map.empty()))
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_empty_false ";
	/* Empty false */
	{
		const int range_int[] = {1452, 3651, -98, 84, 899};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/empty_false", std::fstream::in | std::fstream::out | std::fstream::trunc);

		if (printMapAttributes(fs, stl_map, ft_map) && printBoolResult(fs, stl_map.empty(), ft_map.empty()))
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}

	std::cout << "test_map_size ";
	/* Size */
	{
		const int range_int[] = {9, -84, -45, -67, -9};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/size", std::fstream::in | std::fstream::out | std::fstream::trunc);

		stl_map.insert(std::make_pair(42, "Represent"));
		ft_map.insert(ft::make_pair(42, "Represent"));
		if (printMapAttributes(fs, stl_map, ft_map) && printSingleValue(fs, stl_map.size(), ft_map.size()))
			 std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}

	std::cout << "test_map_max_size ";
	/* Maximum size */
	{
		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		fs.open("./maps_output/max_size", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printMapAttributes(fs, stl_default_map, ft_default_map) && printSingleValue(fs, stl_default_map.max_size(), ft_default_map.max_size()))
			 std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	/*operator []*/
	std::cout << "test_map_operator[] ";
	{
		const int range_int[] = {1489, -98, -9, -46, 256};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/operator_at", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printMapAttributes(fs, stl_map, ft_map);

		if (printSingleValue(fs, stl_map[-9], ft_map[-9]) == true)
		{
			 stl_map[-9] = "Changed";
			 ft_map[-9] = "Changed";
			 if (printSingleValue(fs, stl_map[-9], ft_map[-9]) == true)
				 std::cout << GREEN << "[OK]" << NC << std::endl;
		}
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_insert_single ";
	/*insert single*/
	{
		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		stl_map.insert(std::make_pair(42, "La famille"));
		ft_map.insert(ft::make_pair(42, "La famille"));

		fs.open("./maps_output/insert_single", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printMapAttributes(fs, stl_map, ft_map) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_insert_hint ";
	/*hint insert*/
	{
		const int range_int[] = {584, 96, 21, -54, 36};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/insert_hint", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printMapAttributes(fs, stl_map, ft_map);

		stl_map.insert(++(stl_map.begin()), std::make_pair(42, "Nice"));
		ft_map.insert(++(ft_map.begin()), ft::make_pair(42, "Nice"));

		if (printMapAttributes(fs, stl_map, ft_map) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_insert_range ";
	/* Insert Range */
	{
		const int range_int[] = {754, -985, 58, 999, 5};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map_one;
		ft::map<int, std::string> ft_map_one;
		std::map<int, std::string> stl_map_two;
		ft::map<int, std::string> ft_map_two;

		for (int i = 0; i < 5; i++)
		{
			stl_map_one.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map_one.insert(ft::make_pair(range_int[i], range_str[i]));
			stl_map_two.insert(std::make_pair(range_int[i] + 266, range_str[i] + "_two"));
			ft_map_two.insert(ft::make_pair(range_int[i] + 266, range_str[i] + "_two"));
		}

		fs.open("./maps_output/insert_range", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printMapAttributes(fs, stl_map_one, ft_map_one);
		printMapAttributes(fs, stl_map_two, ft_map_two);

		stl_map_one.insert(stl_map_two.begin(), stl_map_two.end());
		ft_map_one.insert(ft_map_two.begin(), ft_map_two.end());

		if (printMapAttributes(fs, stl_map_one, ft_map_one) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	/* Erase single */
	std::cout << "test_map_erase ";
	{
		const int range_int[] = {-9, -84, -77, 24, 56};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/erase_single", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printMapAttributes(fs, stl_map, ft_map);

		stl_map.erase(stl_map.begin());
		ft_map.erase(ft_map.begin());

		if (printMapAttributes(fs, stl_map, ft_map) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	/* Erase key */
	std::cout << "test_map_erase_key";
	{
		const int range_int[] = {1452, 3651, -98, 84, 899};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_map;
		ft::map<int, std::string> ft_map;

		for (int i = 0; i < 5; i++)
		{
			stl_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/erase_key", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printMapAttributes(fs, stl_map, ft_map);

		stl_map.erase(-98);
		ft_map.erase(-98);

		if (printMapAttributes(fs, stl_map, ft_map) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_erase_range";
	/* Erase range */
	{
        const int range_int[] = {-854, 1, 965, -9, 755};
        const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

        for (int i = 0; i < 5; i++)
        {
            stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
            ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
        }

		fs.open("./maps_output/erase_range", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printMapAttributes(fs, stl_default_map, ft_default_map);

		std::map<int, std::string>::iterator stl_it_beg = stl_default_map.begin();
		ft::map<int, std::string>::iterator ft_it_beg = ft_default_map.begin();
		std::map<int, std::string>::iterator stl_it_end = stl_default_map.end();
		ft::map<int, std::string>::iterator ft_it_end = ft_default_map.end();

		for (int i = 0; i < 2; i++)
		{
			stl_it_beg++;
			ft_it_beg++;
		}
		stl_it_end--;
		ft_it_end--;

        stl_default_map.erase(stl_it_beg, stl_it_end);
        ft_default_map.erase(ft_it_beg, ft_it_end);

		if (printMapAttributes(fs, stl_default_map, ft_default_map) == true)
            std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_map_swap ";
	/* Swap */
	{
		const int range_int[] = {489, 851, 32, -98, 8};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map_one;
		ft::map<int, std::string> ft_default_map_one;
		std::map<int, std::string> stl_default_map_two;
		ft::map<int, std::string> ft_default_map_two;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map_one.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map_one.insert(ft::make_pair(range_int[i], range_str[i]));
			stl_default_map_two.insert(std::make_pair(range_int[i] + 120, range_str[i]));
			ft_default_map_two.insert(ft::make_pair(range_int[i] + 120, range_str[i]));
		}

		fs.open("./maps_output/swap", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printMapAttributes(fs, stl_default_map_one, ft_default_map_one);
		printMapAttributes(fs, stl_default_map_two, ft_default_map_two);

		stl_default_map_one.swap(stl_default_map_two);
		ft_default_map_one.swap(ft_default_map_two);

		if (printMapAttributes(fs, stl_default_map_one, ft_default_map_one) == true &&
			printMapAttributes(fs, stl_default_map_two, ft_default_map_two) == true)
			 std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_map_clear ";
	/* Clear */
	{
		const int range_int[] = {148, 9874, -987, 52, 96};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/clear", std::fstream::in | std::fstream::out | std::fstream::trunc);
		printMapAttributes(fs, stl_default_map, ft_default_map);

		stl_default_map.clear();
		ft_default_map.clear();

		if (printMapAttributes(fs, stl_default_map, ft_default_map) == true)
			 std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_key_comp";
	/* Key comp */
	{
		std::map<int, std::string>::key_compare stl_key = std::map<int, std::string>().key_comp();
		ft::map<int, std::string>::key_compare ft_key = ft::map<int, std::string>().key_comp();

		bool stl_res = stl_key(42, 99);
		bool ft_res = ft_key(42, 99);

		fs.open("./maps_output/key_comp", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printBoolResult(fs, stl_res, ft_res))
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_map_value_comp";
	/* Value comp */
	{
		std::map<int, std::string>::value_compare stl_key = std::map<int, std::string>().value_comp();
		ft::map<int, std::string>::value_compare ft_key = ft::map<int, std::string>().value_comp();

		bool stl_res = stl_key(std::make_pair(99, "End"), std::make_pair(42, "Noice"));
		bool ft_res = ft_key(ft::make_pair(99, "End"), ft::make_pair(42, "Noice"));

		fs.open("./maps_output/value_comp", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printBoolResult(fs, stl_res, ft_res) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	 std::cout << "test_map_find_key_not_exist ";
	/* Find exist */
	{
		const int range_int[] = {954, 12, -965, 42, 1000};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/find_exist", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string>::iterator stl_it = stl_default_map.find(42);
		ft::map<int, std::string>::iterator ft_it = ft_default_map.find(42);

		printMapAttributes(fs, stl_default_map, ft_default_map);
		if (printSingleValue(fs, (*stl_it).first, (*ft_it).first) == true &&
			printSingleValue(fs, (*stl_it).second, (*ft_it).second) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_map_find_key_exist ";
	/* Find not exist*/
	{
		const int range_int[] = {14, 985, 578, -23, 47};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/find_not_exist", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string>::iterator stl_it = stl_default_map.find(42);
		ft::map<int, std::string>::iterator ft_it = ft_default_map.find(42);

		printMapAttributes(fs, stl_default_map, ft_default_map);
		if (printBoolResult(fs, (stl_it == stl_default_map.end()), (ft_it == ft_default_map.end())) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	 std::cout << "test_map_const_find_key_exist ";
	/* Const it Find */
	{
		const int range_int[] = {842, -965, 99, 52, 65};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/find_const_exist", std::fstream::in | std::fstream::out | std::fstream::trunc);

		std::map<int, std::string>::const_iterator stl_it = stl_default_map.find(99);
		ft::map<int, std::string>::const_iterator ft_it = ft_default_map.find(99);

		printMapAttributes(fs, stl_default_map, ft_default_map);
		if (printSingleValue(fs, (*stl_it).first, (*ft_it).first) == true &&
			printSingleValue(fs, (*stl_it).second, (*ft_it).second) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_map_count ";
	/* Count */
	{
		const int range_int[] = {842, 654, 95, -98, -8};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/count", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printMapAttributes(fs, stl_default_map, ft_default_map);
		if (printBoolResult(fs, (stl_default_map.count(-98) > 0), (ft_default_map.count(-98) > 0)) == true
			&& printBoolResult(fs, (stl_default_map.count(42) > 0), (ft_default_map.count(42) > 0)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_lower_bound ";
	/* Lower bound */
	{
		const int range_int[] = {351, -999, 5, 76, 61};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/lower_bound", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printMapAttributes(fs, stl_default_map, ft_default_map);

		std::map<int, std::string>::iterator stl_it = stl_default_map.lower_bound(80);
		ft::map<int, std::string>::iterator ft_it = ft_default_map.lower_bound(80);
		if (printSingleValue(fs, (*stl_it).first, (*ft_it).first) == true
			&& printSingleValue(fs, (*stl_it).second, (*ft_it).second) == true)
			  std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_map_const_lower_bound ";
	/* Const it Lower bound */
	{
		const int range_int[] = {554, 62, 345, 98, -77};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/lower_bound_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printMapAttributes(fs, stl_default_map, ft_default_map);

		std::map<int, std::string>::const_iterator stl_it = stl_default_map.lower_bound(80);
		ft::map<int, std::string>::const_iterator ft_it = ft_default_map.lower_bound(80);
		if (printSingleValue(fs, (*stl_it).first, (*ft_it).first) == true
			&& printSingleValue(fs, (*stl_it).second, (*ft_it).second) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_upper_bound ";
	/* Upper bound */
	{
		const int range_int[] = {45, -84, 957, 966, 3};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/upper_bound", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printMapAttributes(fs, stl_default_map, ft_default_map);

		std::map<int, std::string>::iterator stl_it = stl_default_map.upper_bound(950);
		ft::map<int, std::string>::iterator ft_it = ft_default_map.upper_bound(950);
		if (printSingleValue(fs, (*stl_it).first, (*ft_it).first) == true
			  && printSingleValue(fs, (*stl_it).second, (*ft_it).second) == true)
            std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_map_const_upper_bound ";
	/* Const it Upper bound */
	{
		const int range_int[] = {963, 654, 789, -9, 85};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/upper_bound_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printMapAttributes(fs, stl_default_map, ft_default_map);

		std::map<int, std::string>::const_iterator stl_it = stl_default_map.upper_bound(950);
		ft::map<int, std::string>::const_iterator ft_it = ft_default_map.upper_bound(950);

		if (printSingleValue(fs, (*stl_it).first, (*ft_it).first) == true
			&& printSingleValue(fs, (*stl_it).second, (*ft_it).second) == true)
            std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_map_equal range ";
	/* Equal range */
	{
		const int range_int[] = {-741, 520, 65, -84, -1};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		std::map<int, std::string> stl_default_map;
		ft::map<int, std::string> ft_default_map;

		for (int i = 0; i < 5; i++)
		{
			stl_default_map.insert(std::make_pair(range_int[i], range_str[i]));
			ft_default_map.insert(ft::make_pair(range_int[i], range_str[i]));
		}

		fs.open("./maps_output/equal_range_const", std::fstream::in | std::fstream::out | std::fstream::trunc);

		printMapAttributes(fs, stl_default_map, ft_default_map);

		if (printSingleValue(fs, (*(stl_default_map.equal_range(65).first)).first, (*(ft_default_map.equal_range(65).first)).first) == true
			&& printSingleValue(fs, (*(stl_default_map.equal_range(65).second)).first, (*(ft_default_map.equal_range(65).second)).first) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_map_compare: ";
	/*compare*/
	{
		ft::map<char,int> foo,bar;
		foo['a']=100;
		foo['b']=200;
		bar['a']=10;
		bar['z']=1000;

		if ((foo!=bar) && (foo> bar) && (foo>=bar) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;;
		if ((foo!=bar) && (foo> bar) && (foo>=bar) == false)
			std::cout << RED << "[NOP]" << NC << std::endl;
	}
	std::cout << "test_map_balancy: ";
	{
		std::map<int, int> stl_default_map;
		ft::map<int, int> ft_default_map;
		for(int i=0; i < 1000; i++)
		{
			stl_default_map.insert(std::make_pair(i, i));
			ft_default_map.insert(ft::make_pair(i, i));
		}
		fs.open("./maps_output/test_balance", std::fstream::in | std::fstream::out | std::fstream::trunc);

		if (printMapAttributes(fs, stl_default_map, ft_default_map))
			    std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();

	}
	std::cout << "\n";
}
