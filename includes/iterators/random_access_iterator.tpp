/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:55:03 by agouet            #+#    #+#             */
/*   Updated: 2022/12/30 18:54:47 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

namespace ft {
//---------------------------------------------constructor----------------------

template < class It >
random_access_iterator<It>::random_access_iterator(void):_current(pointer()){
	std::cout << "empty random it constructor "<< std::endl;
	return;
}

template < class It >
random_access_iterator<It>::random_access_iterator(pointer pt){
	_current = pt;
	return;
}


template< class It>
	template< class U >
random_access_iterator<It>::random_access_iterator( const random_access_iterator<U> &other){
	_current = other.base();
}

		~random_access_iterator( void ); 	

}//namesapceft