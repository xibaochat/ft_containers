#include "test.hpp"

void test_item_set(std::string s)
{
	std::cout << "\n" << ORANGE << s << NC << std::endl;
}

template <class T>
void printSetAttributes(TESTED_NAMESPACE::set<T>& s)
{
	std::string empty = ((s.empty() == 1) ? "true" : "false");
	size_t size = s.size();
	size_t max_size = s.max_size();

	std::cout << "══════════════════════════════════════════════════════════════\n";
	std::cout << "sets attributes : \n";
	std::cout << "Empty       : " << empty  << std::endl;
	std::cout << "Size        : " << size  << std::endl;
	std::cout << "Max size    : " << max_size  << std::endl;
	std::cout << "Content     : [";

	typename TESTED_NAMESPACE::set<T>::const_iterator it;
	for (it = s.begin();  it != s.end(); it++)
		std::cout << "[" << *it << ", ";
	std::cout << "]" << std::endl;
}

void test_set()
{
	{
		test_item_set("default constructor");
		TESTED_NAMESPACE::set<int> s;
		printSetAttributes(s);
		get_time_distance();
	}
	{
		test_item_set("copy constructor");
		const std::string range_str[] = {"One", "Two", "Three", "Four", "Five"};
		TESTED_NAMESPACE::set<std::string> s;
		for (int i = 0; i < 5; i++)
			s.insert(range_str[i]);
		TESTED_NAMESPACE::set<std::string> s_cp(s);
		printSetAttributes(s);
		printSetAttributes(s_cp);
		get_time_distance();
		test_item_set("assign");
		TESTED_NAMESPACE::set<std::string> s1 = s_cp;
		printSetAttributes(s1);
	}
	{
		test_item_set("reverse begin");
		const int range_int[] = {1458, -985, 58, 632, 65};
		TESTED_NAMESPACE::set<int> s;
		for (int i = 0; i < 5; i++)
			s.insert(range_int[i]);
		TESTED_NAMESPACE::set<int>::reverse_iterator r_it = s.rbegin();
		++r_it;
		std::cout << *r_it << std::endl;
		get_time_distance();
		test_item_set("reverse const begin");
		TESTED_NAMESPACE::set<int>::const_reverse_iterator c_r_it = s.rbegin();
		++c_r_it;
		std::cout << *c_r_it << std::endl;
		get_time_distance();
		test_item_set("reverse end");
		TESTED_NAMESPACE::set<int>::reverse_iterator r_end = s.rend();
		--r_end;
		std::cout << *r_end << std::endl;
		get_time_distance();
		TESTED_NAMESPACE::set<int>::const_reverse_iterator c_r_end = s.rend();
		--c_r_end;
		std::cout << *c_r_end << std::endl;
		get_time_distance();
	}
	{
		test_item_set("insert single");
		TESTED_NAMESPACE::set<std::string> s1;
		TESTED_NAMESPACE::pair<TESTED_NAMESPACE::set<std::string>::iterator, bool> r;
		r = s1.insert(std::string("test"));
		printSetAttributes(s1);
		get_time_distance();
		r = s1.insert(std::string("test"));
		printSetAttributes(s1);
		get_time_distance();
		TESTED_NAMESPACE::set<std::string>::iterator it;

		test_item_set("insert(iterator, value)");
		it = s1.insert(s1.begin(), std::string("test"));
		printSetAttributes(s1);
		std::cout << "it: " << *it << std::endl;
		get_time_distance();

		test_item_set("set::insert(iterator, iterator)");
		TESTED_NAMESPACE::set<std::string> s2;
		s2.insert(s1.begin(), s1.end());
		printSetAttributes(s2);
		get_time_distance();
		s2.insert(s1.begin(), s1.end());
		printSetAttributes(s2);
		get_time_distance();

		test_item_set("set::insert(value) time");
		TESTED_NAMESPACE::set<std::string> s3;
		for (int i = 0; i < 10000; i++)
		{
			std::ostringstream ss;
			ss << "test" << i;
			s3.insert(std::string(ss.str()));
		}
		get_time_distance();
		std::cout << "s3 size:" << s3.size() << std::endl;
		get_time_distance();
		test_item_set("clear");
		s3.clear();
		printSetAttributes(s3);
		get_time_distance();
	}
	{
		test_item_set("erase(key) (not found)");
		TESTED_NAMESPACE::set<std::string> s1;

		s1.insert(std::string("test1"));
		s1.insert(std::string("test2"));
		s1.insert(std::string("test3"));
		s1.insert(std::string("test4"));
		s1.insert(std::string("test5"));
		std::cout << s1.erase(std::string("test6")) << std::endl;
		printSetAttributes(s1);
		get_time_distance();

		test_item_set("set::erase(key) (found)");
		std::cout << s1.erase(std::string("test2")) << std::endl;
		printSetAttributes(s1);
		get_time_distance();
		s1.insert(std::string("test2"));
		test_item_set("set::erase(iterator)");
		s1.erase(s1.begin());
		printSetAttributes(s1);
		s1.erase(++s1.begin());
		printSetAttributes(s1);
		get_time_distance();
		s1.insert(std::string("test1"));
		s1.insert(std::string("test2"));
		s1.insert(std::string("test3"));
		s1.insert(std::string("test4"));
		s1.insert(std::string("test5"));

		test_item_set("set::erase(iterator, iterator)");
		s1.erase(s1.begin(), s1.end());
		printSetAttributes(s1);
		get_time_distance();
	}
	{
		test_item_set("swap");
		{
			TESTED_NAMESPACE::set<std::string> s1;
			for (int i = 0; i < 30; ++i)
			{
				std::ostringstream ss;
				ss << "test" << i;
				s1.insert(ss.str());
			}
			TESTED_NAMESPACE::set<std::string> s2;
			for (int i = 0; i < 50; ++i)
			{
				std::ostringstream ss;
				ss << "test" << i;
				s2.insert(ss.str());
			}
			s1.swap(s2);
			printSetAttributes(s1);
			printSetAttributes(s2);
			get_time_distance();
		}
	}
	{
		test_item_set("set::find()");
		TESTED_NAMESPACE::set<int> s1;
		for (int i = 0; i < 30; ++i)
			s1.insert(i);
		std::cout << *s1.find(1) << std::endl;
		std::cout << *s1.find(42) << std::endl;
		get_time_distance();
	}
	{
		test_item_set("key cmp");
		TESTED_NAMESPACE::set<std::string> s1;
		TESTED_NAMESPACE::set<std::string>::key_compare comp = s1.key_comp();
		std::cout << comp(std::string("test1"), std::string("test1")) << std::endl;
		std::cout << comp(std::string("test1"), std::string("test2")) << std::endl;
		 get_time_distance();

	}
	{
		test_item_set("val cmp");
		TESTED_NAMESPACE::set<std::string> s1;
		TESTED_NAMESPACE::set<std::string>::value_compare comp = s1.value_comp();

		std::cout << comp(std::string("test1"), std::string("test1")) << std::endl;
		std::cout << comp(std::string("test1"), std::string("test2")) << std::endl;
		get_time_distance();
	}

	{
		test_item_set("set::get_allocator()");
		TESTED_NAMESPACE::set<std::string> s1;
		TESTED_NAMESPACE::set<std::string>::allocator_type alloc = s1.get_allocator();
		std::cout << alloc.max_size() << std::endl;
	get_time_distance();
	}

	{
		test_item_set("set::lower_bound() and upper_bound()");
		TESTED_NAMESPACE::set<int> s1;
		for (int i = 0; i < 30; ++i)
			s1.insert(i);
		std::cout << *s1.lower_bound(1) << std::endl;
		std::cout << *s1.lower_bound(10) << std::endl;
		get_time_distance();
		std::cout << *s1.upper_bound(3) << std::endl;
		std::cout << *s1.upper_bound(15) << std::endl;
		get_time_distance();
	}
	{
		test_item_set("equal range");
		TESTED_NAMESPACE::set<std::string> s1;
		for (int i = 0; i < 30; ++i)
		{
        std::ostringstream ss;
        ss << "test" << i;
        s1.insert(ss.str());
		}
		std::cout << *(s1.equal_range(std::string("test1")).first) << std::endl;
		std::cout << *(s1.equal_range(std::string("test1")).second) << std::endl;
		std::cout << *(s1.equal_range(std::string("test2")).first) << std::endl;
		std::cout << *(s1.equal_range(std::string("test2")).second) << std::endl;
		std::cout << *(s1.equal_range(std::string("test3")).first) << std::endl;
		std::cout << *(s1.equal_range(std::string("test3")).second) << std::endl;
		std::cout << *(s1.equal_range(std::string("test4")).first) << std::endl;
		std::cout << *(s1.equal_range(std::string("test4")).second) << std::endl;
		std::cout << *(s1.equal_range(std::string("test5")).first) << std::endl;
		std::cout << *(s1.equal_range(std::string("test5")).second) << std::endl;
		std::cout << *(s1.equal_range(std::string("does not exist")).first) << std::endl;
		std::cout << *(s1.equal_range(std::string("does not exist")).second) << std::endl;
		get_time_distance();
	}
	{
		TESTED_NAMESPACE::set<int> s1;
		for (int i = 0; i < 10; ++i)
			s1.insert(i);
		TESTED_NAMESPACE::set<int> s2;
		for (int i = 0; i < 10; ++i)
			s2.insert(i);

		test_item_set("set::operator==()");
		std::cout << (s1 == s2) << std::endl;
		std::cout << (s2 == s1) << std::endl;
		std::cout << (s1 == s1) << std::endl;
		 get_time_distance();

		test_item_set("set::operator!=()");
		std::cout << (s1 != s2) << std::endl;
		std::cout << (s2 != s1) << std::endl;
		std::cout << (s1 == s1) << std::endl;
		 get_time_distance();

		test_item_set("set::operator<()");
		std::cout << (s1 < s2) << std::endl;
		std::cout << (s2 < s1) << std::endl;
		std::cout << (s1 < s1) << std::endl;
		 get_time_distance();

		test_item_set("set::operator<=()");
		std::cout << (s1 <= s2) << std::endl;
		std::cout << (s2 <= s1) << std::endl;
		std::cout << (s1 <= s1) << std::endl;
		get_time_distance();

		test_item_set("set::operator>()");
		std::cout << (s1 > s2) << std::endl;
		std::cout << (s2 > s1) << std::endl;
		std::cout << (s1 > s1) << std::endl;
		get_time_distance();

		test_item_set("set::operator>=()");
		std::cout << (s1 >= s2) << std::endl;
		std::cout << (s2 >= s1) << std::endl;
		std::cout << (s1 >= s1) << std::endl;
		get_time_distance();
	}
	{
		test_item_set("non member swap");
		TESTED_NAMESPACE::set<std::string> s1;
		for (int i = 0; i < 30; ++i)
		{
			std::ostringstream ss;
			ss << "test" << i;
			s1.insert(ss.str());
    }
		TESTED_NAMESPACE::set<std::string> s2;
		for (int i = 0; i < 30; ++i)
		{
			std::ostringstream ss;
			ss << "gest" << i;
			s2.insert(ss.str());
		}
		s1.swap(s2);
		printSetAttributes(s1);
		printSetAttributes(s2);
	}
	get_time_distance();
}
