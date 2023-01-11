/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:11:05 by agouet            #+#    #+#             */
/*   Updated: 2023/01/11 16:17:53 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

// The type T is enabled as member type enable_if::type if Cond is true.
namespace ft
{
	template <bool Cond, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

}
#endif;