#include "stack.hpp"
#include <vector>
#include <deque>
# include <stack>
# include <list>

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

// void test_constructor_empty_size()
// {
// 	NAME_USE::vector<int> myvector (2,200);        // vector with 2 elements

// 	NAME_USE::stack<int> first;  
// 	NAME_USE::stack<int,NAME_USE::vector<int> > fourth (myvector);       
// 	//   NAME_USE::stack<int> second (myvector);     

// 	if(first.empty())
// 		std::cout<< "first is empty "<< std::endl;

// 	if(fourth.empty())
// 		std::cout<< "fourth is empty "<< std::endl;
// 	else
// 		std::cout<< "fourth is not empty "<< std::endl;

// 	NAME_USE::stack<int,std::vector<int> > third;  // empty stack using vector

// 	std::cout << "size of first: " << first.size() << '\n';
// 	std::cout << "size of third: " << third.size() << '\n';
// 	std::cout << "size of fourth: " << fourth.size() << '\n';
// }

// void  test_pop_push()
// {
// 	NAME_USE::stack<int> mystack;

//   for (int i=0; i<5; ++i) mystack.push(i);

//   std::cout << "Popping out elements...";
//   while (!mystack.empty())
//   {
//      std::cout << ' ' << mystack.top();
//      mystack.pop();
//   }

//   std::cout << '\n';

//   for (int i=0; i<5; ++i) mystack.push(i);

//   std::cout << "Popping out elements...";
//   while (!mystack.empty())
//   {
//      std::cout << ' ' << mystack.top();
//      mystack.pop();
//   }
//   std::cout << '\n';

// }

// void test_top()
// {
// 	NAME_USE::stack<int> mystack;

//   mystack.push(10);
//   mystack.push(20);

//   mystack.top() -= 5;

//   std::cout << "mystack.top() is now " << mystack.top() << '\n';
// }

// int main ()
// {
//   test_constructor_empty_size();
//   test_pop_push();
//   test_top();

//   return 0;
// }


// #define TESTED_TYPE int
// typedef std::list<TESTED_TYPE> container_type;
// #define t_stack_ NAME_USE::stack<TESTED_TYPE, container_type>


// template <class T_STACK>
// void	cmp(const T_STACK &lhs, const T_STACK &rhs)
// {
// 	static int i = 0;

// 	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
// 	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
// 	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
// 	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
// }

// int		main(void)
// {
// 	container_type	ctnr;

// 	ctnr.push_back(21);
// 	ctnr.push_back(42);
// 	ctnr.push_back(1337);
// 	ctnr.push_back(19);
// 	ctnr.push_back(0);
// 	ctnr.push_back(183792);

// 	t_stack_	stck(ctnr);
// 	t_stack_	stck2(ctnr);

// 	cmp(stck, stck);  // 0
// 	cmp(stck, stck2); // 1

// 	stck2.push(60);
// 	stck2.push(61);
// 	stck2.push(62);

// 	cmp(stck, stck2); // 2
// 	cmp(stck2, stck); // 3

// 	stck.push(42);

// 	cmp(stck, stck2); // 4
// 	cmp(stck2, stck); // 5

// 	stck.push(100);

// 	cmp(stck, stck2); // 6
// 	cmp(stck2, stck); // 7
// 	return 0;
// }


#define TESTED_TYPE int
#define t_stack_ NAME_USE::stack<TESTED_TYPE>
typedef t_stack_::container_type container_type;

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_stack_	stck(ctnr);
	t_stack_	stck2(ctnr);

	cmp(stck, stck);  // 0
	cmp(stck, stck2); // 1

	stck2.push(60);
	stck2.push(61);
	stck2.push(62);

	cmp(stck, stck2); // 2
	cmp(stck2, stck); // 3

	stck.push(42);

	cmp(stck, stck2); // 4
	cmp(stck2, stck); // 5

	stck.push(100);

	cmp(stck, stck2); // 6
	cmp(stck2, stck); // 7
	return (0);
}