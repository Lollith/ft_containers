/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:49:54 by agouet            #+#    #+#             */
/*   Updated: 2023/01/11 18:07:32 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{

	// Compares the elements in the range [first1,last1) 
	// with those in the range beginning at first2, and returns true 
	// if all of the elements in both ranges match.
	
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1) 
		{
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	//BinaryPredicate: binary fct hat accepts two elements as argument 
	//(one of each of the two sequences, in the same order), and returns a value convertible to bool.
	//ex sur cplusplus: i==j equivaux a la 1ere verion de equal au dessus.
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1) 
		{
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
}

#endif