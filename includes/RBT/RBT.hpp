/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:48 by agouet            #+#    #+#             */
/*   Updated: 2023/01/20 17:48:46 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

namespace ft{

	template< >
	class RBT
	{
		public:
			typedef typename ft::RBT_node<T , Allocator>	node; // creer mon type node dapres mon RBT_node <vaalue,alloc>
			
		//constructor
		RBT();
		~RBT();

			
			
	}	




	
}//ft

#endif