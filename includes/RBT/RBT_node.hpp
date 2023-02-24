/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:24 by agouet            #+#    #+#             */
/*   Updated: 2023/02/24 16:03:27 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

#include <memory>
#include <iostream>
#include "pair.hpp"
#include "make_pair.hpp"

namespace ft {
	
	typedef enum e_color
	{
		BLACK,
		RED
	}			t_color;


	// template < class T, class Allocator = std::allocator<T> >
	// class RBT_node
	// {
	// 	private:
	// 		T				_value;
	// 		t_color			_color;
	// 		RBT_node		*_left;
	// 		RBT_node		*_right;
	// 		RBT_node		*_parent;
	// 		Allocator		_alloc;
		
	// 	public:
	// 		RBT_node( const Allocator &alloc = Allocator() ); // si RBT_node( void ) => Alloc par default
	// 		~RBT_node( void );
	// 		RBT_node(RBT_node const &copy);
	// 		RBT_node &operator=(const RBT_node &rhs);

	// 	//surcharge
	// 		RBT_node(const T &value, t_color color, RBT_node *left, RBT_node *right, 
	// 			RBT_node *parent, const Allocator &alloc = Allocator());



// In each node, there is a boolean value x.leaf which is true if x is a leaf.
// https://www.programiz.com/dsa/b-tree
	template < class Key , class T >
	struct RBT_node
	{
			typedef ft::pair< Key, T >		value_type;

			t_color							_color;
			RBT_node						*_parent;
			RBT_node						*_left;
			RBT_node						*_right;
			value_type						_pair_data;
			bool 							_is_leaf;
			
			

			RBT_node( void );
			RBT_node( value_type pair_init );
			~RBT_node( void );
			RBT_node( RBT_node const &copy );
			RBT_node &operator=( const RBT_node &rhs );
	
			// RBT_node( RBT_node *parent );// utile?
			
			// RBT_node( t_color color, RBT_node *parent, RBT_node *left, RBT_node *right, value_type pair_data );

//--------------------------------------ft membres -----------------------------
		value_type *value_ptr( void );
		const value_type *value_ptr( void ) const;
		const value_type &value_ref( void ) const;
		value_type &value_ref( void );

	
	};
	
	
}// ft

#include "RBT_node.tpp"

#endif