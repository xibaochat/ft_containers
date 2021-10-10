#ifndef UTILITY_HPP
# define UTILITY_HPP

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

namespace ft
{
	//Iterator tags

	struct InputIteratorTag {};

	struct OutputIteratorTag {};

	struct ForwardIteratorTag : public InputIteratorTag {};

	struct BidirectionalIteratorTag : public ForwardIteratorTag {};

	struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};

	template <typename T>
    void    swap(T &a, T &b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    };
	template<class T>
    struct less : std::binary_function<T, T, bool>
    {
        bool    operator()(T const& x, T const& y) const
		{
			return x < y;
		}
    };


}

#endif
