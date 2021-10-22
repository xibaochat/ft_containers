#include "test.hpp"

void test_item_vector(std::string s)
{
	std::cout << BLUE << s << NC << std::endl;
}

template <class T>
void printVectorAttributes(TESTED_NAMESPACE::vector<T>& vector)
{
	std::string is_empty = (vector.empty() == 1) ? "vector is empty" : "vector is not empty";
	size_t size = vector.size();
    size_t max_size = vector.max_size();
    size_t capacity = vector.capacity();
	std::cout << "\n══════════════════════════════════════════════════════════════\n";
    std::cout << "Vectors attributes : \n";
    std::cout << "STL : \n";
    std::cout << "Empty       : " << is_empty  << std::endl;
    std::cout << "Size        : " << size  << std::endl;
    std::cout << "Max size    : " << max_size  << std::endl;
    std::cout << "Capacity    : " << capacity  << std::endl;
    std::cout << "Content     : [";
	for (typename TESTED_NAMESPACE::vector<T>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		std::cout << *it;
		if (it != vector.end() - 1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void test_vector()
{
	{
		test_item_vector("vector::constructor");
		TESTED_NAMESPACE::vector<int> v1; // default constructor
		TESTED_NAMESPACE::vector<int> v2(2); // size constructor
		TESTED_NAMESPACE::vector<int> v3(2, 42); // size and value constructor
		TESTED_NAMESPACE::vector<int> v4(v3); // copy constructor
		TESTED_NAMESPACE::vector<int> v5(v3.begin(), v3.end()); // iterator constructor
		get_time_distance();
		printVectorAttributes(v1);
		printVectorAttributes(v2);
		printVectorAttributes(v3);
		printVectorAttributes(v4);
		printVectorAttributes(v5);
		test_item_vector("throw erreur test:");
		try
		{
			v1.at(0);
			std::cout << "KO" << std::endl;
		}
		catch (std::out_of_range &e)
		{
			std::cout << "OK" << std::endl;
		}
		get_time_distance();

		test_item_vector("AT test");
		show_res("vector::constructor (size) (at)", v2.at(0));
		show_res("vector::constructor (size and value) (at)", v3.at(0));
		show_res("vector::constructor (copy) (at)", v4.at(0));
		show_res("vector::constructor (iterator) (at)", v5.at(0));

		test_item_vector("operator[] test");
		show_res("vector::constructor (size) (operator[])", v2[0]);
		show_res("vector::constructor (size and value) (operator[])", v3[0]);
		show_res("vector::constructor (copy) (operator[])", v4[0]);
		show_res("vector::constructor (iterator) (operator[])", v5[0]);

		test_item_vector("begin test");
		show_res("vector::constructor (size) (begin)", *v2.begin());
		show_res("vector::constructor (size and value) (begin)", *v3.begin());
		show_res("vector::constructor (copy) (begin)", *v4.begin());
		show_res("vector::constructor (iterator) (begin)", *v5.begin());

		test_item_vector("end test");
		show_res("vector::constructor (size) (end)", *(v2.end() - 1));
		show_res("vector::constructor (size and value) (end)", *(v3.end() - 1));
		show_res("vector::constructor (copy) (end)", *(v4.end() - 1));
		show_res("vector::constructor (iterator) (end)", *(v5.end() - 1));

		test_item_vector("rbegin test");
		show_res("vector::constructor (size) (rbegin)", *v2.rbegin());
		show_res("vector::constructor (size and value) (rbegin)", *v3.rbegin());
		show_res("vector::constructor (copy) (rbegin)", *v4.rbegin());
		show_res("vector::constructor (iterator) (rbegin)", *v5.rbegin());

		test_item_vector("rend test");
		show_res("vector::constructor (size) (rend)", *(v2.rend() - 1));
		show_res("vector::constructor (size and value) (rend)", *(v3.rend() - 1));
		show_res("vector::constructor (copy) (rend)", *(v4.rend() - 1));
		show_res("vector::constructor (iterator) (rend)", *(v5.rend() - 1));
	}
	{
		test_item_vector("Assign test");
		TESTED_NAMESPACE::vector<int> v1;
		TESTED_NAMESPACE::vector<int> v2;
		v1.assign (7,100);
		printVectorAttributes(v1);
		get_time_distance();
		v2.assign(v1.begin(), v1.end());
		printVectorAttributes(v2);
		get_time_distance();
		v2.assign(5, 666);
		printVectorAttributes(v2);
		get_time_distance();
	}
	{
		test_item_vector("Front and Back test");
		int array[] = {144, 335, 5, 0, -54};
		ft::vector<int> v(5, 10);
		show_res("vector front", v.front());
		show_res("vector back", v.back());
		ft::vector<int> v1(array, array + 5);
		show_res("vector front", v1.front());
		show_res("vector back", v1.back());
	}
	{
		test_item_vector("push_back and pop back test");
		TESTED_NAMESPACE::vector<int> v1;
		TESTED_NAMESPACE::vector<int> v2(42, 5);
		TESTED_NAMESPACE::vector<int> v3(42, 10);

		for (int i = 0; i < 10000; i++)
			v1.push_back(i);
		get_time_distance();
		printVectorAttributes(v1);
		get_time_distance();
		v2.push_back(666);
		v3.push_back(88);
		printVectorAttributes(v2);
		printVectorAttributes(v3);
		get_time_distance();
		while (!v1.empty())
			v1.pop_back();
		get_time_distance();
		printVectorAttributes(v1);
		v2.pop_back();
		v2.pop_back();
		v3.pop_back();
		v3.pop_back();
		printVectorAttributes(v2);
		printVectorAttributes(v3);
        get_time_distance();
	}
	{
		test_item_vector("insert test");
		TESTED_NAMESPACE::vector<int> v(10, 42);
		v.push_back(42);
		v.push_back(17);
		v.insert(v.begin(), v.begin() + 2, v.end() - 3);
		get_time_distance();
		printVectorAttributes(v);
	}
	{
		TESTED_NAMESPACE::vector<int> v(110, 2);
        v.insert(v.begin(), v.begin(), v.end());
		get_time_distance();
		printVectorAttributes(v);
	}
	{
		TESTED_NAMESPACE::vector<int> v(110, 2);
		TESTED_NAMESPACE::vector<int> v1(10, 888);
		v.insert(v.begin(), 150, 1);
		get_time_distance();
		printVectorAttributes(v);
		v1.insert(v1.begin(), 42);
		get_time_distance();
		printVectorAttributes(v1);
	}
	{
		TESTED_NAMESPACE::vector<int> v(110, 2);
		v.insert(v.begin() + 15, 888);
		get_time_distance();
		printVectorAttributes(v);
	}
	{
		test_item_vector("erase test");
		TESTED_NAMESPACE::vector<int> v;
        for (int i=1; i<=10; i++)
            v.push_back(i);
        v.erase(v.begin() + 5);
		get_time_distance();
		printVectorAttributes(v);
		v.erase(v.begin(), v.begin() + 3);
		get_time_distance();
		printVectorAttributes(v);
	}
	{
		int array[] = {454, -5424, 12, 565, 54, 893, 12, 85, 78, -123, 2333};
		TESTED_NAMESPACE::vector<int>::iterator v_it(array);
		TESTED_NAMESPACE::vector<int>  v(v_it, v_it + 11);
		v.erase(v.begin() + 2, v.end() - 3);
		get_time_distance();
		printVectorAttributes(v);
	}
	{
		TESTED_NAMESPACE::vector<int> v1;
		TESTED_NAMESPACE::vector<int> v2(42, 5);
		test_item_vector("vector::swap (time)");
		for (int i = 0; i < 10000; i++)
			v2.swap(v1);
		get_time_distance();
		printVectorAttributes(v1);
		printVectorAttributes(v2);
		get_time_distance();
	}
	{
		int range_array_one[] = {144, 335, 5, 0, -54};
		int range_array_two[] = {47, -98, 58, 611, -4};
		TESTED_NAMESPACE::vector<int>::iterator it(&(range_array_one[0]));
		TESTED_NAMESPACE::vector<int>::iterator it_2(&(range_array_two[0]));
		TESTED_NAMESPACE::vector<int> v(it, it + 5);
		TESTED_NAMESPACE::vector<int> v1(it_2, it_2 + 5);
		v1.swap(v);
		get_time_distance();
		printVectorAttributes(v);
		printVectorAttributes(v1);
		get_time_distance();
	}
	{
		test_item_vector("test clear");
		TESTED_NAMESPACE::vector<int> v;
		v.push_back (100);
		v.push_back (200);
		v.push_back (300);
		v.clear();
		get_time_distance();
		printVectorAttributes(v);
	}
{
	test_item_vector("test get allocator");
	TESTED_NAMESPACE::vector<int> v1;
	TESTED_NAMESPACE::vector<std::string> v2;

	TESTED_NAMESPACE::vector<int>::allocator_type alloc1 = v1.get_allocator();
	TESTED_NAMESPACE::vector<std::string>::allocator_type alloc2 = v2.get_allocator();
	int *p1 = alloc1.allocate(1);
	std::string *p2 = alloc2.allocate(1);
	alloc1.construct(p1, 42);
	alloc2.construct(p2, "42");
	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	alloc1.destroy(p1);
	alloc2.destroy(p2);
	alloc1.deallocate(p1, 1);
	alloc2.deallocate(p2, 1);
	get_time_distance();
}
{
	test_item_vector("test operator");
	TESTED_NAMESPACE::vector<int> v1;
    TESTED_NAMESPACE::vector<int> v2(42, 5);
    TESTED_NAMESPACE::vector<int> v3(42, 5);
	TESTED_NAMESPACE::vector<int> v4(888, 5);

    std::cout << (v1 == v2) << std::endl;
    std::cout << (v2 == v3) << std::endl;
    std::cout << (v3 == v4) << std::endl;
	get_time_distance();
	std::cout << (v1 != v2) << std::endl;
    std::cout << (v2 != v3) << std::endl;
    std::cout << (v3 != v4) << std::endl;
    get_time_distance();
    std::cout << (v1 < v2) << std::endl;
    std::cout << (v2 < v3) << std::endl;
    std::cout << (v3 < v4) << std::endl;
	get_time_distance();
    std::cout << (v1 <= v2) << std::endl;
    std::cout << (v2 <= v3) << std::endl;
    std::cout << (v3 <= v4) << std::endl;
	get_time_distance();
    std::cout << (v1 > v2) << std::endl;
    std::cout << (v2 > v3) << std::endl;
    std::cout << (v3 > v4) << std::endl;
	get_time_distance();
    std::cout << (v1 >= v2) << std::endl;
    std::cout << (v2 >= v3) << std::endl;
    std::cout << (v3 >= v4) << std::endl;
	get_time_distance();
}
{
	test_item_vector("test non member swap");
	TESTED_NAMESPACE::vector<int> v1;
    TESTED_NAMESPACE::vector<int> v2(42, 5);
	TESTED_NAMESPACE::swap(v1, v2);
	printVectorAttributes(v1);
	printVectorAttributes(v2);
	get_time_distance();
}
}
