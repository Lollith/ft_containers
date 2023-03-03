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

void test_constructor_empty_size()
{
	NAME_USE::vector<int> myvector (2,200);        // vector with 2 elements

	NAME_USE::stack<int> first;  
	NAME_USE::stack<int,NAME_USE::vector<int> > fourth (myvector);       
	//   NAME_USE::stack<int> second (myvector);     

	if(first.empty())
		std::cout<< "first is empty "<< std::endl;

	if(fourth.empty())
		std::cout<< "fourth is empty "<< std::endl;
	else
		std::cout<< "fourth is not empty "<< std::endl;

	NAME_USE::stack<int,std::vector<int> > third;  // empty stack using vector

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
}

void  test_pop_push()
{
	NAME_USE::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }

  std::cout << '\n';

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

}

void test_top()
{
	NAME_USE::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

int main ()
{
  test_constructor_empty_size();
  test_pop_push();
  test_top();

  return 0;
}



