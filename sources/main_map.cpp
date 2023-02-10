/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:14:39 by agouet            #+#    #+#             */
/*   Updated: 2023/02/10 16:49:46 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/map.hpp" // a modif pour makefile
#include <map>


#ifdef FT
	#include <vector.hpp>
	// #include <map.hpp>
	// #include <stack.hpp>
	namespace NAME_USE = ft;
#else
	// #include <map>
// 	// #include <stack>
	#include <vector>
	namespace NAME_USE = std;
#endif

namespace ft{
	std::string s = "ft";
}
namespace std{
	std::string s = "std";
}


int main()
{
	NAME_USE::map< int, int > mymap;
	if(mymap.empty())
		std::cout << "empty"<<std::endl;
	std::cout << mymap.size()<< std::endl;
	// std::cout << mymap.max_size()<< std::endl; // max_size donne cb je peux crrer d elements dans ma memoire, depend directement de la taille dun element=> depend de lorga des nodes
	
	
	mymap.insert ( NAME_USE::pair<int,int>(3,100) );// ne mrche pas ,
	
	// NAME_USE::map<int,int>::iterator  it1;
	// it1 = mymap.begin();
	// std::cout << it1->first << std::endl;
	// std::cout << it1->second << std::endl;
	// / insert, end , maximum a tester
	// mymap2.insert ( std::pair<int,int>(3,100) );
	// std::cout << it->second << std::endl;
	
	return 0;
	
}