/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:34:27 by agouet            #+#    #+#             */
/*   Updated: 2023/01/13 10:49:56 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

# include "integral_constant.hpp"
// It inherits from integral_constant as being either true_type or false_type,
//  depending on whether T is an integral type


namespace ft
{
	//-------------------------false--------------------------------------------
	template< class T >
	struct is_integral: false_type {};
	
	//equivalent a : 
	//struct is_integral: integral_constant< bool, false >{};
	//heritage de la struct, (struc sont public par default))
	
	//----------------------------const-----------------------------------------
	template< class T >
	struct is_integral<const T>: is_integral<T> {};
	
	// -----------------------------true----------------------------------------

	template <> // specialisation complete
	struct is_integral<bool> : true_type {};

	template <>
	struct is_integral<char> : true_type {};
	
	template <>
	struct is_integral<wchar_t> : true_type {};
	
	template <>
	struct is_integral<signed char> : true_type {};

	template <>
	struct is_integral<short int> : true_type {};

	template <>
	struct is_integral<int> : true_type {};
	
	template <>
	struct is_integral<long int> : true_type {};
	
	template <>
	struct is_integral<long long int> : true_type {};

	template <>
	struct is_integral<unsigned char> : true_type {};
	
	template <>
	struct is_integral<unsigned short int> : true_type {};

	template <>
	struct is_integral<unsigned int> : true_type {};

	template <>
	struct is_integral<unsigned long int> : true_type {};
	
	template <>
	struct is_integral<unsigned long long int> : true_type {};
}

#endif