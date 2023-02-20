/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:14:39 by agouet            #+#    #+#             */
/*   Updated: 2023/02/20 16:24:26 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "map.hpp" // a modif pour makefile
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
	mymap.insert ( NAME_USE::pair<int,int>(8,5) );
	mymap.insert ( NAME_USE::pair<int,int>(5,20) );
	std::cout << mymap.size()<< std::endl;
	NAME_USE::map<int,int>::iterator  it1;
	NAME_USE::map<int,int>::iterator  itend;
	
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

	
	
}

// void test_insert()
// {
// 	NAME_USE::map< int, int > mymap;
// 	NAME_USE::map<int,int>::iterator  it1;
// 	NAME_USE::map<int,int>::iterator  itend;
	
// 	mymap.insert ( NAME_USE::pair<int,int>(4,100) );
// 	mymap.insert ( NAME_USE::pair<int,int>(0,100) );
// 	mymap.insert ( NAME_USE::pair<int,int>(10,10) );
// 	it1 = mymap.begin();
// 	itend = mymap.end();
// 	std::cout << "INSERT " << std::endl;	
// 	std::cout << "begin "<<it1->first << " - ";
// 	std::cout << it1->second << std::endl;
// 	std::cout << "end "<<itend->first << " - ";
// 	std::cout << itend->second << std::endl;
// 	std::cout << mymap[4] << std::endl;
// 	std::cout << mymap[0] << std::endl;
// 	std::cout << mymap[10] << std::endl;

// // third insert function version (range insertion):
//  	NAME_USE::map<char,int> mymap1;
// 	NAME_USE::map<char,int>::iterator it = mymap1.begin();
// 	NAME_USE::map<char,int> anothermap;
//   	anothermap.insert(mymap1.begin(),mymap1.find('c'));

// 	std::cout << "mymap contains:\n";
// 	for (it=mymap1.begin(); it!=mymap1.end(); ++it)
//  	std::cout << it->first << " => " << it->second << '\n';

//   	std::cout << "anothermap contains:\n";
//   	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
// }

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

// void test_swap()
// {
// 	NAME_USE::map<char,int> foo,bar;

//   foo['x']=100;
//   foo['y']=200;

//   bar['a']=11;
//   bar['b']=22;
//   bar['c']=33;

//   foo.swap(bar);

//   std::cout << "foo contains:\n";
//   for (NAME_USE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "bar contains:\n";
//   for (NAME_USE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
// }

// void test_equal()
// {
//   NAME_USE::map<char,int> mymap;

//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;

//   NAME_USE::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
//   ret = mymap.equal_range('b');

//   std::cout << "lower bound points to: ";
//   std::cout << ret.first->first << " => " << ret.first->second << '\n';

//   std::cout << "upper bound points to: ";
//   std::cout << ret.second->first << " => " << ret.second->second << '\n';

// }


int main()
{ // OK
	// test_capacity();
	test_begin_end();
	// test_access();
	// test_find();
	// test_bound();




	// ne marche pas
	// test_value_comp();    // 1.debugger rbegin deja <<===================
 							//2. rbegin avec un delete	
	//ne compile pas
	// test_swap();
	// test_equal();	
	// test_insert();
	
	
	
// a tester  + finir avant : constructors	
// manque 1 insert
//3 erases
	return 0;
	
}