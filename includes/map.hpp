/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:30 by agouet            #+#    #+#             */
/*   Updated: 2023/03/01 13:23:49 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <functional> // std::less
# include "utils/equal.hpp"
# include "utils/pair.hpp"
# include "utils/lexicographical_compare.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "RBT/RBT.hpp"
# include "iterators/RBT_iterator.hpp" 
# include "iterators/reverse_iterator.hpp"

namespace ft{

//std::less
// Objects of this class can be used on standard algorithms
// returning whether the first argument compares less than the second (x<y)
// class compare = std::less<key> => par deffaut va tier du plus petit au plus grand
// Compare: A binary predicate that takes two element keys as arguments and returns a bool.
// va transmettre le less au RBT


//less = un type ici
template < typename Key, typename T, typename Compare = std::less< Key >, typename Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
	
		public: 
		
//--------------------------Alias for intern class-------------------------------		
			typedef	Key												key_type;
			typedef	T												mapped_type;
			typedef pair< const key_type, mapped_type>				value_type; 
			typedef	Compare											key_compare;

//------------------------------------intern class-------------------------------
		// class interne value_comp :Returns a comparison object that can be used to compare 
		// two elements to get whether the key of the first one goes before the second.
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			 friend class map; // peut utiliser tous les membres privees ou proteges de map 

			protected:
			Compare 											comp;

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
			typedef	Alloc											allocator_type;
			typedef	value_type										&reference;
			typedef	const value_type								&const_reference;
			typedef typename Alloc::pointer 						pointer;
			typedef typename Alloc::const_pointer 					const_pointer;
			
			typedef	ft::RBT_iterator<Key, T>						iterator;
			typedef	ft::RBT_const_iterator<Key, T>					const_iterator;
			typedef	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			typedef	std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;
	
	
//-------------------------------------attributs--------------------------------			
			
	private:
			typedef	ft::RBT_node<value_type, allocator_type>	rbt_node;

			key_compare 							_comp;
			allocator_type 							_alloc;
			RBT< Key, T, key_compare, Alloc > 		_tree;  // importance du key compare (=Compare)qui recup linfo de map vers rbt


	public: 
			//---------------------------constructor// destructor---------------
//empty (1)	
		explicit map( const key_compare& comp = key_compare(), 
			const allocator_type& alloc = allocator_type() );
//range (2)	
		template <class InputIterator>  
		map( typename ft::enable_if< !ft::is_integral< InputIterator> ::value, 
			InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), 
			const allocator_type& alloc = allocator_type() );
// //copy (3)	
		map( const map &cpy );
		
		~map( void );


			//------------------------------operator=---------------------------
		map 					&operator=( const map& rhs );
			
			//-------------------------iterators--------------------------------
		iterator 				begin( void );
		const_iterator 			begin( void ) const;
		iterator 				end( void );
		const_iterator 			end( void ) const;
		reverse_iterator 		rbegin( void );
		const_reverse_iterator 	rbegin( void ) const;
		reverse_iterator 		rend( void );
		const_reverse_iterator	rend( void ) const;

			//----------------------------capacity------------------------------
		
		bool	 				empty( void ) const;
		size_type 				size( void ) const;
		size_type				max_size( void ) const;
		
			//----------------------------access--------------------------------

		mapped_type				&operator[]( const key_type& x );
		mapped_type& 			at( const key_type& k );
		const mapped_type& 		at( const key_type& k ) const;

			//------------------------modifier----------------------------------
		pair<iterator, bool>	insert( const value_type& k );
		iterator				insert( iterator position, const value_type& k );

		template <class InputIterator>
		void 					insert( InputIterator first, InputIterator last );

		void					erase( iterator position );
		size_type 				erase( const key_type& x );
		void 					erase( iterator first, iterator last );

		void 					swap( map &other );
		void 					clear( void );

			//-----------------------observers----------------------------------
	key_compare 				key_comp() const;
	value_compare				value_comp() const;

			//---------------------------------operations-----------------------
	iterator 					find( const key_type &x );
	const_iterator 				find( const key_type& x ) const;
	
	size_type 					count( const key_type& x ) const;
	
	iterator					lower_bound( const key_type& x );
	const_iterator				lower_bound( const key_type& x ) const;
	iterator					upper_bound( const key_type& x );
	const_iterator				upper_bound( const key_type& x ) const;

	pair<iterator,iterator> 	equal_range( const key_type& x );
	pair<const_iterator,const_iterator> 
								equal_range( const key_type& x ) const;

			//--------------------------------allocator-------------------------
	allocator_type 				get_allocator( void ) const;
	
	}; //map


template <class Key, class T, class Compare, class Allocator>
bool 	operator==(const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool 	operator<(const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool 	operator!=(const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool 	operator> (const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool 	operator>=(const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);

template <class Key, class T, class Compare, class Allocator>
bool 	operator<=(const map<Key,T,Compare,Allocator>& x,
const map<Key,T,Compare,Allocator>& y);

// specialized algorithms:
template <class Key, class T, class Compare, class Allocator>
void 	swap(map<Key, T, Compare, Allocator>& x,
map<Key, T, Compare, Allocator>& y);


}// ft

#include "map.tpp"

#endif

