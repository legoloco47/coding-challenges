/*
    This is taken from:
        https://www.cplusplus.com/reference/vector/vector/

Member functions
(constructor)	Construct set (public member function )
(destructor)	Set destructor (public member function )
operator=	    Copy container content (public member function )

Iterators:
Begin		Return iterator to beginning (public member function )
end		    Return iterator to end (public member function )
rbegin		Return reverse iterator to reverse beginning (public member function )
rend		Return reverse iterator to reverse end (public member function )
cbegin 		Return const_iterator to beginning (public member function )
cend 		Return const_iterator to end (public member function )
crbegin 	Return const_reverse_iterator to reverse beginning (public member function )
crend 		Return const_reverse_iterator to reverse end (public member function )

Capacity:
empty		Test whether container is empty (public member function )
size		Return container size (public member function )
max_size	Return maximum size (public member function )

Modifiers:
insert		    Insert element (public member function )
erase		    Erase elements (public member function )
swap		    Swap content (public member function )
clear		    Clear content (public member function )
emplace 		Construct and insert element (public member function )
emplace_hint 		Construct and insert element with hint (public member function )

Observers:
key_comp		Return comparison object (public member function )
value_comp		Return comparison object (public member function )

Operations:
find		    Get iterator to element (public member function )
count		    Count elements with a specific value (public member function )
lower_bound		Return iterator to lower bound (public member function )
upper_bound		Return iterator to upper bound (public member function )
equal_range		Get range of equal elements (public member function )

Allocator:
get_allocator		Get allocator (public member function )

*/


// assignment operator with sets
#include <iostream>
#include <set>

void clearSet() {
        std::set<int> myset;

    myset.insert (100);
    myset.insert (200);
    myset.insert (300);

    std::cout << "myset contains:";
    for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    myset.clear();
    myset.insert (1101);
    myset.insert (2202);

    std::cout << "myset contains:";
    for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    // myset contains: 100 200 300
    // myset contains: 1101 2202
}



void eraseFromSet() {
    std::set<int> myset;
    std::set<int>::iterator it;

    // insert some values:
    for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

    it = myset.begin();
    ++it;                                         // "it" points now to 20

    myset.erase (it);

    myset.erase (40);

    it = myset.find (60);
    myset.erase (it, myset.end());

    std::cout << "myset contains:";
    for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    // myset contains: 10 30 50

}


void insertIntoSet(){
    std::set<int> myset;
    std::set<int>::iterator it;
    std::pair<std::set<int>::iterator,bool> ret;

    // set some initial values:
    for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

    ret = myset.insert(20);               // no new element inserted

    if (ret.second==false) it=ret.first;  // "it" now points to element 20

    myset.insert (it,25);                 // max efficiency inserting
    myset.insert (it,24);                 // max efficiency inserting
    myset.insert (it,26);                 // no max efficiency inserting

    int myints[]= {5,10,15};              // 10 already in set, not inserted
    myset.insert (myints,myints+3);

    std::cout << "myset contains:";

    for (it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;

    std::cout << '\n';
    // myset contains: 5 10 15 20 24 25 26 30 40 50
}


int main ()
{
  int myints[]={ 12,82,37,64,15 };
  std::set<int> first (myints,myints+5);   // set with 5 ints
  std::set<int> second;                    // empty set

  second = first;                          // now second contains the 5 ints
  first = std::set<int>();                 // and first is empty

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  /*
    Output:
    Size of first: 0
    Size of second: 5
*/

  return 0;
}

