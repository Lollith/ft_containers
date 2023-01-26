/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:48 by agouet            #+#    #+#             */
/*   Updated: 2023/01/26 17:56:12 by agouet           ###   ########.fr       */
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
			pt_node										_leaf;//TNULL
			allocator_type								_alloc;
			Compare										_comp; //save  ma fonction de comparaison,
			
			
		public:
		//-----------------------------------constructor------------------------
		RBT( const Compare &comp = Compare(), const allocator_type &alloc = allocator_type());
		~RBT( void );
		RBT( const RBT &copy);
		RBT &operator=(const RBT &rhs);

	//----------------------------------- search------------------------
 		pt_node searchTreeHelper(pt_node node, Key k);
		pt_node searchTree(Key k);
	

	//--------------------------------------- operations -------------------------
		
	void insert( value_type data );
	
	//----------------------------------------affichage ------------------------
		// void preOrderHelper	(pt_node node);

		//helper permettent d appeler des attribut prive => appel dune 2eme fct 
		//qui appel helper qui elle peut etre utlisee ds le main
		void display_helper(pt_node &root, std::string indent, bool last);
		void display( void );
			
	};	


	//

	
}//ft

#include "RBT.tpp"
#endif