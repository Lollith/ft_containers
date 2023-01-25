/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:48 by agouet            #+#    #+#             */
/*   Updated: 2023/01/25 17:58:38 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP
# include "RBT_node.hpp"
# include <memory>

// Compare et Allocator = default envoye par map

namespace ft{

	template < typename Key, typename T, typename Compare = std::less< Key >, typename Allocator = std::allocator<ft::pair<const Key, T> > >
	// template< class Key, class T, class Compare, class Allocator>
	class RBT
	{
		public:
			typedef typename ft::RBT_node< Key, T >		node_type; // creer mon type node dapres mon RBT_node 
			typedef Key									key_type;
			typedef	T 									mapped_type;
			typedef Allocator							allocator_type;
			typedef pair<const key_type, mapped_type>	value_type;
			typedef node_type*							pt_node;

		private:
			pt_node										_root;
			pt_node										_null;
			allocator_type								_alloc;
			Compare										_comp; //save  ma fonction de comparaison,
			
			
		public:
		//-----------------------------------constructor------------------------
		RBT( const Compare &comp = Compare(), const allocator_type &alloc = allocator_type());
		~RBT( void );
		RBT( const RBT &copy);
		RBT &operator=(const RBT &rhs);

	//--------------------------------------- rotation -------------------------
	
	//----------------------------------------affichage ------------------------
		void preOrderHelper	(pt_node node);
			
	};	




	
}//ft

#include "RBT.tpp"
#endif