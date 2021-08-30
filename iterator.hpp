#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{
	template <typename T>
	class VectorIterator
	{
	public:
		typedef size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	private:
		typedef VectorIterator<T> _Self;

		//should put inside private
		pointer m_ptr;
	public:
		VectorIterator(pointer ptr) : m_ptr(ptr){}
		VectorIterator(): m_ptr(NULL){}//default

		VectorIterator(const _Self &obj):m_ptr(obj.m_ptr){}
		~VectorIterator(){}//destructor
		_Self &operator=(const _Self &src)//b = a;
		{
			this->m_ptr = src.m_ptr;
			return *this;
		}

		reference operator*() const {return *m_ptr;}
		pointer operator->() {return m_ptr;}

		//prefix-increase :++a
		_Self& operator++() { m_ptr++; return *this;}

		//post-increase : a++
		_Self operator++(int)
		{
			_Self obj(*this);
			m_ptr++;
			return (obj);
		}

		friend bool operator==(const _Self& a, const _Self& b){return (a.m_ptr == b.m_ptr);}
		friend bool operator!=(const _Self& a, const _Self& b){return !(a.m_ptr == b.m_ptr);}
		friend bool operator<(const _Self& a, const _Self& b){return (a.m_ptr < b.m_ptr);}
		friend bool operator<=(const _Self& a, const _Self& b){return (a.m_ptr <= b.m_ptr);}
		friend bool operator>(const _Self& a, const _Self& b){return (a.m_ptr > b.m_ptr);}
		friend bool operator>=(const _Self& a, const _Self& b){return (a.m_ptr >= b.m_ptr);}

		template <typename U>
		friend std::ptrdiff_t operator-( const VectorIterator<U> &a, const VectorIterator<U> &b);

		//prefix-decrease :--a
		_Self operator--() {m_ptr--; return *this;}
		//post-decrease :a--
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
		reference operator[](size_type n){return m_ptr[n];}
		template<typename U,  class Allocator>
		friend class Vector;
		/*Vector can visit all attribute*/

	};

	template <typename T>// declare in the class
	std::ptrdiff_t operator-(const VectorIterator<T> &a, const VectorIterator<T> &b)
	{
		return (a.m_ptr - b.m_ptr);
	}

	template<typename T>
	VectorIterator<T> & operator-(VectorIterator<T> &a, size_t n)
	{
		VectorIterator<T> t(a);
		return t-=n;
	}
	template< typename T >
		VectorIterator<T> operator+(VectorIterator<T> &a, size_t n)
	{
		VectorIterator<T> tmp = a;
        return tmp += n;
	} //https://stackoverflow.com/questions/2425906/operator-overloading-outside-class

	template< typename T>
	VectorIterator<T> operator+(size_t n, VectorIterator<T> &a)
	{
		return (a + n);
	}
}


#endif