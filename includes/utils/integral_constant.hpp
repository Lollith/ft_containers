/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:34:27 by agouet            #+#    #+#             */
/*   Updated: 2023/01/13 10:47:36 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// It inherits from integral_constant as being either true_type or false_type,
//  depending on whether T is an integral type
// https://cplusplus.com/reference/type_traits/integral_constant/

#ifndef INTEGRAL_CONSTANT_HPP
#define INTEGRAL_CONSTANT_HPP


namespace ft
{

	template <class T, T v>
	struct integral_constant
	{
		typedef T 							value_type;
		typedef integral_constant<T, v>		type;
		
		static const						T value = v;
		
		operator T() const {return v;}
	};

	typedef integral_constant< bool, true >		true_type;
	typedef integral_constant< bool, false >	false_type;
}

#endif