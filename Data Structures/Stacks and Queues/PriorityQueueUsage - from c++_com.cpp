/*
    This is taken from:
        https://www.cplusplus.com/reference/queue/

Classes
    queue           FIFO queue (class template )
    priority_queue  Priority queue (class template )

Priority queue
Priority queues are a type of container adaptors, specifically designed such that its first element 
    is always the greatest of the elements it contains, according to some strict weak ordering criterion.

This context is similar to a heap, where elements can be inserted at any moment, and only the max  
    heap element can be retrieved (the one at the top in the priority queue).

Priority queues are implemented as container adaptors, which are classes that use an encapsulated object
     of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are popped from the "back" of the specific container, which is known as the top of the priority queue.

The underlying container may be any of the standard container class templates or some other specifically
     designed container class. The container shall be accessible through random access iterators and support the following operations:
    empty()
    size()
    front()
    push_back()
    pop_back()



Member functions
    (constructor)	Construct priority queue (public member function )
    empty		Test whether container is empty (public member function )
    size		Return size (public member function )
    top	        Access top element (public member function )
    push		Insert element (public member function )
    emplace 	Construct and insert element (public member function )
    pop		    Remove top element (public member function )
    swap 		Swap contents (public member function )

Non-member function overloads
    swap (queue) 		Exchange contents of priority queues (public member function )

Non-member class specializations
    uses_allocator<queue> 		Uses allocator for priority queue (class template )



*/


// priority_queue::top
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue

using namespace std;


void createMinQueue() {
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    // Creates a min heap
    priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);
 
    // One by one extract items from min heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }


}

void popOperator() {
    std::priority_queue<int> mypq;

    mypq.push(30);
    mypq.push(100);
    mypq.push(25);
    mypq.push(40);

    int sum (0);

    std::cout<<"Queue size: "<<mypq.size()<<'\n';
    std::cout << "Popping out elements...";
    while (!mypq.empty())
    {
        std::cout << ' ' << mypq.top();
        sum += mypq.top();
        mypq.pop();
    }
    std::cout << 'Sum: '<<sum<<'\n';
    // Size: 4
    // Popping out elements... 100 40 30 25
    // Sum: 195
}


int main ()
{
    std::priority_queue<int> mypq;

    mypq.push(10);
    mypq.push(20);
    mypq.push(15);

    std::cout << "mypq.top() is now " << mypq.top() << '\n';
    // mypq.top() is now 20

    return 0;
}