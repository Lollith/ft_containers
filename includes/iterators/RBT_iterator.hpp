/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:17:30 by agouet            #+#    #+#             */
/*   Updated: 2023/02/27 09:31:44 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
#define RBT_ITERATOR_HPP

#include "../RBT/RBT_node.hpp"

namespace ft{
// ietrator = adresse dun noeud=> me deplace de noeud en noeud, sachnt que 
//je vais chercher le +proche existant, deplacement de pas en pas
template < class Key, class T >
struct RBT_iterator; // car present ds ma structure RBT_iterator => ne marche pas

template < class Key, class T >
struct RBT_const_iterator; // car present ds ma structure RBT_iterator => ne marche pas


//____________________________________________________________________________//
//____________________________________RBT_it__________________________________//
template <class Key, class T>
struct RBT_iterator
{
		typedef ft::pair< Key, T > 							value_type; //const key
		typedef value_type&									reference;
		typedef value_type*									pointer;

		typedef std::bidirectional_iterator_tag 			iterator_category;
		typedef std::ptrdiff_t 								difference_type;

		typedef ft::RBT_node< Key, T > 						node_type;
		typedef node_type									*pt_node;
		
		typedef RBT_iterator< Key, T >						iterator;
		typedef RBT_const_iterator< Key, T > 				const_iterator;

	//--------------------------------------------attribut----------------------
		pt_node												_current;

	//--------------------------------------------constructor-------------------

		RBT_iterator( void );
		RBT_iterator( pt_node input );
		RBT_iterator( const RBT_iterator &cpy );
		RBT_iterator &operator=( const RBT_iterator &other );
		~RBT_iterator ( void );

	//--------------------------------------accessor----------------------------

		pt_node base( void ) const;
	
	//---------------------------------------operator---------------------------
		reference operator*( void ) const;
		pointer operator->( void ) const;
		iterator &operator++( void );
		iterator operator++( int );
		iterator &operator--( void );
		iterator operator--( int );
		iterator operator+( difference_type n ) const;
		iterator operator-( difference_type n ) const;
		
	};
	
	template < class Key, class T >
	inline bool operator==(const RBT_iterator< Key, T> &lhs, 
		const RBT_iterator< Key, T> &rhs);

	template < class Key, class T >
	inline bool operator==( const RBT_iterator< Key, T> &lhs, 
		const RBT_const_iterator< Key, T> &rhs );

	template < class Key, class T >
	inline bool operator!=( const RBT_iterator< Key, T> &lhs, 
		const RBT_iterator< Key, T> &rhs );

	template < class Key, class T >
	inline bool operator!=( const RBT_iterator< Key, T> &lhs, 
		const RBT_const_iterator< Key, T>  &rhs );
		
		
//____________________________________________________________________________//
//____________________________________RBT_const_it____________________________//

	template <class Key, class T>
	struct RBT_const_iterator
	{
		typedef pair<  Key, T> 								value_type;
		typedef const value_type 							&reference;
		typedef const value_type 							*pointer;

		typedef std::bidirectional_iterator_tag 			iterator_category;
		typedef std::ptrdiff_t 								difference_type;

		typedef const ft::RBT_node<Key, T> 					node_type;
		typedef node_type									*pt_node;
		
		typedef RBT_const_iterator<Key, T> 					const_iterator;
		typedef RBT_iterator<Key, T>						iterator;
		
	//--------------------------------------------attribut----------------------
		pt_node												_current;

	//--------------------------------------------constructor-------------------
		RBT_const_iterator( void );
		RBT_const_iterator( pt_node input);
		RBT_const_iterator(const RBT_const_iterator &cpy);
		RBT_const_iterator &operator=( const RBT_const_iterator &other );
		~RBT_const_iterator ( void );
		
	//--------------------------------------accessor----------------------------
		pt_node base( void ) const;

	//---------------------------------------operator---------------------------
		reference operator*( void ) const;
		pointer operator->( void ) const;

		const_iterator &operator++( void );
		const_iterator operator++( int );
		const_iterator &operator--( void );
		const_iterator operator--( int );
		const_iterator operator+( difference_type n ) const;
		const_iterator operator-( difference_type n ) const;

	};

	template < class Key, class T >
	bool operator==( const RBT_const_iterator< Key, T> &lhs, 
		const RBT_const_iterator< Key, T> &rhs );

	template < class Key, class T >
	bool operator==( const RBT_const_iterator< Key, T> &lhs, 
		const RBT_iterator< Key, T> &rhs );

	template < class Key, class T >
	bool operator!=( const RBT_const_iterator< Key, T> &lhs, 
		const RBT_const_iterator< Key, T> &rhs );

	template < class Key, class T >
	bool operator!=( const RBT_const_iterator< Key, T> &lhs, 
		const RBT_iterator< Key, T> &rhs );

		
//-------------------------------------no member:helper-------------------------
	template <class Key, class T>
	static RBT_node< Key, T>* helper_rb_tree_increment( RBT_node<Key, T> *pt_node );

	template <class Key, class T>
	RBT_node<Key, T> *rb_tree_increment( RBT_node<Key, T> *pt_node );

	template <class Key, class T>
	RBT_node<Key, T> *rb_tree_increment( const RBT_node<Key, T> *pt_node );
	
	
	template <class Key, class T>
	static RBT_node< Key, T>* helper_rb_tree_decrement( RBT_node<Key, T> *pt_node );
	
	template <class Key, class T>
	RBT_node<Key, T> *rb_tree_decrement( RBT_node<Key, T> *pt_node );

	template <class Key, class T>
	RBT_node<Key, T> *rb_tree_decrement( const RBT_node<Key, T> *pt_node );


}//ft
#include "RBT_iterator.tpp"
#endif
