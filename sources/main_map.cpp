/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:14:39 by agouet            #+#    #+#             */
/*   Updated: 2023/02/02 17:05:44 by agouet           ###   ########.fr       */
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
	
	return 0;
	
}