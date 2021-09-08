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
		typedef const T& reference;
		typedef const T* pointer;
		typedef RandomAccessIteratorTag iterator_category;
	};

	//reverse_iterator
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator                                              iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type        value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type   difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer           pointer;
		typedef typename ft::iterator_traits<Iterator>::reference         reference;
	private:
		iterator_type _base;
	public:
		iterator_type base() const
		{
			return (_base);
		}
		/*construct*/
		reverse_iterator():_base(){}
		explicit reverse_iterator (iterator_type it):_base(it){}
		reverse_iterator (const reverse_iterator<Iterator>& rev_it): _base(rev_it.base()){}
		reverse_iterator& operator=( const reverse_iterator& other )
		{
			if (this != &other)
				_base = other.base();
			return *this;
		}
		~reverse_iterator(){}
		reference operator*() const
		{
			Iterator it(_base);
			--it;
			return (*it);
		}
		reverse_iterator operator+ (difference_type n) const
		{
			reverse_iterator it(_base - n);
			return (it);
		}
		reverse_iterator& operator++()
		{
			--_base;
			return (*this);
		}
		reverse_iterator  operator++(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		}
		reverse_iterator& operator+= (difference_type n)
		{
			_base -= n;
			return (*this);
		}
		reverse_iterator operator- (difference_type n) const
		{
			reverse_iterator it(_base + n);
			return (it);
		}
		reverse_iterator& operator--()
		{
			++_base;
			return (*this);
		}
		reverse_iterator  operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		}
		reverse_iterator& operator-= (difference_type n)
		{
			 _base += n;
			 return (*this);
		}
		pointer operator->() const
		{
			return &(operator*());
		}
		reference operator[] (difference_type n) const
		{
			return base()[-n-1];
		}
	};
	//non member reverse_iterator
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class Iterator>
  bool operator!= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}
	template <class Iterator>
  bool operator>  (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}
	template <class Iterator>
  bool operator>= (const reverse_iterator<Iterator>& lhs,
                   const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	}

}

#endif




//reverse_it http://www.cplusplus.com/reference/iterator/reverse_iterator/
//reverse_iterator non_member http://www.cplusplus.com/reference/iterator/reverse_iterator/operators/
