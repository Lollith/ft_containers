/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:55:07 by agouet            #+#    #+#             */
/*   Updated: 2023/01/03 17:50:58 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	//rndom_access_iterator = iterator des vecteurs
	
	// n herite pas forcement des caracteristiques de la class iterator , 
	//mais signale quelle appartient au genre des iterators, pour etre 
	//reconnaissable et utilisable en tant que tel car iterator obeissent a une certaine interface
	

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define  RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>
# include "iterator_traits.hpp"

namespace ft {
	
	template < typename It >
	class random_access_iterator: : public std::iterator<typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference>
	{

		public:
		//Définissez les types de pointeur et de référence pour itérateur 
		// en utilisant les types de votre conteneur comme modèle. 
			typedef It												iterator_type;
			typedef typename iterator_traits<It>::iterator_category	iterator_category;
			typedef typename iterator_traits<It>::value_type		value_type;
			typedef typename iterator_traits<It>::difference_type	difference_type;
			typedef typename iterator_traits<It>::pointer			pointer;
			typedef typename iterator_traits<It>::reference			reference;

		protected:
			pointer								_current;
		
		public:
		//--------------------------------constructors--------------------------

		random_access_iterator(void);
		explicit random_access_iterator(pointer pt);
		
		template< class U >
		random_access_iterator( const random_access_iterator<U> &other );
		
		~random_access_iterator( void ); 
		
	
		//-------------------------------members--------------------------------	

		template< class U >
		random_access_iterator &operator=(const random_access_iterator<U> &other);
		pointer base() const;
		
		reference operator*() const;
		pointer operator->() const;
		reference operator[] ( difference_type n);
		
		random_access_iterator &operator++();
		random_access_iterator &operator--();
		random_access_iterator operator++( int );
		random_access_iterator operator--( int );
		
		random_access_iterator operator+( difference_type n ) const;
		random_access_iterator operator-( difference_type n ) const;
		
		random_access_iterator &operator+=( diference_type n );
		random_access_iterator &operator-=( diference_type n );
	
	};

	template< class T1, class T2>
	

} //namespace ft


#include "random_access_iterator.tpp"

#endif