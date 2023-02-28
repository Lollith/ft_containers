/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:14:39 by agouet            #+#    #+#             */
/*   Updated: 2023/02/27 17:51:54 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "map.hpp" // a modif pour makefile
# include <map>
#include <string>
#include<stdlib.h>
#include<iostream>
#include <list>

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


// void test_constructor()
// {
	
// }
void test_capacity()
{
	NAME_USE::map< int, int > mymap;
	if(mymap.empty())
		std::cout << "empty"<<std::endl;
	std::cout <<"size "<< mymap.size()<< std::endl;
 
	#if TEST_MAX_SIZE
 	std::cout << mymap.max_size()<< std::endl; // max_size donne cb je peux crrer d elements dans ma memoire, depend directement de la taille dun element=> depend de lorga des nodes
	#endif
}

void test_access(void)
{
	NAME_USE::map< int, int > mymap;
	mymap[1] = 5;
	mymap[4] = 8;
	std::cout << mymap[1] << std::endl;
	std::cout << mymap[4] << std::endl;
	std::cout << mymap[0] << std::endl;
	std::cout <<"size "<< mymap.size()<< std::endl;
	mymap[4] = 8;
	std::cout <<"size "<< mymap.size()<< std::endl;
	mymap.at( 4 ) = 8;
	std::cout << mymap.at(4) << std::endl;
	try
	{
		NAME_USE::map<int, int> mymap;
		mymap.at(1) = 2;
	}
	catch(std::out_of_range const &e)
	{
		std::cerr<< "ERREUR: "<<e.what() <<std::endl;
	}
}

void test_begin_end ()
{
	NAME_USE::map< int, int > mymap;
	mymap.insert ( NAME_USE::pair<int,int>(10,100) );
	mymap.insert ( NAME_USE::pair<int,int>(3,5) );
	mymap.insert ( NAME_USE::pair<int,int>(5,20) );
	std::cout << mymap.size()<< std::endl;
	NAME_USE::map<int,int>::iterator  it1;
	NAME_USE::map<int,int>::iterator  itend;
	NAME_USE::map<int,int>::reverse_iterator  itr2;
	
	it1 = mymap.begin();
	std::cout << "begin "<<it1->first << " - ";
	std::cout << it1->second << std::endl;
	
	itend = mymap.end();
	std::cout << "end "<<itend->first << " - ";
	std::cout << itend->second << std::endl;

	NAME_USE::map<int,int>::reverse_iterator  itr;
	itr = mymap.rbegin();
	std::cout << "rbegin "<<itr->first << " - ";
	std::cout << itr->second << std::endl;

	
	itr2 = mymap.rend();
	std::cout << "rend "<<itr2->first << " - ";
	std::cout << itr2->second << std::endl;
	
}

void test_insert()
{
	NAME_USE::map< int, int > mymap;
	NAME_USE::map<int,int>::iterator  it1;
	NAME_USE::map<int,int>::iterator  itend;
	
	mymap.insert ( NAME_USE::pair<int,int>(4,100) );
	mymap.insert ( NAME_USE::pair<int,int>(0,100) );
	mymap.insert ( NAME_USE::pair<int,int>(10,10) );
	it1 = mymap.begin();
	itend = mymap.end();
	std::cout << "INSERT " << std::endl;	
	std::cout << "begin "<<it1->first << " - ";
	std::cout << it1->second << std::endl;
	std::cout << "end "<<itend->first << " - ";
	std::cout << itend->second << std::endl;
	std::cout << mymap[4] << std::endl;
	std::cout << mymap[0] << std::endl;
	std::cout << mymap[10] << std::endl;

 	NAME_USE::map<char,int> mymap1;
// second insert function version (with hint position):
  NAME_USE::map<char,int>::iterator it;
  it = mymap1.begin();
  mymap1.insert (it, NAME_USE::pair<char,int>('b',300));  // max efficiency inserting
  mymap1.insert (it, NAME_USE::pair<char,int>('c',400));  // no max efficiency inserting

	NAME_USE::map<char,int> anothermap;
  	anothermap.insert(mymap1.begin(),mymap1.find('c'));

	std::cout << "mymap contains:\n";
	for (it=mymap1.begin(); it!=mymap1.end(); ++it)
 	std::cout << it->first << " => " << it->second << '\n';

  	std::cout << "anothermap contains:\n";
  	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';



}

void test_find()
{
	NAME_USE::map< int, int > mymap;
	mymap.insert ( NAME_USE::pair<int,int>(4,100) );
	mymap.insert ( NAME_USE::pair<int,int>(0,100) );
	mymap.insert ( NAME_USE::pair<int,int>(10,10) );

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
}

void test_bound()
{
	 NAME_USE::map<int,int>::iterator itlow;	
	NAME_USE::map< int, int > mymap12;
	mymap12.insert ( NAME_USE::pair<int,int>(3,100) );
	mymap12.insert ( NAME_USE::pair<int,int>(9,10) );

	itlow = mymap12.begin();
	std::cout << "begin "<< itlow->first << " - ";
	std::cout << itlow->second << std::endl;
	
	itlow = mymap12.end();
	std::cout <<"end "<< itlow->first << " - ";
	std::cout << itlow->second << std::endl;
	
	std::cout << "LOWER" << std::endl;	
	itlow = mymap12.lower_bound(10);
	std::cout << itlow->first << " - ";
	std::cout << itlow->second << std::endl;
	itlow = mymap12.lower_bound(3);
	std::cout << itlow->first << " - ";
	std::cout << itlow->second << std::endl;
	itlow = mymap12.lower_bound(4);
	std::cout << itlow->first << " - ";
	std::cout << itlow->second << std::endl;

	std::cout << "UPPER" << std::endl;	
	itlow = mymap12.upper_bound(10);
	std::cout << itlow->first << " - ";
	std::cout << itlow->second << std::endl;
	itlow = mymap12.upper_bound(3);
	std::cout << itlow->first << " - ";
	std::cout << itlow->second << std::endl;
	itlow = mymap12.upper_bound(4);
	std::cout << itlow->first << " - ";
	std::cout << itlow->second << std::endl;
	itlow = mymap12.upper_bound(0);
	std::cout << itlow->first << " - ";
	std::cout << itlow->second << std::endl;

}


void test_value_comp()
{
	NAME_USE::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  NAME_USE::pair<char,int> highest = *mymap.rbegin();          // last element

  NAME_USE::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } 
  while ( mymap.value_comp()(*it++, highest) );
}

void test_swap()
{
	NAME_USE::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (NAME_USE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (NAME_USE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void test_equal()
{
  NAME_USE::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  NAME_USE::pair<NAME_USE::map<char,int>::iterator,NAME_USE::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

}

void test_erase()
{
	NAME_USE::map<char,int> mymap;
  	NAME_USE::map<char,int>::iterator it;
  	NAME_USE::map<char,int>::reverse_iterator itr;
  	NAME_USE::map<char,int>::reverse_iterator itr2;

//   insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator

	mymap.erase ('c');                  // erasing by key

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end() );    // erasing by range

//   show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout <<"size "<< mymap.size()<< std::endl;
	
	itr = mymap.rbegin();
	std::cout << "rbegin "<<itr->first << " - ";
	std::cout << itr->second << std::endl;

	itr2 = mymap.rend();
	std::cout << "rend "<<itr2->first << " - ";
	std::cout << itr2->second << std::endl;
}

void	test_constructor()
{
	NAME_USE::map<char,int> mymap;
	NAME_USE::map<char,int>::iterator it = mymap.begin();
	std::cout << it->first << " => " << it->second << '\n';
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

		// (4) Range constructor
		NAME_USE::map<char, int> map2(mymap.begin(), mymap.end());
	for (it=map2.begin(); it!=map2.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	NAME_USE::map<char,int> mymap1 (mymap);
	for (it=mymap1.begin(); it!=mymap1.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

void test_string()
{
	NAME_USE::map<std::string,int> mymap;
	mymap["ade"]=10;
	NAME_USE::map<std::string,int>::iterator it = mymap.begin();
	std::cout << it->first << " => " << it->second << '\n';

	NAME_USE::map<std::string, int> map2(mymap.begin(), mymap.end());
	for (it=map2.begin(); it!=map2.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	
	NAME_USE::map<std::string,int> mymap1 (mymap);
	for (it=mymap1.begin(); it!=mymap1.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

// int main()
// { 
// 	// test_constructor();
// 	// test_capacity();
// 	// test_begin_end();
// 	// test_access();
// 	// test_find();
// 	// test_bound();
// 	// test_value_comp();  
// 	// test_swap();
// 	// test_equal();	
// 	// test_insert();
// 	// test_erase();
// test_string();

// 	NAME_USE::map<std::string,int> mymap;
// 	mymap["1234567890123456"]=10;
// 	NAME_USE::map<std::string,int>::iterator it = mymap.begin();
// 	std::cout << it->first << " => " << it->second << '\n';

// return 0;	
// }

//----------------------------------------------------------------------------------
template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}


template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}
//------------------------------------------------------------------------------



// #define T1 int
// #define T2 std::string
// typedef NAME_USE::map<T1, T2>::value_type T3;
// typedef NAME_USE::map<T1, T2>::iterator iterator;

// static int iter = 0;

// template <typename MAP, typename U>
// void	ft_insert(MAP &mp, U param)
// {
// 	NAME_USE::pair<iterator, bool> tmp;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	tmp = mp.insert(param);
// 	std::cout << "insert return: " << printPair(tmp.first);
// 	std::cout << "Created new node: " << tmp.second << std::endl;
// 	printSize(mp);
// }

// template <typename MAP, typename U, typename V>
// void	ft_insert(MAP &mp, U param, V param2)
// {
// 	iterator tmp;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	tmp = mp.insert(param, param2);
// 	std::cout << "insert return: " << printPair(tmp);
// 	printSize(mp);
// }

// int		main(void)
// {
// 	NAME_USE::map<T1, T2> mp, mp2;

// 	ft_insert(mp, T3(42, "lol"));
// 	ft_insert(mp, T3(42, "mdr"));

// 	ft_insert(mp, T3(50, "mdr"));
// 	ft_insert(mp, T3(35, "funny"));

// 	ft_insert(mp, T3(45, "bunny"));
// 	ft_insert(mp, T3(21, "fizz"));
// 	ft_insert(mp, T3(38, "buzz"));

// 	ft_insert(mp, mp.begin(), T3(55, "fuzzy"));

// 	ft_insert(mp2, mp2.begin(), T3(1337, "beauty"));
// 	ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
// 	ft_insert(mp2, mp2.end(), T3(1500, "World"));

// 	return (0);
// }


//=-----------------------------------------------------------------------------
// #define T1 int
// #define T2 std::string
// typedef NAME_USE::map<T1, T2>::value_type T3;

// static int iter = 0;

// template <typename MAP, typename U>
// void	ft_insert(MAP &mp, U param, U param2)
// {
// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	mp.insert(param, param2);
// 	printSize(mp);
// }

// int		main(void)
// {
// 	std::list<T3> lst;
// 	std::list<T3>::iterator itlst;

// 	lst.push_back(T3(42, "lol"));

// 	lst.push_back(T3(50, "mdr"));
// 	lst.push_back(T3(35, "funny"));

// 	lst.push_back(T3(45, "bunny"));
// 	lst.push_back(T3(21, "fizz"));
// 	lst.push_back(T3(38, "buzz"));
// 	lst.push_back(T3(55, "fuzzy"));

// 	std::cout << "List contains:" << std::endl;
// 	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
// 		printPair(itlst);

// 	NAME_USE::map<T1, T2> mp;
// 	ft_insert(mp, lst.begin(), lst.end());

// 	lst.clear();

// 	lst.push_back(T3(87, "hey"));
// 	lst.push_back(T3(47, "eqweqweq"));
// 	lst.push_back(T3(35, "this key is already inside"));
// 	lst.push_back(T3(23, "but not that one"));
// 	lst.push_back(T3(1, "123456789012345"));//pas de leak
// 	lst.push_back(T3(1, "1234567890123456"));//leak
// 	lst.push_back(T3(1, "surprising isnt it?"));
// 	lst.push_back(T3(100, "is it enough??"));
// 	lst.push_back(T3(55, "inside map too"));

// 	std::cout << "List contains:" << std::endl;
// 	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
// 		printPair(itlst);

// 	ft_insert(mp, lst.begin(), lst.begin());
// 	ft_insert(mp, lst.begin(), lst.end());

// 	return (0);
// }


//------------------------------------------------------------------------------
#define T1 int
#define T2 std::string

struct ft_more {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};

typedef NAME_USE::map<T1, T2, ft_more> ft_mp;
// typedef NAME_USE::map<T1, T2, ft_more>::iterator ft_mp_it;

int		main(void)
{
	ft_mp mp;

	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printSize(mp);

	return (0);
}

// a faire 
insert_node_it ne sert  a rien => insert_node
debug compare