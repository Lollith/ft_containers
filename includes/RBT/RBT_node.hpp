/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:24 by agouet            #+#    #+#             */
/*   Updated: 2023/01/20 18:17:06 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP
#include <memory>
#include <iostream>

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
	template < class Key, class T >
	struct RBT_node
	{
			typedef pair< const Key, T>		value_type;
// voir mamhed
	
			// T				_value;
			t_color			_color;
			RBT_node		*_parent;
			RBT_node		*_left;
			RBT_node		*_right;
			value_type		pair_data;
			bool 			leaf;

			RBT_node( void );
			RBT_node( value_type pair_init );
			~RBT_node( void );


	

	};
	
	
	
}// ft

#include "RBT_node.tpp"

#endif