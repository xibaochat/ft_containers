#include "test.hpp"

template<class T>
bool printSingleValue(std::fstream& fs, const T& t1, const T& t2)
{
    fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "Value from :\n";
    fs << "STL    : " << t1 << "\n";
    fs << "FT  [" << equal(t1, t2) << "]: " << t2 << "\n";
    fs << "══════════════════════════════════════════════════════════════\n";
	if (t1 == t2)
	{
		std::cout << GREEN << "[OK]" << NC;
		return true;
	}
	else
		std::cout << RED << "[NOP]" << NC;
	fs.close();
	return false;
}

template <class T>
std::string equalContent(
    std::stack<T> stl_stack,
    ft::stack<T> ft_stack
)
{
    while (42)
    {
        if (stl_stack.size() == 0 || ft_stack.size() == 0)
            break;
        if (ft_stack.top() != stl_stack.top())
            return ("✘");
        ft_stack.pop();
        stl_stack.pop();
    }
    return ("✔");
}

template <class T>
bool printStackAttributes(std::fstream& fs, std::stack<T> stl_stack, ft::stack<T> ft_stack)
{
    /* STL Values */
    std::string stl_empty = ((stl_stack.empty() == 1) ? "true" : "false");
    size_t stl_size = stl_stack.size();

    /* FT Values */
    std::string ft_empty = ((ft_stack.empty() == 1) ? "true" : "false");
    size_t ft_size = ft_stack.size();

    /* FT Result compare values */
    bool empty = equalbool(ft_empty, stl_empty);
    bool size = equalbool(ft_size, stl_size);
    std::string content = equalContent(stl_stack, ft_stack);

    fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "stacks attributes : \n";
    fs << "STL : \n";
    fs << "Empty       : " << stl_empty  << std::endl;
    fs << "Size        : " << stl_size  << std::endl;
    fs << "Content     : [";

    while (42)
    {
        if (stl_stack.size() == 0)
            break;
        fs << stl_stack.top();
        stl_stack.pop();
        if (stl_stack.size() != 0)
            fs << ", ";
    }
    fs << "]\n";
    fs << std::endl;
    fs << "FT : \n";
    fs << "Empty    [" << equal(ft_empty, stl_empty) << "]: " << ft_empty  << std::endl;
    fs << "Size     [" << equal(ft_size, stl_size) << "]: " << ft_size  << std::endl;
    fs << "Content  [" << content << "]: [";
    while (42)
    {
        if (ft_stack.size() == 0)
            break;
        fs << ft_stack.top();
        ft_stack.pop();
        if (ft_stack.size() != 0)
            fs << ", ";
    }
    fs << "]\n";
    fs << "══════════════════════════════════════════════════════════════\n";

    /* Error case */
    if (empty == false)
        return (false);
    else if (size == false)
        return (false);
    else if (content == "✘")
        return (false);
    return (true);
}

