#ifndef TEST_HPP
# define TEST_HPP

# include <sys/stat.h>
# include <sys/types.h>
# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <stack>
# include <set>
# include <vector>
# include "../containers/vector.hpp"
# include "../containers/map.hpp"
# include "../containers/stack.hpp"
# include "../containers/set.hpp"


template <class T>
bool equalbool(const T& t1, const T& t2);
template <class T>
std::string equal(const T& t1, const T& t2);
bool printBoolResult(std::fstream& fs, bool stl_bool, bool ft_bool);

void test_map();
void test_vector();
void test_stack();
void test_set();
#endif
