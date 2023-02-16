/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_RBT.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:46:37 by agouet            #+#    #+#             */
/*   Updated: 2023/02/16 15:40:16 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RBT/RBT_node.hpp"
#include "../includes/RBT/RBT.hpp"
# include "../includes/iterators/RBT_iterator.hpp"

// c++ -Wall -Wextra -Werror -fsanitize=address main_RBT.cpp

int main()
{
	ft::RBT_node<int, int> node1;
	ft::RBT_node<int, int > node2( ft::pair<int,int>(2, 3));
	
	std::cout << "node1_color: "<< node1._color<< std::endl;
	std::cout << "node2_data_first: " << node2._pair_data.first<< std::endl;
	std::cout << "node2_data_second: "<< node2._pair_data.second<< std::endl;
	
	ft::RBT_node<int, int> node3(node2);
	std::cout << "copie de node2: "<<node3._pair_data.first<< std::endl;

	// ft::RBT_node<int, int> node4(0);
	// std::cout << "surcharge node4: "<< node4._parent<< std::endl;
	//-------------------------------------------------------------------------
	std::cout << std::endl;
	ft::RBT<int, int, int > rbt1;
	// std::cout<< "tree display: "<<std::endl;
	rbt1.insert_node(ft::pair< int, int>(9,3));
	rbt1.insert_node(ft::pair< int, int>(4,3));
	rbt1.insert_node(ft::pair< int, int>(1,3));
	rbt1.insert_node(ft::pair< int, int>(5,3));
	rbt1.insert_node(ft::pair< int, int>(8,3));
	// ft::RBT<int, int, int > rbt2(rbt1);
	rbt1.display();
	// rbt1.delete_node(2);
	// rbt1.delete_node(3);
	// rbt1.display();
	// std::cout << std::endl;
	// rbt2.display();
	
	// //-------------------------------------------------------------------------
	
	std::cout <<"---------- iterators------------" <<std::endl;
	ft::RBT_iterator<int,int> it;
	std::cout << it.base() << std::endl;

	ft::RBT<int, int, int > rbt_vide;
	ft::RBT<int, int, int>::iterator it1;
	it1 = rbt_vide.begin();
	if (it1.base() != NULL)
	{
		std::cout << it1.base()->_pair_data.first << " - ";
		std::cout << it1.base()->_pair_data.second << std::endl;
	}
	else
		std::cout << "Null" << std::endl;
	
	ft::RBT<int, int, int>::iterator it2;
	it2 = rbt1.begin();
	std::cout << it2._current->_pair_data.first << " - ";
	std::cout << it2.base()->_pair_data.second << std::endl;
	std::cout << "-> " <<it2->first << std::endl;
	
	ft::RBT<int, int, int>::iterator it3;
	it3 = rbt1.begin() + 1;
	std::cout << it3.base()->_pair_data.first << " - ";
	std::cout << it3.base()->_pair_data.second << std::endl;
	it3 = rbt1.begin() + 2;
	std::cout << it3.base()->_pair_data.first << " - ";
	std::cout << it3.base()->_pair_data.second << std::endl;

	ft::RBT<int, int, int>::iterator it4;
	it4 = rbt1.end();
	std::cout << it4.base()->_pair_data.first << " - ";
	std::cout << it4.base()->_pair_data.second << std::endl;
	it4--;	
	std::cout << it4.base()->_pair_data.first << " - ";
	std::cout << it4.base()->_pair_data.second << std::endl;

	it4--;	
	std::cout << it4.base()->_pair_data.first << " - ";
	std::cout << it4.base()->_pair_data.second << std::endl;
	



	ft::RBT<int, int >::iterator itlow;
	ft::RBT<int, int> rbt12;
	rbt12.insert_node(ft::pair< int, int>(9,3));
	rbt12.insert_node(ft::pair< int, int>(4,3));
	itlow = rbt12.lower_bound(100);
	
	return 0;
	
}