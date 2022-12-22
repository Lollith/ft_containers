/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:31:04 by agouet            #+#    #+#             */
/*   Updated: 2022/12/22 18:16:33 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define  VECTOR_HPP

# include <iostream>

namespace ft {
	template < typename T, typename Alloc = std::allocator<T> >// si pas de precision Alloc va compiler comme type T de la classe std::allocator
	class Vector{
		public:
//---------------------------------------------constructor----------------------
//(1)empty 

//(2)fill

//(3)range

//(4)copy
	
//---------------------------------------------members fct----------------------

//---------------------------------------------overloards-----------------------

//---------------------------------------------non member fct-------------------

//---------------------------------------------iterators------------------------

		private:
		T 														_value_type;
		Alloc													_allocator_type;
		_allocator_type::reference								_reference;
		typedef typename _allocator_type::const_reference 		_const_reference; //typename rappeler pour pas que le compilateur se perde // type def =alias ,evite les using 
		_allocator_type::pointer								_pointer;
		_allocator_type::const_pointer							_const_pointer;
		ptrdiff_t												_diference_type;
		size_t													_size_type;
	//iterators??
		
		
		
	
	};

}

#include "vector.tpp"

#endif