void test_stack()
{
    std::cout << UNDERLINE << "STACK :" << NC << std::endl;

    mkdir("./tester/stacks_output", 0777);

    std::fstream fs;
	std::cout << YELLOW << "Member function overloads  " << NC << std::endl;
    std::cout << "test_stack_default Constructor ";
    /* Default Constructor */
    {
        std::stack<int> stl_default;
        ft::stack<int> ft_default;

        fs.open("./tester/stacks_output/constructor_default", std::fstream::in | std::fstream::out | std::fstream::trunc);
        if (printStackAttributes(fs, stl_default, ft_default) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_empty_true ";
    /* Empty true */
    {
        std::stack<int> stl_empty;
        ft::stack<int> ft_empty;

        fs.open("./tester/stacks_output/empty_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printStackAttributes(fs, stl_empty, ft_empty) == true)
            std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_empty_false ";
    /* Empty false */
    {
        std::stack<int> stl_empty;
        ft::stack<int> ft_empty;

        stl_empty.push(42);
        ft_empty.push(42);

        fs.open("./tester/stacks_output/empty_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printStackAttributes(fs, stl_empty, ft_empty) == true)
            std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_size ";
    /* Size */
    {
        std::stack<int> stl_size;
        ft::stack<int> ft_size;

        for (int i = 0; i < 42; i++)
        {
            stl_size.push(i);
            ft_size.push(i);
        }

        fs.open("./tester/stacks_output/size", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printStackAttributes(fs, stl_size, ft_size) == true)
            std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_top ";
    /* Top */
    {
        std::stack<int> stl_top;
        ft::stack<int> ft_top;

        for (int i = 0; i < 42; i++)
        {
            stl_top.push(i);
            ft_top.push(i);
        }

        fs.open("./tester/stacks_output/top", std::fstream::in | std::fstream::out | std::fstream::trunc);
        if(printSingleValue(fs, stl_top.top(), ft_top.top()) == false)
		{
            std::cout << RED << "[NOP]" << NC << std::endl;
		}
		else
		{
			stl_top.pop();
			ft_top.pop();

			if (printSingleValue(fs, stl_top.top(), ft_top.top()) == true)
				std::cout << GREEN << "[OK]" << NC << std::endl;
			else
				std::cout << RED << "[NOP]" << NC << std::endl;
		}
		fs.close();
    }
	 std::cout << "test_stack_push ";
    /* Push */
    {
        std::stack<int> stl_size;
        ft::stack<int> ft_size;

        for (int i = 0; i < 42; i++)
        {
            stl_size.push(i * 2);
            ft_size.push(i * 2);
        }
        fs.open("./tester/stacks_output/push", std::fstream::in | std::fstream::out | std::fstream::trunc);
        if (printStackAttributes(fs, stl_size, ft_size) == true)
			 std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
    }
	std::cout << "test_stack_pop ";
    /* Pop */
    {
        std::stack<int> stl_pop;
        ft::stack<int> ft_pop;

        for (int i = 0; i < 42; i++)
        {
            stl_pop.push(i);
            ft_pop.push(i);
        }

        fs.open("./tester/stacks_output/pop", std::fstream::in | std::fstream::out | std::fstream::trunc);
		if (printStackAttributes(fs, stl_pop, ft_pop) == false)
			std::cout << RED << "[NOP]" << NC << std::endl;
		else
		{
			stl_pop.pop();
			ft_pop.pop();
			if (printStackAttributes(fs, stl_pop, ft_pop) == true)
				std::cout << GREEN << "[OK]" << NC << std::endl;
			else
				std::cout << RED << "[NOP]" << NC << std::endl;
		}
        fs.close();
    }
    std::cout << YELLOW << "Non-member function overloads " << NC << std::endl;
	std::cout << "test_stack_operator == ";
    /* RL == true */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i);
            stl_pop_two.push(i);
            ft_pop_one.push(i);
            ft_pop_two.push(i);
        }

        fs.open("./tester/stacks_output/operator_equal_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

		if (printBoolResult(fs, (stl_pop_one == stl_pop_two), (ft_pop_one == ft_pop_two)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_operator == ";
    /* RL == false */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i);
            stl_pop_two.push(i * 2);
            ft_pop_one.push(i);
            ft_pop_two.push(i * 2);
        }

        fs.open("./tester/stacks_output/operator_equal_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

		if (printBoolResult(fs, (stl_pop_one == stl_pop_two), (ft_pop_one == ft_pop_two)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
	}
	std::cout << "test_stack_operator != ";
    /* RL != true */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i);
            stl_pop_two.push(i * 2);
            ft_pop_one.push(i);
            ft_pop_two.push(i * 2);
        }

        fs.open("./tester/stacks_output/operator_net_equal_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one != stl_pop_two), (ft_pop_one != ft_pop_two)))
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_operator != ";
    /* RL != false */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i);
            stl_pop_two.push(i);
            ft_pop_one.push(i);
            ft_pop_two.push(i);
        }

        fs.open("./tester/stacks_output/operator_not_equal_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one != stl_pop_two), (ft_pop_one != ft_pop_two)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
	}
	std::cout << "test_stack_operator < ";
    /* RL < true */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i);
            ft_pop_one.push(i);
            if (i == 30)
            {
                stl_pop_two.push(i * 2);
                ft_pop_two.push(i * 2);
            }
            else
            {
                stl_pop_two.push(i);
                ft_pop_two.push(i);
            }
        }

        fs.open("./tester/stacks_output/operator_inf_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one < stl_pop_two), (ft_pop_one < ft_pop_two)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_operator < ";
    /* RL < false */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_two.push(i);
            ft_pop_two.push(i);
            if (i == 30)
            {
                stl_pop_one.push(i * 2);
                ft_pop_one.push(i * 2);
            }
            else
            {
                stl_pop_one.push(i);
                ft_pop_one.push(i);
            }
        }

        fs.open("./tester/stacks_output/operator_inf_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one < stl_pop_two), (ft_pop_one < ft_pop_two)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_operator <= ";
    /* RL <= true */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i);
            stl_pop_two.push(i * 2);
            ft_pop_one.push(i);
            ft_pop_two.push(i * 2);
        }

        fs.open("./tester/stacks_output/operator_inf_equal_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one <= stl_pop_two), (ft_pop_one <= ft_pop_two)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_operator <= ";
    /* RL <= true equal */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i);
            stl_pop_two.push(i);
            ft_pop_one.push(i);
            ft_pop_two.push(i);
        }

        fs.open("./tester/stacks_output/operator_inf_equal_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one <= stl_pop_two), (ft_pop_one <= ft_pop_two)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
		fs.close();
    }
	std::cout << "test_stack_operator <= ";
    /* RL <= false */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i * 2);
            stl_pop_two.push(i);
            ft_pop_one.push(i * 2);
            ft_pop_two.push(i);
        }

        fs.open("./tester/stacks_output/operator_inf_equal_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one <= stl_pop_two), (ft_pop_one <= ft_pop_two)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_operator > ";
    /* RL > true */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i * 2);
            stl_pop_two.push(i);
            ft_pop_one.push(i * 2);
            ft_pop_two.push(i);
        }

        fs.open("./tester/stacks_output/operator_sup_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one > stl_pop_two), (ft_pop_one > ft_pop_two)))
			std::cout << GREEN << "[OK]" << NC << std::endl;
		else
			std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_operator > ";
    /* RL > false */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i);
            stl_pop_two.push(i);
            ft_pop_one.push(i);
            ft_pop_two.push(i);
        }

        fs.open("./tester/stacks_output/operator_sup_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one > stl_pop_two), (ft_pop_one > ft_pop_two)) == true)
			 std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_operator >= ";
    /* RL >= true */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i);
            stl_pop_two.push(i);
            ft_pop_one.push(i);
            ft_pop_two.push(i);
        }

        fs.open("./tester/stacks_output/operator_sup_equal_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one >= stl_pop_two), (ft_pop_one >= ft_pop_two)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }
	std::cout << "test_stack_operator >= ";
    /* RL >= false */
    {
        std::stack<int> stl_pop_one;
        std::stack<int> stl_pop_two;
        ft::stack<int> ft_pop_one;
        ft::stack<int> ft_pop_two;

        for (int i = 0; i < 42; i++)
        {
            stl_pop_one.push(i);
            ft_pop_one.push(i);
            if (i == 30)
            {
                stl_pop_two.push(i * 2);
                ft_pop_two.push(i * 2);
            }
            else
            {
                stl_pop_two.push(i);
                ft_pop_two.push(i);
            }
        }

        fs.open("./tester/stacks_output/operator_sup_equal_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
        printStackAttributes(fs, stl_pop_one, ft_pop_one);
        printStackAttributes(fs, stl_pop_two, ft_pop_two);

        if (printBoolResult(fs, (stl_pop_one >= stl_pop_two), (ft_pop_one >= ft_pop_two)) == true)
			std::cout << GREEN << "[OK]" << NC << std::endl;
        else
            std::cout << RED << "[NOP]" << NC << std::endl;
        fs.close();
    }

    std::cout << std::endl;
}
