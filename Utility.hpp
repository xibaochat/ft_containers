#ifndef UTILITY_HPP
# define UTILITY_HPP

#include <iterator>
#include <cstddef>
#include <iostream>
#define SLASH       "\e[4m"
#define GREEN       "\033[33;32m"
#define YELLOW      "\033[33;33m"
#define RED         "\033[33;31m"
#define MAGENTA     "\e[95m"
#define BLUE        "\033[1;34m"
#define CYAN        "\e[96m"
#define ORANGE      "\e[38;5;215m"
#define NC          "\033[0m"

namespace ft
{
	//Iterator tags

	struct InputIteratorTag {};

	struct OutputIteratorTag {};

	struct ForwardIteratorTag : public InputIteratorTag {};

	struct BidirectionalIteratorTag : public ForwardIteratorTag {};

	struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};

	//iterator traits
	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits < T *>
	{
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T& reference;
		typedef T* pointer;
		typedef RandomAccessIteratorTag iterator_category;
	};

	template<class T>
	struct iterator_traits <const T *>
	{
		typedef const T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T& const_reference;
		typedef const T* const_pointer;
		typedef RandomAccessIteratorTag iterator_category;
	};

	//reverse_iterator



}

#endif
