/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_RBT.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:46:37 by agouet            #+#    #+#             */
/*   Updated: 2023/01/25 18:08:58 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RBT/RBT_node.hpp"
#include "../includes/RBT/RBT.hpp"

// c++ -Wall -Wextra -Werror -fsanitize=address main_RBT.cpp

int main()
{
	ft::RBT_node<int, int> node1;
	ft::RBT_node<int, int > node2( ft::pair<int,int>(2, 3));
	
	std::cout << node1._color<< std::endl;
	std::cout << node2._pair_data.first<< std::endl;
	std::cout << node2._pair_data.second<< std::endl;
	
	ft::RBT_node<int, int> node3(node2);
	std::cout << node3._pair_data.first<< std::endl;

	ft::RBT_node<int, int> node4(0);
	std::cout << node3._parent<< std::endl;
	//-------------------------------------------------------------------------
	ft::RBT<int, int, int > rbt1;
	ft::RBT<int, int, int > rbt2(rbt1);
	std::cout<< "preOrder:?? "<<std::endl;
	rbt2.preOrderHelper(0);
	
}