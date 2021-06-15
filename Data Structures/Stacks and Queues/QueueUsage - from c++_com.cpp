/*
QUEUEU
FIFO-- first in first out (line of people)

Ues:
- anytime scheduling based on 1st come 1st serve
    -CPU scheduling, disk scheduling, buffers, pipes
- Used for BFS

Insert O(1)
Delete O(1)
Access worst case O(n) 






*/
/*

    This is taken from:
        https://www.cplusplus.com/reference/queue/

Classes
    queue           FIFO queue (class template )
    priority_queue  Priority queue (class template )

FIFO queue
queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out), 
where elements are inserted into one end of the container and extracted from the other.

queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container
 class as its underlying container, providing a specific set of member functions to access its elements. Elements are 
 pushed into the "back" of the specific container and popped from its "front".

The underlying container may be one of the standard container class template or some other specifically designed container
 class. This underlying container shall support at least the following operations:
    empty
    size
    front
    back
    push_back
    pop_front

The standard container classes deque and list fulfill these requirements. By default, if no container class is specified for a particular queue class instantiation, the standard container deque is used.


Member functions
    (constructor)		Construct queue (public member function )
    empty		Test whether container is empty (public member function )
    size		Return size (public member function )
    front		Access next element (public member function )
    back		Access last element (public member function )
    push		Insert element (public member function )
    emplace 	Construct and insert element (public member function )
    pop		    Remove next element (public member function )
    swap 		Swap contents (public member function )

Non-member function overloads
relational operators	Relational operators for queue (function )
swap (queue) 		    Exchange contents of queues (public member function )

Non-member class specializations
uses_allocator<queue> 	Uses allocator for queue (class template )

*/


// queue::empty
#include <iostream>       // std::cout
#include <queue>          // std::queue
using namespace std;

int main ()
{
    std::queue<int> myqueue;
    int sum (0);

    for (int i=1;i<=10;i++) myqueue.push(i);

    while (!myqueue.empty())
    {
        sum += myqueue.front();
        myqueue.pop();
    }

    std::cout << "total: " << sum << '\n';
    // total: 55

    return 0;
}
