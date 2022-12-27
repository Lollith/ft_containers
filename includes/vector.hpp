/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:31:04 by agouet            #+#    #+#             */
/*   Updated: 2022/12/27 18:04:06 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define  VECTOR_HPP

# include <iostream>

namespace ft {
	//allocator = class
	template < typename T, typename Alloc = std::allocator<T> >// si pas de precision Alloc va compiler comme type T de la classe std::allocator
	class Vector{
		public:
//---------------------------------------------constructor----------------------
//(1)empty
 Vector( void );

//(2)fill
Vector( size_t n );
//(3)range
Vector ( T first, T last);
//(4)copy
Vector (Vector const &copy);
//destructeur
~Vector( void );
//operator=

//---------------------------------------------members fct----------------------

//---------------------------------------------overloards-----------------------

//---------------------------------------------non member fct-------------------

//---------------------------------------------iterators------------------------

		private:
		typedef T 														_value_type;
		typedef Allocator													_allocator_type;
		typedef typename _allocator_type::reference				_reference;
		typedef typename _allocator_type::const_reference 		_const_reference; //typename rappeler pour pas que le compilateur se perde // type def =alias ,evite les using 
		typedef typename _allocator_type::pointer				_pointer;
		typedef typename _allocator_type::const_pointer			_const_pointer;
		typedef std::ptrdiff_t												_diference_type;
		typedef std::size_t													_size_type;
	//iterators??
	
		//The container keeps an internal copy of alloc, which is used to allocate storage throughout its lifetime.
		Allocator		_alloc;
		
		
	
	};

}

#include "vector.tpp"

#endif