/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:55:07 by agouet            #+#    #+#             */
/*   Updated: 2022/12/30 18:53:49 by agouet           ###   ########.fr       */
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
	class random_access_iterator//: public std::iterator<std::random_access_iterator_tag, It> 
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

		private:
			pointer								_current;
		
		public:
		//--------------------------------constructors--------------------------

		random_access_iterator(void);
		explicit random_access_iterator(pointer pt);
		
		template< class U >
		random_access_iterator( const random_access_iterator<U> &other);
		
		~random_access_iterator( void ); 	
	
	};

} //namespace ft


#include "random_access_iterator.tpp"

#endif