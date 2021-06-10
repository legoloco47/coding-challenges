/*
    This is taken from:
        https://www.cplusplus.com/reference/map/map/


Member functions
(constructor)     Construct unordered_map (public member function )
(destructor)      Destroy unordered map (public member function)
operator=         Assign content (public member function )

Capacity
empty           Test whether container is empty (public member function)
size            Return container size (public member function)
max_siz         Return maximum size (public member function)

Iterators
begin           Return iterator to beginning (public member function)
end             Return iterator to end (public member function)
cbegin          Return const_iterator to beginning (public member function)
cend            Return const_iterator to end (public member function)

Element access
operator[]      Access element (public member function )
at              Access element (public member function)

Element lookup
find            Get iterator to element (public member function)
count           Count elements with a specific key (public member function )
equal_range     Get range of elements with specific key (public member function)

Modifiers
emplace         Construct and insert element (public member function )
emplace_hint    Construct and insert element with hint (public member function )
insert          Insert elements (public member function )
erase           Erase elements (public member function )
clear           Clear content (public member function )
swap            Swap content (public member function)

Buckets
bucket_count        Return number of buckets (public member function)
max_bucket_count    Return maximum number of buckets (public member function)
bucket_size         Return bucket size (public member type)
bucket              Locate element's bucket (public member function)

Hash policy
load_factor         Return load factor (public member function)
max_load_factor     Get or set maximum load factor (public member function )
rehash              Set number of buckets (public member function )
reserve             Request a capacity change (public member function)

Observers
hash_function       Get hash function (public member type)
key_eq              Get key equivalence predicate (public member type)
get_allocator       Get allocator (public member function)

Non-member function overloads
operators (unordered_map)    Relational operators for unordered_map (function template )
swap (unordered_map)         Exchanges contents of two unordered_map containers (function template )

*/

//https://www.cplusplus.com/reference/unordered_map/unordered_map/at/


// unordered_map::at
#include <iostream>
#include <string>
#include <unordered_map>

/*
Searches the container for elements whose key is k and returns the number of elements 
    found. Because unordered_map containers do not allow for duplicate keys, this means 
    that the function actually returns 1 if an element with that key exists in the 
    container, and zero otherwise.
*/
void countElement() {
      std::unordered_map<std::string,double> mymap = {
     {"Burger",2.99},
     {"Fries",1.99},
     {"Soda",1.50} };

    for (auto& x: {"Burger","Pizza","Salad","Soda"}) {
        if (mymap.count(x)>0)
        std::cout << "mymap has " << x << std::endl;
        else
        std::cout << "mymap has no " << x << std::endl;
    }
}
void bracket_operator(){ 
    std::unordered_map<std::string,std::string> mymap;

    mymap["Bakery"]="Barbara";  // new element inserted
    mymap["Seafood"]="Lisa";    // new element inserted
    mymap["Produce"]="John";    // new element inserted

    std::string name = mymap["Bakery"];   // existing element accessed (read)
    mymap["Seafood"] = name;              // existing element accessed (written)

    mymap["Bakery"] = mymap["Produce"];   // existing elements accessed (read/written)

    name = mymap["Deli"];      // non-existing element: new element "Deli" inserted!

    mymap["Produce"] = mymap["Gifts"];    // new element "Gifts" inserted, "Produce" written

    // iterate over the elements in the map
    for (auto& x: mymap) {
        std::cout << x.first << ": " << x.second << std::endl;
    }

}


int main ()
{
  std::unordered_map<std::string,int> mymap = {
                { "Mars", 3000},
                { "Saturn", 60000},
                { "Jupiter", 70000 } };

  mymap.at("Mars") = 3396;
  mymap.at("Saturn") += 272;
  mymap.at("Jupiter") = mymap.at("Saturn") + 9638;

  for (auto& x: mymap) {
    std::cout << x.first << ": " << x.second << std::endl;
  }

  return 0;
}
