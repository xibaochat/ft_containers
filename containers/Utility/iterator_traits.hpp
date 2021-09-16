#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include "Utility.hpp"
namespace ft
{
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
		typedef const T& reference;
		typedef const T* pointer;
		typedef RandomAccessIteratorTag iterator_category;
	};
}

#endif
