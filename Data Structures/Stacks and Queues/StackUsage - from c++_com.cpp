/*
    This is taken from:
        https://www.cplusplus.com/reference/queue/

LIFO stack
Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), 
    where elements are inserted and extracted only from one end of the container.

stacks are implemented as container adaptors, which are classes that use an encapsulated object of a specific 
    container class as its underlying container, providing a specific set of member functions to access its elements.
     Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.

The underlying container may be any of the standard container class templates or some other specifically designed 
    container class. The container shall support the following operations:
    empty
    size
    back
    push_back
    pop_back


Member functions
(constructor)		Construct stack (public member function )
Empty	    Test whether container is empty (public member function )
size		Return size (public member function )
top		    Access next element (public member function )
push		Insert element (public member function )
emplace 	Construct and insert element (public member function )
pop		    Remove top element (public member function )
swap 		Swap contents (public member function )

Non-member function overloads
relational operators	Relational operators for stack (function )
swap (stack) 		    Exchange contents of stacks (public member function )

Non-member class specializations
uses_allocator<stack> 	Uses allocator for stack (class template )


*/

// stack::top
#include <iostream>       // std::cout
#include <stack>          // std::stack
using namespace std;



void popOperator() {
    std::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << '\n';
    //Popping out elements... 4 3 2 1 0
}

int main ()
{
  std::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';
    //mystack.top() is now 15

  return 0;
}