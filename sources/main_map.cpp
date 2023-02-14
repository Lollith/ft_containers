/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:14:39 by agouet            #+#    #+#             */
/*   Updated: 2023/02/14 18:17:09 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/map.hpp" // a modif pour makefile
#include <map>

#define TEST_MAX_SIZE 0 //  a passer sur 1 pour lancer le test


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
 
	#if TEST_MAX_SIZE
 	std::cout << mymap.max_size()<< std::endl; // max_size donne cb je peux crrer d elements dans ma memoire, depend directement de la taille dun element=> depend de lorga des nodes
	#endif
	
	mymap.insert ( NAME_USE::pair<int,int>(3,100) );
	std::cout << mymap.size()<< std::endl;
	
	NAME_USE::map<int,int>::iterator  it1;
	it1 = mymap.begin();
	std::cout << it1->first << " - ";
	std::cout << it1->second << std::endl;
	mymap.insert ( NAME_USE::pair<int,int>(4,100) );
	mymap.insert ( NAME_USE::pair<int,int>(0,100) );
	std::cout << it1->first << " - ";
	std::cout << it1->second << std::endl;
	
	std::cout << mymap.find(3)->second<< std::endl;
	if (mymap.count(5)) // ne marche pas
		std::cout << "is an element of map"<< std::endl;
	else
		std::cout << "is NOT an element of map"<< std::endl;
	if (mymap.count(3)) // ne marche pas
		std::cout << "is an element of map"<< std::endl;
	else
		std::cout << "is NOT an element of map"<< std::endl;
	if (mymap.count(0)) // ne marche pas
		std::cout << "is an element of map"<< std::endl;
	else
		std::cout << "is NOT an element of map"<< std::endl;

	
	// NAME_USE::map<int,int>::iterator itlow;	
	// itlow = mymap.lower_bound(100);
	
	return 0;
	
}