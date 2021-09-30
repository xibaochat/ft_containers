#ifndef MAP_HPP
# define MAP_HPP

#include "Utility/main.hpp"
namespace ft
{
	//           key_type	, mapped_type,  key_compare
 	template<class Key, class T, class Compare = std::less<Key>,
			 class Allocator = std::allocator<ft ::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key                                       key_type;
		typedef T                                         mapped_type;
		typedef ft::pair<const Key, T>                    value_type;
		typedef Compare                                   key_compare;
		typedef value_type&                               reference;
		typedef const value_type&                         const_reference;
		typedef value_type*                               pointer;
		typedef const value_type*                         const_pointer;
		typedef std::size_t                               size_type;
		typedef std::ptrdiff_t                            difference_type;
		typedef Allocator                                 allocator_type;
		//it

		key_compare key_comp() const
		{
			return Compare();
		}
//		template <class Key, class T, class Compare, class Alloc>
		class value_compare: std::binary_function<value_type,value_type,bool>
		{
			friend class map;
		protected:
			Compare comp;//obj from std::less
			value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			bool operator() (const value_type& x, const value_type& y) const
     		{
				return comp(x.first, y.first);
  			}
		};

		value_compare value_comp() const
		{
			return value_comp(Compare());
		}

	};






}

#endif
//https://stackoverflow.com/questions/21476869/constant-pointer-vs-pointer-to-constant
