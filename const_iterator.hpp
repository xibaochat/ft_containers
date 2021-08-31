#ifndef CONST_ITERATOR
# define CONST_ITERATOR

namespace ft
{
	template <typename T>
	class Const_VectorIterator
	{
	private:
		typedef size_t          size_type;
		typedef std::ptrdiff_t  difference_type;
		typedef const T         value_type;
		typedef const T*        const_pointer;
		typedef const T&        const_reference;
		typedef std::random_access_iterator_tag iterator_category;

	private:
		typedef Const_VectorIterator<T> _Self;
		const_pointer m_ptr;
		Const_VectorIterator(const_pointer ptr):m_ptr(ptr){}//need move to privee
	public:
		/*******************************************
        *****  Member Functions (Coplien Form) *****
        *******************************************/
		Const_VectorIterator():m_ptr(NULL){}
		Const_VectorIterator(const _Self &obj):m_ptr(obj.m_ptr){}
		_Self &operator=(const _Self &src)
		{
			this->m_ptr = src.m_ptr;
			return (*this);
		}
		~Const_VectorIterator(){}

		template <typename U>
		friend std::ptrdiff_t operator-( const VectorIterator<const U> &a, const VectorIterator<const U> &b);
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

		_Self & operator+=(size_type n)
        {
            m_ptr += n;
            return (*this);
        }
		_Self &operator-=(size_type n)
        {
                m_ptr -= n;
                return (*this);
        }
		/******************************************************************
		 ****** dereference  *****
		 *a | a->m | *a = t | a[n]
		*************************************************************/
		const_reference operator*() const {return *m_ptr;}
		const_pointer operator->() {return m_ptr;}
		const_reference operator[](size_type n){return m_ptr[n];}

		template<typename U,  class Allocator>
		friend class Vector;
	};

	/******************************************************************
	 ***** arithmetic operators  *****
       a + n | n + a | a - n | a - b
	*******************************************************************/
	template< typename T >
	VectorIterator<const T> operator+(VectorIterator<const T> &a, size_t n)
    {
        VectorIterator<const T> tmp = a;
        return tmp += n;
    }

	template< typename T>
    VectorIterator<const T> operator+(size_t n, VectorIterator<T> &a)
    {
        return (a + n);
    }

	template<typename T>
    VectorIterator<T> & operator-(VectorIterator<const T> &a, size_t n)
    {
        VectorIterator<T> t(a);
        return t-=n;
    }

	template <typename T>// declare as friend in the class
    std::ptrdiff_t operator-(const VectorIterator<const T> &a, const VectorIterator<const T> &b)
    {
        return (a.m_ptr - b.m_ptr);
    }
}

#endif
