/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:14:39 by agouet            #+#    #+#             */
/*   Updated: 2023/02/08 17:58:24 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/map.hpp" // a modif pour makefile
#include <map>

int main()
{
	ft::map< int, int > mymap;
	if(mymap.empty())
		std::cout << "empty"<<std::endl;
	std::cout << mymap.size()<< std::endl;
	std::cout << mymap.max_size()<< std::endl;
	
	ft::map<int, int > mymap1;
	ft::map<int,int>::iterator  it1 = mymap1.begin();
	// std::cout << it1->first << std::endl; // ne marche pas

	std::map<int, int > mymap2;
	std::map<int,int>::iterator it = mymap2.begin();
	std::cout << it->second << std::endl;
	
	return 0;
	
}