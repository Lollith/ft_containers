/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:14:39 by agouet            #+#    #+#             */
/*   Updated: 2023/02/09 17:38:56 by agouet           ###   ########.fr       */
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
	std::cout << mymap.max_size()<< std::endl;
	// mymap.insert ( ft::pair<int,int>(3,100) ); ne mrche pas ,
	// / insert, end , maximum a tester
	
	// ft::map<const int, int > mymap1;
	// ft::map<int,int>::iterator  it1 = mymap1.begin();
	// std::cout << it1->first << std::endl; // ne marche pas

	// std::map<int, int > mymap2;
	// std::map<int,int>::iterator it = mymap2.begin();
	// std::cout << it->second << std::endl;
	// mymap2.insert ( std::pair<int,int>(3,100) );
	// std::cout << it->second << std::endl;
	
	return 0;
	
}