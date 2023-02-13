/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:48 by agouet            #+#    #+#             */
/*   Updated: 2023/02/13 16:36:09 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP
# include "RBT_node.hpp"
# include <memory>
# include <iostream>
# include "../iterators/RBT_iterator.hpp"
# include "../utils/pair.hpp"
#include "../iterators/reverse_iterator.hpp"

//https://www.programiz.com/dsa/red-black-tree
// Compare et Allocator = default envoye par map

namespace ft{

	template < typename Key, typename T, typename Compare = std::less< Key >, 
		    typename Allocator = std::allocator<ft::pair<const Key, T> > >
	// template< class Key, class T, class Compare, class Allocator>
	class RBT
	{
		public:
			typedef RBT_node< Key, T >						node_type; // creer mon type node dapres mon RBT_node 
			typedef Key										key_type;
			typedef	T 										mapped_type;
			typedef Allocator								allocator_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef node_type*								pt_node;
			typedef std::size_t								size_type;
			
			typedef typename Allocator::template rebind<RBT_node<Key, T> >::other 	node_allocator; //rebind
			//map=>alloc=> aloue des paires,  RBT, objet de map =+ alloc => dc des paires => 
			//ms je veux allouer des node et non des paris => rebind permet de redefinir ce 
			//que je veux allouer, le template de l allocator
			typedef RBT_iterator<Key, T> 					iterator;
			typedef RBT_const_iterator<Key, T> 				const_iterator;
			typedef ft::reverse_iterator<const_iterator> 	const_reverse_iterator;
			typedef ft::reverse_iterator<iterator> 			reverse_iterator;
			
		private:
			pt_node										_root;
			pt_node										_leaf;//TNULL _null_node
			allocator_type								_alloc;
			Compare										_comp; //save  ma fonction de comparaison,
			
			node_allocator								_node_alloc; //rebind
			
			
		public:
	//-----------------------------------constructor------------------------
					
							RBT( const Compare &comp = Compare(), const allocator_type &alloc = allocator_type());
							~RBT( void );
							RBT( const RBT &copy);
		RBT 				&operator=( const RBT &rhs);

	//-------------------------------- capacity-----------------------------
		
		bool				empty( void )  const;
		void				size_helper( pt_node nd, size_t *i ) const;
		size_type			size( void ) const;
		size_type			max_size( void ) const;
	
	//------------------------modifier----------------------------------

		void 				clear ( void );

	//----------------------------------- search------------------------
 		
		pt_node				searchTreeHelper( pt_node node, Key k );
		pt_node				searchTree( Key k );
		
		iterator 			find(const Key &key);
		const_iterator		find(const Key &key) const;
	
	//--------------------------------------- operations -------------------------
		
		pt_node				insert_node( value_type pair_data );
		void				insert_balancing( pt_node new_node );

		void				delete_helper( pt_node node, key_type key );
		void				delete_node( key_type key );
		
		void				delete_balancing( pt_node x );


	//---------------------------------------- tools----------------------------
	
		pt_node				minimum( pt_node node ) const;
		pt_node				maximum( pt_node node) const;	
		void				delete_tree( pt_node root );
		void				copy_tree(pt_node old_root, RBT &new_rbt );

		void				rightRotate( pt_node x );
		void				leftRotate( pt_node x );
		void				rbTransplant( pt_node u, pt_node v );


	//----------------------------------iterator--------------------------------
		
		iterator	 			begin( void );
		const_iterator			begin( void ) const;
		iterator				end( void );
		const_iterator			end( void ) const;
		reverse_iterator 		rbegin( void );
		const_reverse_iterator 	rbegin( void ) const;
		reverse_iterator 		rend( void );
		const_reverse_iterator 	rend(void) const;
		
	//----------------------------------------affichage ------------------------
		// void preOrderHelper	(pt_node node);

		//helper permettent d appeler des attribut prive => appel dune 2eme fct 
		//qui appel helper qui elle peut etre utlisee ds le main
		void					display_helper( pt_node &root, std::string indent, bool last );
		void					display( void );

		
	
	
	};	



	
}//ft

#include "RBT.tpp"
#endif