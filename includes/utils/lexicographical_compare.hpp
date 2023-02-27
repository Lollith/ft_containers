/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:37:40 by agouet            #+#    #+#             */
/*   Updated: 2023/02/27 15:26:06 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2/*._current*/ < *first1/*._current*/)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

// 	template< class InputIt1, class InputIt2 >
// bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
//                               InputIt2 first2, InputIt2 last2 )
// {
// 	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
//         if (*first1 < *first2) return true;
//         if (*first2 < *first1) return false;
//     }
//     return (first1 == last1) && (first2 != last2);
// }

// template< class InputIt1, class InputIt2, class Compare >
// bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
//                               InputIt2 first2, InputIt2 last2,
//                               Compare comp )
// {
// 	for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
//         if (comp(*first1, *first2)) return true;
//         if (comp(*first2, *first1)) return false;
//     }
//     return (first1 == last1) && (first2 != last2);
// }
}
//comp
//Binary function that accepts two arguments of the types pointed by the iterators,
// and returns a value convertible to bool.Binary function that accepts two arguments 
//of the types pointed by the iterators, and returns a value convertible to bool.	


#endif