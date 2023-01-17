/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:57:48 by agouet            #+#    #+#             */
/*   Updated: 2022/12/30 18:04:21 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns basic information about an iterator.
// Les traits sont des petits objets qui fournissent des informations à propos
// d'un autre objet (ou algorithme) pour déterminer la marche à suivre ou
// des détails d'implémentation.
//=>unifier iterators, pointeurs et const-pointeurs. On fournit 5 typedefs,
// c'est la projection des typedefs de std::iterator. 

#ifndef ITERATORS_TRAITS_HPP
# define ITERATORS_TRAITS_HPP

namespace ft
{
	template <typename _Iterator>
	struct iterator_traits
	{
		typedef typename _Iterator::iterator_category 	iterator_category;
		typedef typename _Iterator::value_type 			value_type;
		typedef typename _Iterator::difference_type 	difference_type;
		typedef typename _Iterator::pointer 			pointer;
		typedef typename _Iterator::reference 			reference;
	};

	template <typename _Tp>
	struct iterator_traits< _Tp*>
	{
		typedef std::random_access_iterator_tag 		iterator_category;
		typedef _Tp 									value_type;
		typedef std::ptrdiff_t 							difference_type;
		typedef _Tp*									pointer;
		typedef _Tp&									reference;
	};

	template <typename _Tp>
	struct iterator_traits<const _Tp*>
	{
		typedef std::random_access_iterator_tag 		iterator_category;
		typedef _Tp										value_type;
		typedef std::ptrdiff_t 							difference_type;
		typedef const _Tp 								*pointer;
		typedef const _Tp 								&reference;
	};
}

#endif
