#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator                                                  iterator_type;
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
		//conversion
		template<class U> reverse_iterator(const reverse_iterator<U>& u):_base(u.base()){}

		template<class U>
		const reverse_iterator& operator=(const reverse_iterator<U>& u)
			{
				_base = u.base();
				return (*this);
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
	// template <class Iterator>
	// bool operator== (const reverse_iterator<Iterator>& lhs,
	// 				 const reverse_iterator<Iterator>& rhs)
	// {
	// 	return lhs.base() == rhs.base();
	// }

	/*to manage const*/
	template<typename T, typename U>
	bool operator==(const reverse_iterator<T>& __x,
					const reverse_iterator<U>& __y)
     { return __x.base() == __y.base(); }

  // 	template <class Iterator>
  // bool operator!= (const reverse_iterator<Iterator>& lhs,
  //                  const reverse_iterator<Iterator>& rhs)
  // 	{
  // 		return lhs.base() != rhs.base();
  // 	}

	/*to manage const*/
	template <class T, class U>
  bool operator!= (const reverse_iterator<T>& lhs,
                   const reverse_iterator<U>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class Iterator, class U>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<U>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class T, class U>
	bool operator<= (const reverse_iterator<T>& lhs,
					 const reverse_iterator<U>& rhs)
	{
		return lhs.base() >= rhs.base();
	}
	template <class T, class U>
  bool operator>  (const reverse_iterator<T>& lhs,
                   const reverse_iterator<U>& rhs)
	{
		return lhs.base() < rhs.base();
	}
	template <class T, class U>
  bool operator>= (const reverse_iterator<T>& lhs,
                   const reverse_iterator<U>& rhs)
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
	template <class T, class U>
	typename reverse_iterator<T>::difference_type operator- (
		const reverse_iterator<T>& lhs,
		const reverse_iterator<U>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}


//reverse_it http://www.cplusplus.com/reference/iterator/reverse_iterator/
//reverse_iterator non_member http://www.cplusplus.com/reference/iterator/reverse_iterator/operators/
#endif
/*
  to do the conversion const_reverse_iterator to reverse_iterator, and vice-vera, I use template <class T, class U> to manage these two class, and inside the class of reverse_iterator, copy and assignement is the same.
 */
//https://cplusplus.github.io/LWG/issue280#23.5.1.2
//https://gcc.gnu.org/onlinedocs/gcc-11.1.0/libstdc++/api/a18648_source.html#l00450
