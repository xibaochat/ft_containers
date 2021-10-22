#ifndef TEST_HPP
# define TEST_HPP

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

# include <sys/stat.h>
# include <sys/types.h>
# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <stack>
# include <set>
# include <vector>
# include <time.h>
# include "../containers/vector.hpp"
# include "../containers/map.hpp"
# include "../containers/stack.hpp"
# include "../containers/set.hpp"

#define SLASH       "\e[4m"
#define GREEN       "\033[33;32m"
#define YELLOW      "\033[33;33m"
#define RED         "\033[33;31m"
#define MAGENTA     "\e[95m"
#define BLUE        "\033[1;34m"
#define CYAN        "\e[96m"
#define ORANGE      "\e[38;5;215m"
#define UNDERLINE "\033[4m"
#define NC          "\033[0m"

void get_time_distance();

template <typename T>
void show_res(std::string s, T a)
{
	std::cout << s << " " << a << std::endl;
    get_time_distance();
}

void test_map();
void test_vector();
void test_stack();
void test_set();
void test_42();


#endif
