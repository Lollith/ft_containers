/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:30 by agouet            #+#    #+#             */
/*   Updated: 2023/02/01 13:42:51 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "utils/pair.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include  "RBT/RBT.hpp" 

namespace ft{

//std::less
// Objects of this class can be used on standard algorithms
// returning whether the first argument compares less than the second (x<y)
// class compare = std::less<key> => par deffaut va tier du plus petit au plus grand
// Compare: A binary predicate that takes two element keys as arguments and returns a bool.
// va transmettre le less au RBT

template < typename Key, typename T, typename Compare = std::less< Key >, typename Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
		

	public: 
		
//--------------------------Alias for intern class-------------------------------		
			typedef	Key												key_type;
			typedef	T												mapped_type;
			typedef	typename ft::pair<const key_type, mapped_type>	value_type;

//------------------------------------intern class-------------------------------
		// class interne value_comp :Returns a comparison object that can be used to compare 
		// two elements to get whether the key of the first one goes before the second.
		class value_compare 
		{
			//  friend class map; // peut utiliser tous les membres privees ou proteges de map ??

			protected:
			Compare 						comp;

			value_compare (Compare c) : comp(c) {};  // constructed with map's comparison object
		
	public:
			typedef bool 					result_type;
			typedef value_type 				first_argument_type;
			typedef value_type 				second_argument_type;

			bool 	operator() (const value_type& x, const value_type& y) const{
				return comp(x.first, y.first);
			}

		}; // class value_comp
		
//------------------------------------------Alias-------------------------------		
			typedef	Compare											key_compare;
			typedef	Alloc											allocator_type;
			// typedef	value_compare										value_compare;

			// typedef	typename allocator_type::reference				reference;
			// typedef	typename allocator_type::const_reference		const_reference;
			// typedef	typename allocator_type::pointer				pointer;
			// typedef	typename allocator_type::const_pointer			const_pointer;
			// typedef	ft::Iterator_map<Key, T, Alloc>					iterator;
			// typedef	ft::constIterator_map<Key, T, Alloc>			const_iterator;
			// typedef	typename ft::reverse_iterator<iterator>			reverse_iterator;
			// typedef	typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			typedef	ptrdiff_t										difference_type;
			typedef	size_t											size_type;
	
	
//-------------------------------------attributs--------------------------------			
			
	private:
// 			typedef	ft::RBT_node<value_type, allocator_type>	node;

			key_compare 							_comp;
			allocator_type 							_alloc;
			RBT<value_type, Compare, Alloc> 		_tree;


	public: 
			//---------------------------constructor// destructor---------------
//empty (1)	
		explicit map( const key_compare& comp = key_compare(), 
			const allocator_type& alloc = allocator_type() );
//range (2)	
		template <class InputIterator>  
		map(typename ft::enable_if< !ft::is_integral< InputIterator> ::value, 
		InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), 
		const allocator_type& alloc = allocator_type());
// //copy (3)	
		map ( const map &copy );

		~map( void );


			//------------------------------operator=---------------------------
		map &operator=( const map &rhs );

			//-------------------------iterators--------------------------------


			//----------------------------capacity------------------------------
		
		bool empty() const;


			//----------------------------access--------------------------------



			//------------------------modifier----------------------------------



			//-----------------------observers----------------------------------


			//---------------------------------operations-----------------------


			//--------------------------------allocator-------------------------
	
	}; //map
}// ft

#include "map.tpp"

#endif

