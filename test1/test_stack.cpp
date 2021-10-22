#include "test.hpp"

void test_item_stack(std::string s)
{
	std::cout << "\n" << YELLOW << s << NC << std::endl;
}

template <class T>
void printStackAttributes(TESTED_NAMESPACE::stack<T> s)
{
	std::string empty = ((s.empty() == 1) ? "true" : "false");
    size_t size = s.size();

    std::cout << "══════════════════════════════════════════════════════════════\n";
    std::cout << "stacks attributes : \n";
    std::cout << "Empty       : " << empty  << std::endl;
    std::cout << "Size        : " << size  << std::endl;
    std::cout << "Content     : [";

    while (42)
    {
        if (s.size() == 0)
            break;
		std::cout << s.top();
        s.pop();
        if (s.size() != 0)
			std::cout << ", ";
    }
	std::cout << "]\n";
}

void test_stack()
{
	{
		test_item_stack("default constructor");
		TESTED_NAMESPACE::stack<int> s;
		printStackAttributes(s);
		get_time_distance();
		test_item_stack("push");
		s.push(888);
		s.push(888);
		printStackAttributes(s);
		get_time_distance();
		for (int i = 0; i < 42; i++)
			s.push(i);
		printStackAttributes(s);
		get_time_distance();
		test_item_stack("pop");
		s.pop();
		s.pop();
		printStackAttributes(s);
		get_time_distance();
	}
	{
		test_item_stack("operator");
		TESTED_NAMESPACE::stack<int> stack;
		TESTED_NAMESPACE::stack<int> stack2;
		TESTED_NAMESPACE::stack<int> stack3;
		TESTED_NAMESPACE::stack<int> stack4;

		for (int i = 0; i < 10; i++)
			stack.push(i);
		for (int i = 0; i < 10; i++)
			stack2.push(i);
		for (int i = 0; i < 10; i++)
			stack3.push(6);
		for (int i = 0; i < 10; i++)
			stack4.push(7);

		show_res("stack::operator==", stack == stack2);
		show_res("stack::operator!=", stack != stack3);
		show_res("stack::operator<", stack < stack4);
		show_res("stack::operator<=", stack <= stack4);
		show_res("stack::operator>", stack > stack3);
		show_res("stack::operator>=", stack >= stack3);
	}
}
