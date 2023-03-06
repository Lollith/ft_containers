/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:24 by agouet            #+#    #+#             */
/*   Updated: 2023/02/27 09:30:09 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

#include <memory>
#include <iostream>
#include "../utils/pair.hpp"
#include "../utils/make_pair.hpp"

namespace ft {
	
	typedef enum e_color
	{
		BLACK,
		RED
	}			t_color;


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
	
			
//--------------------------------------ft membres -----------------------------
		value_type *value_ptr( void );
		const value_type *value_ptr( void ) const;
	
	};
	
	
}// ft

#include "RBT_node.tpp"

#endif