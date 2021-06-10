/*
    This is taken from:
        https://www.cplusplus.com/reference/vector/vector/


Member functions
(constructor)   Construct vector (public member function )
(destructor)    Vector destructor (public member function )
operator=       Assign content (public member function )

Iterators:
begin       Return iterator to beginning (public member function )
end         Return iterator to end (public member function )
rbegin      Return reverse iterator to reverse beginning (public member function )
rend        Return reverse iterator to reverse end (public member function )
cbegin      Return const_iterator to beginning (public member function )
cend        Return const_iterator to end (public member function )
crbegin     Return const_reverse_iterator to reverse beginning (public member function )
crend       Return const_reverse_iterator to reverse end (public member function )

Capacity:
size        Return size (public member function )
max_size    Return maximum size (public member function )
resize      Change size (public member function )
capacity    Return size of allocated storage capacity (public member function )
empty       Test whether vector is empty (public member function )
reserve     Request a change in capacity (public member function )
shrink_to_fit   Shrink to fit (public member function )

Element access:
operator[]      Access element (public member function )
at              Access element (public member function )
front           Access first element (public member function )
back            Access last element (public member function )
data            Access data (public member function )

Modifiers:
assign          Assign vector content (public member function )
push_back       Add element at the end (public member function )
pop_back        Delete last element (public member function )
insert          Insert elements (public member function )
erase           Erase elements (public member function )
swap            Swap content (public member function )
clear           Clear content (public member function )
emplace         Construct and insert element (public member function )
emplace_back    Construct and insert element at the end (public member function )

Allocator:
get_allocator       Get allocator (public member function )

Non-member function overloads
relational operators        Relational operators for vector (function template )
swap                        Exchange contents of vectors (function template )

Template specializations
vector<bool>        Vector of bool (class template specialization )

*/



// vector::operator[]
#include <iostream>
#include <vector>

void insertOperator(){
    std::vector<int> myvector (3,100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );

    myvector.insert (it,2,300);

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::vector<int> anothervector (2,400);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());

    int myarray [] = { 501,502,503 };
    myvector.insert (myvector.begin(), myarray, myarray+3);

    std::cout << "myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
    //myvector contains: 501 502 503 300 300 400 400 200 100 100 100

}

void atOperator() {
    std::vector<int> myvector (10);   // 10 zero-initialized ints

    // assign some values:
    for (unsigned i=0; i<myvector.size(); i++)
        myvector.at(i)=i;

    std::cout << "myvector contains:";
    for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector.at(i);
    std::cout << '\n';
    // myvector contains: 0 1 2 3 4 5 6 7 8 9

}


int main ()
{
  std::vector<int> myvector (10);   // 10 zero-initialized elements

  std::vector<int>::size_type sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}