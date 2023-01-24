/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_RBT.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:46:37 by agouet            #+#    #+#             */
/*   Updated: 2023/01/24 16:34:20 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RBT/RBT_node.hpp"

// c++ -Wall -Wextra -Werror -fsanitize=address main_RBT.cpp

int main()
{
	ft::RBT_node<int , int> node1;
	ft::RBT_node<int, int > node2( ft::pair<int,int>(2, 3));
	
	// node1 = node2;
	// std::cout << node1._color<< std::endl;
	
}