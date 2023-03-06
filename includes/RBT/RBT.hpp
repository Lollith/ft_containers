/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:48 by agouet            #+#    #+#             */
/*   Updated: 2023/03/01 11:12:24 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

# include <memory>
# include <iostream>
# include <functional> // std::less
# include "../RBT/RBT_node.hpp"
# include "../iterators/RBT_iterator.hpp"
# include "../utils/pair.hpp"
# include "../iterators/reverse_iterator.hpp"

//https://www.programiz.com/dsa/red-black-tree
// Compare et Allocator = default envoye par map

namespace ft{

	template < typename Key, typename T, typename Compare, typename Allocator > // recup linfo de map , pas besoin de remettre par default
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
			typedef Compare									key_compare;
			
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
			pt_node										_leaf;
			pt_node										_leaf_max;
			pt_node										_leaf_min;
			allocator_type								_alloc;
			key_compare									_comp; //save  ma fonction de comparaison,
			
			node_allocator								_node_alloc; //rebind
			
			
		public:
	//-----------------------------------constructor------------------------
					
				RBT( const Compare &comp = Compare(), const allocator_type &alloc = allocator_type());
				~RBT( void );
				RBT( const RBT &copy);
		RBT 	&operator=( const RBT &rhs);

	//-------------------------------- capacity-----------------------------
		
		bool				empty( void )  const;
		void				size_helper( pt_node nd, size_t *i ) const;
		size_type			size( void ) const;
		size_type			max_size( void ) const;
	
	//------------------------modifier----------------------------------

		void 				clear ( void );
		void				swap ( RBT &other );
	//----------------------------------- search------------------------
 		
		pt_node				searchTreeHelper( pt_node node, Key k );
		pt_node				searchTreeHelper( pt_node node, const Key k ) const;
		pt_node				searchTree( Key k );
		pt_node				searchTree( Key const k ) const;
		
		iterator 			find( const Key &key );
		const_iterator		find( const Key &key ) const;

		iterator			lower_bound( const key_type& k );
		const_iterator		lower_bound( const key_type& k ) const;
		iterator			upper_bound( const key_type& x );
		const_iterator		upper_bound( const key_type& x ) const;
		
		mapped_type			&access_operator( const key_type& x );
		mapped_type& 		at( const key_type& k );
		const mapped_type& 	at( const key_type& k ) const;
	
	
	//-----------------------observers------------------------------------------
	
		key_compare 		key_comp( void ) const;
		allocator_type		getAllocator( void ) const;
	
	//--------------------------------------- operations -------------------------
		
		pt_node				insert_node( value_type pair_data );
		iterator			insert_node_it( const value_type &value);
		pt_node				insert_node_position( value_type pair_data, iterator position );
		iterator			insert_node_pos( iterator position, const value_type &value );
		void				insert_balancing( pt_node new_node );

		void				erase_node( iterator pos );
		void				delete_helper( pt_node node, key_type key );
		void				delete_node( key_type key );
		void				delete_balancing( pt_node x );



	//---------------------------------------- tools----------------------------
	
		pt_node				minimum( pt_node node ) const;
		pt_node				maximum( pt_node node) const;	
		void				delete_tree( pt_node root );
		void				copy_tree( pt_node old_root, RBT &new_rbt );

		void				rightRotate( pt_node x );
		void				leftRotate( pt_node x );
		void				rbTransplant( pt_node u, pt_node v );
		void				replace_extremity( void );	

	//----------------------------------iterator--------------------------------
		
		iterator	 			begin( void );
		const_iterator			begin( void ) const;
		iterator				end( void );
		const_iterator			end( void ) const;
		reverse_iterator 		rbegin( void );
		const_reverse_iterator 	rbegin( void ) const;
		reverse_iterator 		rend( void );
		const_reverse_iterator 	rend( void ) const;
		
	//----------------------------------------affichage ------------------------

		//helper permettent d appeler des attribut prive => appel dune 2eme fct 
		//qui appel helper qui elle peut etre utlisee ds le main
		void					display_helper( pt_node &root, std::string indent, bool last );
		void					display( void );

		
	};	



	
}//ft

#include "RBT.tpp"
#endif