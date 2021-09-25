#ifndef MAP_HPP
# define MAP_HPP

#include "Utility/main.hpp"
namespace ft
{
	//           key_type	, mapped_type,  key_compare
 	template<class Key, class T, class Compare = std::less<Key>,
			 class Allocator = std::allocator<ft ::pair<const Key, T>>>
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

	}






}

#endif
//https://stackoverflow.com/questions/21476869/constant-pointer-vs-pointer-to-constant
