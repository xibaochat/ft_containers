#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{
	template<bool, class T = void>
	struct enable_if{};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif
//https://stackoverflow.com/questions/62012761/what-is-the-meaning-of-type-nullptr
//https://eli.thegreenplace.net/2014/sfinae-and-enable_if/
