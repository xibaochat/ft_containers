#ifndef CONST_ITERATOR
# define CONST_ITERATOR

#include "Utility.hpp"
namespace ft
{
	template <typename T>
	class Const_VectorIterator
	{
	public:
		typedef size_t          size_type;
		typedef std::ptrdiff_t  difference_type;
		typedef const T         value_type;
		typedef const T*        pointer;
		typedef const T&        reference;
		typedef std::random_access_iterator_tag iterator_category;

	private:
		typedef Const_VectorIterator<T> _Self;
		pointer m_ptr;
		Const_VectorIterator(pointer ptr):m_ptr(ptr){}
	public:
		/*******************************************
        *****  Member Functions (Coplien Form) *****
        *******************************************/
		Const_VectorIterator():m_ptr(NULL){}
		Const_VectorIterator(const _Self &obj):m_ptr(obj.m_ptr){}//a(b)
		Const_VectorIterator(VectorIterator<T> obj)
		{
			m_ptr = obj.operator->();
		}
		~Const_VectorIterator(){}
		_Self &operator=(const _Self &src)
		{
			this->m_ptr = src.m_ptr;
			return (*this);
		}
		_Self &operator=(VectorIterator<T> src)
		{
			this->m_ptr = src.operator->();
			return (*this);
		}

		friend difference_type     operator-(const _Self &a, const _Self &b) {
            return (a.m_ptr - b.m_ptr);
        }

		//template <typename U>
		//friend std::ptrdiff_t operator-( const VectorIterator<const U> &a, const VectorIterator<const U> &b);
		/*******************************************
		        *****  COMPARE  *****
           == | != | < | <= | > | >= 6 in total
        *******************************************/

		friend bool operator==(const _Self& a, const _Self& b){return (a.m_ptr == b.m_ptr);}
        friend bool operator!=(const _Self& a, const _Self& b){return !(a.m_ptr == b.m_ptr);}
        friend bool operator<(const _Self& a, const _Self& b){return (a.m_ptr < b.m_ptr);}
        friend bool operator<=(const _Self& a, const _Self& b){return (a.m_ptr <= b.m_ptr);}
        friend bool operator>(const _Self& a, const _Self& b){return (a.m_ptr > b.m_ptr);}
        friend bool operator>=(const _Self& a, const _Self& b){return (a.m_ptr >= b.m_ptr);}

		/******************************************************************
		  ***** arithmetic operators  *****
          ++a | a++ | --a | a-- | a+= | a-=n
        *******************************************************************/
		_Self& operator++() { m_ptr++; return *this;}
		_Self operator++(int){
			_Self obj(*this);
			m_ptr++;
            return (obj);
        }
		_Self operator--() {m_ptr--; return *this;}
		_Self operator--(int)
        {
            _Self obj(*this);
            m_ptr--;
            return (obj);
        }

		_Self & operator+=(std::ptrdiff_t n)
        {
            m_ptr += n;
            return (*this);
        }
		_Self &operator-=(std::ptrdiff_t n)
        {
                m_ptr -= n;
                return (*this);
        }
		/******************************************************************
		 ****** dereference  *****
		 *a | a->m | *a = t | a[n]
		*************************************************************/
		reference operator*() const {return *m_ptr;}
		pointer operator->() {return m_ptr;}
		reference operator[](std::ptrdiff_t n){return m_ptr[n];}

		template<typename U,  class Allocator>
		friend class vector;

		_Self operator-(difference_type n)
			{
				return (_Self(m_ptr - n));
			};

	};

	/******************************************************************
	 ***** arithmetic operators  *****
       a + n | n + a |        a - n              |   a - b
                          inside the class
	*******************************************************************/
	template< typename T >
	Const_VectorIterator<T> operator+(const Const_VectorIterator<T> &a, std::ptrdiff_t n)
    {
        Const_VectorIterator<T> tmp = a;
        return tmp += n;
    }

	template< typename T>
    Const_VectorIterator<const T> operator+(std::ptrdiff_t n, const Const_VectorIterator<T> &a)
    {
        return (a + n);
    }

	template<typename T>
    Const_VectorIterator<T> & operator-(const Const_VectorIterator<T> &a, std::ptrdiff_t n)
    {
        Const_VectorIterator<T> t(a);
        return t-=n;
    }
	// template <typename T>// declare as friend in the class
    // std::ptrdiff_t operator-(const VectorIterator<const T> &a, const VectorIterator<const T> &b)
    // {
    //     return (a.m_ptr - b.m_ptr);
    // }
}

#endif
