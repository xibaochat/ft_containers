#ifndef TEST_HPP
# define TEST_HPP

# include <sys/stat.h>
# include <sys/types.h>
# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include "../containers/vector.hpp"
# include "../containers/map.hpp"



void iterator_test();
void real_iterator();
void reverse_iterator_incrementers();
void stl_reverse_iterator_incrementers();
void reverse_iterator_arithmetics();
void stl_reverse_iterator_arithmetics();
void reverse_iterator_bool_test();
void stl_reverse_iterator_bool_test();
void test_vector_construct();
void test_map();
void test_vector();


#endif
