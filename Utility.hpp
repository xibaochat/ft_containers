#ifndef UTILITY_HPP
# define UTILITY_HPP

#include <iterator>
#include <cstddef>
#include <iostream>

namespace ft
{
	//Iterator tags

	struct InputIteratorTag {};

	struct OutputIteratorTag {};

	struct ForwardIteratorTag : public InputIteratorTag {};

	struct BidirectionalIteratorTag : public ForwardIteratorTag {};

	struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};
}

#endif
