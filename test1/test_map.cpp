#include "test.hpp"

void test_item(std::string s)
{
	std::cout << "\n" << MAGENTA << s << NC << std::endl;
}

template <class Ta, class Tb>
void printMapAttributes(TESTED_NAMESPACE::map<Ta, Tb>& map)
{
	std::string empty = ((map.empty() == 1) ? "true" : "false");
	size_t size = map.size();
	size_t max_size = map.max_size();

	std::cout << "══════════════════════════════════════════════════════════════\n";
	std::cout << "maps attributes : \n";
	std::cout << "Empty       : " << empty  << std::endl;
	std::cout << "Size        : " << size  << std::endl;
	std::cout << "Max size    : " << max_size  << std::endl;
	std::cout << "Content     : [";

	typename TESTED_NAMESPACE::map<Ta, Tb>::const_iterator it;
	for (it = map.begin();  it != map.end(); it++)
	{
		std::cout << "[" <<  (*it).first << ", " << (*it).second << "]";
		if (it != --map.end())
			std::cout << " ,";
	}
	std::cout << "]\n";
	std::cout << std::endl;
}

void test_map()
{
	{
		test_item("default construct");
		TESTED_NAMESPACE::map<int, std::string> map;
		get_time_distance();
		printMapAttributes(map);
		get_time_distance();
	}
	{
		test_item("range construct and copy by iterator");
		const int range_int[] = {-652, -4, 98, 54, -210};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};
		TESTED_NAMESPACE::map<int, std::string> map;
		for (int i = 0; i < 5; i++)
			map.insert(TESTED_NAMESPACE::make_pair(range_int[i], range_str[i]));
		TESTED_NAMESPACE::map<int, std::string> copy_map(map.begin(), map.end());
		printMapAttributes(map);
		printMapAttributes(copy_map);
		get_time_distance();
	}
	{
		test_item("range construct and copy constructor");
		TESTED_NAMESPACE::map<char,int> first;
		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;
		TESTED_NAMESPACE::map<char,int> second (first.begin(),first.end());
		printMapAttributes(first);
		printMapAttributes(second);
		get_time_distance();
		TESTED_NAMESPACE::map<char,int> third (second);
		printMapAttributes(third);
		get_time_distance();
		test_item("operator_assign");
		TESTED_NAMESPACE::map<char,int> forth = first;
		printMapAttributes(forth);
		get_time_distance();
	}
	{
		test_item("assign");
		TESTED_NAMESPACE::map<char,int> first;
		first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;
		TESTED_NAMESPACE::map<char,int> second = first;
		printMapAttributes(second);
		get_time_distance();
	}
	{
		test_item("begin and end");
		const int range_int[] = {1485, 5, 89, 652, -94};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};

		TESTED_NAMESPACE::map<int, std::string> map;
		for (int i = 0; i < 5; i++)
			map.insert(TESTED_NAMESPACE::make_pair(range_int[i], range_str[i]));
		TESTED_NAMESPACE::map<int, std::string>::iterator it = map.begin();
		TESTED_NAMESPACE::map<int, std::string>::iterator end_it = map.end();
		--end_it;
		std::cout << "begin first " << (*it).first << " second " << (*it).second << std::endl;
		std::cout << "end first " << (*end_it).first << " second " << (*end_it).second << std::endl;
		get_time_distance();
		test_item("const begin and end");
		TESTED_NAMESPACE::map<int, std::string>::const_iterator c_it = map.begin();
		TESTED_NAMESPACE::map<int, std::string>::const_iterator c_end_it = map.end();
		--c_end_it;
		std::cout << "const begin first " << (*c_it).first << " second " << (*c_it).second << std::endl;
		std::cout << "const end first " << (*c_end_it).first << " second " << (*c_end_it).second << std::endl;
		get_time_distance();
		test_item("rbegin and const rbegin");
		TESTED_NAMESPACE::map<int, std::string>::reverse_iterator r_it = map.rbegin();
		TESTED_NAMESPACE::map<int, std::string>::const_reverse_iterator const_r_it = map.rbegin();
		std::cout << "rbegin first " << (*r_it).first << " second " << (*r_it).second << std::endl;
		std::cout << "const rbegin first " << (*const_r_it).first << " second " << (*const_r_it).second << std::endl;
		get_time_distance();
		test_item("rend and const rend");
		TESTED_NAMESPACE::map<int, std::string>::reverse_iterator r_end =  map.rend();
		TESTED_NAMESPACE::map<int, std::string>::const_reverse_iterator const_r_end =  map.rend();
		--r_end;
		--const_r_end;
		std::cout << "rend first " << (*r_end).first << " second " << (*r_end).second << std::endl;
		std::cout << "const rend first " << (*const_r_end).first << " second " << (*const_r_end).second << std::endl;
		get_time_distance();
	}
	{
		test_item("test operator []");
		TESTED_NAMESPACE::map<int,int> first;
		first[0]=10;
		first[1]=30;
		first[2]=50;
		first[3]=70;
		first[-1]=70;
		std::cout << "first[-9] is " << first[-9] << std::endl;
		get_time_distance();
		std::cout << "first[2] is " << first[2] << std::endl;
		get_time_distance();
		printMapAttributes(first);
		get_time_distance();
	}
	{
		test_item("test insert single");
		TESTED_NAMESPACE::map<int, std::string> map;
		map.insert(TESTED_NAMESPACE::make_pair(42, "La famille"));
		printMapAttributes(map);
		get_time_distance();
		test_item("hint insert");
		const int range_int[] = {584, 96, 21, -54, 36};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};
		for (int i = 0; i < 5; i++)
			map.insert(TESTED_NAMESPACE::make_pair(range_int[i], range_str[i]));
		printMapAttributes(map);
		get_time_distance();
		test_item("insert range");
		const int arr[] = {754, -985, 58, 999, 5};
		const std::string range_str0[] = {"One0", "Two0", "Three0", "Four0", "Five0"};
		TESTED_NAMESPACE::map<int, std::string> map0;
		for (int i = 0; i < 5; i++)
			map0.insert(TESTED_NAMESPACE::make_pair(arr[i], range_str0[i]));
		map.insert(map0.begin(), map0.end());
		printMapAttributes(map);
		get_time_distance();
		test_item("erase");
		map.erase(map.begin());
		get_time_distance();
		printMapAttributes(map);
		get_time_distance();
		test_item("erase key");
		map.erase(-98);
		get_time_distance();
		printMapAttributes(map);
		get_time_distance();
		map.erase(96);
		printMapAttributes(map);
        get_time_distance();
		TESTED_NAMESPACE::map<int, std::string>::iterator it = map.end();
		--it;
		--it;
		map.erase(map.begin(), it);
		printMapAttributes(map);
        get_time_distance();
	}
	{
		test_item("swap");
		const int range_int[] = {489, 851, 32, -98, 8};
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};
		TESTED_NAMESPACE::map<int, std::string> map, map0;
		for (int i = 0; i < 5; i++)
		{
			map.insert(TESTED_NAMESPACE::make_pair(range_int[i], range_str[i]));
			map0.insert(TESTED_NAMESPACE::make_pair(range_int[i] + 888, range_str[i]));
		}
		map.swap(map0);
		get_time_distance();
		printMapAttributes(map);
		printMapAttributes(map0);
		get_time_distance();
		test_item("clear");
		map.clear();
		printMapAttributes(map);
		get_time_distance();
		test_item("key cmp");
		TESTED_NAMESPACE::map<int, std::string>::key_compare key =  TESTED_NAMESPACE::map<int, std::string>().key_comp();
		std::cout << key(42, 99) << std::endl;
		get_time_distance();
		test_item("value cmp");
		TESTED_NAMESPACE::map<int, std::string>::value_compare v =  TESTED_NAMESPACE::map<int, std::string>().value_comp();
		bool result = v(TESTED_NAMESPACE::make_pair(99, "End"), TESTED_NAMESPACE::make_pair(42, "Noice"));
		std::cout << result << std::endl;
		get_time_distance();

		test_item("find");
		TESTED_NAMESPACE::map<int, std::string>::iterator it = map.find(42);
		if (it == map.end())
			std::cout << "no found" << std::endl;
		it = map0.find(-98);
		std::cout << (*it).first << " " << (*it).second << std::endl;
	}
	{
		TESTED_NAMESPACE::map<std::string, int> m1;
		for (int i = 0; i < 30; ++i)
		{
			std::ostringstream ss;
			ss << "test" << i;
			m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
		}

		test_item("count");
		std::cout << m1.count("test1") << std::endl;
		std::cout << m1.count("test2") << std::endl;
		std::cout << m1.count("test3") << std::endl;
		std::cout << m1.count("test4") << std::endl;
		std::cout << m1.count("test5") << std::endl;
		std::cout << m1.count("does not exist") << std::endl;
		get_time_distance();
	}
	{
		test_item("lower_bound");
		TESTED_NAMESPACE::map<std::string, int> m1;
		for (int i = 0; i < 10; ++i)
		{
			std::ostringstream ss;
			ss << "petit bao" << i;
			m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
		}
		std::cout << m1.lower_bound("petit bao1")->second << std::endl;
		std::cout << m1.lower_bound("petit bao2")->second << std::endl;
		std::cout << m1.lower_bound("petit bao3")->second << std::endl;
		std::cout << m1.lower_bound("petit bao4")->second << std::endl;
		std::cout << m1.lower_bound("petit bao5")->second << std::endl;
		std::cout << m1.lower_bound("does not exist")->second << std::endl;
		get_time_distance();
	}
	{
		test_item("upper_bound");
		TESTED_NAMESPACE::map<std::string, int> m1;
		for (int i = 0; i < 30; ++i)
		{
			std::ostringstream ss;
			ss << "test" << i;
			m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
		}
		std::cout << m1.upper_bound("test1")->second << std::endl;
		std::cout << m1.upper_bound("test2")->second << std::endl;
		std::cout << m1.upper_bound("test3")->second << std::endl;
		std::cout << m1.upper_bound("test4")->second << std::endl;
    std::cout << m1.upper_bound("test5")->second << std::endl;
    std::cout << m1.upper_bound("does not exist")->second << std::endl;
	get_time_distance();
	}
	{
		test_item("equal_range");
		TESTED_NAMESPACE::map<std::string, int> m1;
		for (int i = 0; i < 30; ++i)
		{
			std::ostringstream ss;
			ss << "test" << i;
			m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
		}
		std::cout << m1.equal_range("test1").first->first << std::endl;
		std::cout << m1.equal_range("test1").second->first << std::endl;
		std::cout << m1.equal_range("test2").first->first << std::endl;
		std::cout << m1.equal_range("test2").second->first << std::endl;
		std::cout << m1.equal_range("test3").first->first << std::endl;
		std::cout << m1.equal_range("test3").second->first << std::endl;
		std::cout << m1.equal_range("test4").first->first << std::endl;
		std::cout << m1.equal_range("test4").second->first << std::endl;
		std::cout << m1.equal_range("test5").first->first << std::endl;
		std::cout << m1.equal_range("test5").second->first << std::endl;
		std::cout << m1.equal_range("does not exist").first->first << std::endl;
		get_time_distance();
	}
	{
		TESTED_NAMESPACE::map<std::string, int> m1;
		for (int i = 0; i < 30; ++i)
		{
			std::ostringstream ss;
			ss << "test" << i;
			m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
		}
		TESTED_NAMESPACE::map<std::string, int> m2;
		for (int i = 0; i < 30; ++i)
		{
			std::ostringstream ss;
			ss << "gest" << i;
			m2.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
		}
		test_item("map::operator==");
		std::cout << (m1 == m2) << std::endl;
		get_time_distance();

		test_item("map::operator!=");
		std::cout << (m1 != m2) << std::endl;
		std::cout << (m1 != m1) << std::endl;
		get_time_distance();

		test_item("map::operator<");
		std::cout << (m1 < m2) << std::endl;
		std::cout << (m2 < m1) << std::endl;
		std::cout << (m1 < m1) << std::endl;
		get_time_distance();

		test_item("map::operator<=");
		std::cout << (m1 <= m2) << std::endl;
		std::cout << (m2 <= m1) << std::endl;
		std::cout << (m1 <= m1) << std::endl;
		get_time_distance();

		test_item("map::operator>");
		std::cout << (m1 > m2) << std::endl;
		std::cout << (m2 > m1) << std::endl;
		std::cout << (m1 > m1) << std::endl;
		get_time_distance();

		test_item("map::operator>=");
		std::cout << (m1 >= m2) << std::endl;
		std::cout << (m2 >= m1) << std::endl;
		std::cout << (m1 >= m1) << std::endl;
		get_time_distance();
	}
	{
		test_item("map::swap");
		TESTED_NAMESPACE::map<std::string, int> m1;
		for (int i = 0; i < 30; ++i)
		{
			std::ostringstream ss;
			ss << "test" << i;
			m1.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
		}
		TESTED_NAMESPACE::map<std::string, int> m2;
		for (int i = 0; i < 30; ++i)
		{
			std::ostringstream ss;
        ss << "gest" << i;
        m2.insert(TESTED_NAMESPACE::make_pair(ss.str(), i));
		}
		m1.swap(m2);
		get_time_distance();
		printMapAttributes(m1);
		printMapAttributes(m2);
		get_time_distance();
	}
	{
		test_item("Balance TEST");
		TESTED_NAMESPACE::map<int, int> m1;
		for(int i=0; i < 1000; i++)
			m1.insert(TESTED_NAMESPACE::make_pair(i, i));
		printMapAttributes(m1);
		get_time_distance();
	}
}
