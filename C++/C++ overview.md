##### Author: Helen Edelson

# Public vs private vs protected
* Public—members of class A are accessible for all and everyone
* Protected—members of class A are not accessible outside of A’s code. But it is accessible from the code of any class derviced from A
* Private—memebrs of a ckass A are not accessible outside of A’s code or from the code of any class derviced from A

### Choosing between protected or private?
* How much trust do you have in the programmer of the derived class?
* By default assume derviced classes cannot be trusted -> use private

Protected—child classes can access the inherited protected data members of base class
```
class Parent {
     protected: 
	     int id_protected;
};

class Child: public Parent {
public:
void setID(int id){
	id_protected = id;
}
void displayID() {
	cout<<”ID is <<id_protected<<endl;
}
}

int main() {
	Child obj1;
	Obj1.setID(81);
	Obj1.displayID();
}

class Circle {
private: double radius;
public:
    double computeArea(double r){
    radius = r;
    return radius*3.14* radius;
    }
};
int main() {
	Circle obj1;
	Obj1.computeArea(2);
}
```

```
class Circle {
private: double radius;
public:
    double computeArea(double r){
        radius = r;
        return radius*3.14* radius;
    }
};
```

# Virtual Function, Abstract Class
Virtual function—redefined in derived (child) classes
* Only have to elcare it (assign 0 in declaration)
## Virtual function
* Used to achieve runtime polymorphism
* resolving of functions is done at runtime
* they ensure correct function is called for an okect regardless of the type of reference (or pointer) used for function casll
* cannot be static type
## Abstract Class
* have at least one pure virual function
* if implementation of all functions cannot be provided in a base class because we don’t know the implementation
*Ex: shape is a base class. We cannot provide implementation of function Draw() in shape, but we know every derviced class must have implementation of draw()
*Cannot create objects of abstract classes
*has at least one pure virtual function


```
#include <iosream>
using namespace std;

//base class. Will provide interface framework 
class Shape {
    protected: int width, height;
    public:
    virtual int getArea() = 0;	//pure virtual function
    void setWidth(int w){width = w;}
    void setHeight(int h){height = h;}
};
class Rectangle : public Shape {
    public: int getArea() {return width*height; }
};
class Triangle : public Shape {
    public: int getArea() {return ½*width*height; }
};
int main(){
    Rectangle rect;
    Triangle tri;
    rect.setWidth(5);
    rect.setHeight(7);
    rect.getArea();
}
```


# C++ arrays
```
type name[size];

Arrays consist of contiguous memory
ind[0] = lowest address
ind[n] = highest address
```

## inits
```
int bal[5] = {1000, 2, 3, 17, 50};
int bal[] = {1000, 2, 3, 17, 50};
```

## Reset array:
```
/* For automatically allocated arrays */
memset(myArr, 0 , sizeof(myArr));

/* For heap-allocated arrays, N = # elements */
memset(myArr, 0, N*sizeof(*myArr));
```

## Multi Dimensional array:
```
type name[n1][n2]...[nn]       
int a[3][4] = {{0,1,2,3},      
				{4,5,6,7},      
				{8,9,10, 11}}; 
                                     
```
or 
```
int b[3][4] = {0,1,23,4,5,6,7,8,9,10,11};           
int c[5][2] = {{0,0}, {1,2}, {2,4}, {3,6}, {4,8}};  
```
Pointer to Array
* an array name is a constant pointer to the 1st element of the array
```
/* balance is a pointer to &balance[0] */
int bal[5] = {1000, 2, 3, 17, 50};
int *p;
p = balance;

//legal
*p = *(p+0) = balance[0] = 1000;
	 *(p+1) = balance[1] = 2;
	 *(p+2) = balance[2] = 3;
	 *(p+3) = balance[3] = 17;
	 *(p+4) = balance[4] = 50;
```

## Passing Arrays to Functions
* C++ cannot pass entire array to a function as an argument 
* Can pass a pointer to an array (just array name)

```
void methodA(int * arr) {...}           // pass as a pointer
void methodB(int arr[10]) {...}         // Pass as a sized array
void methodC(int arr[], int size) {...} // pass as unsized array
```

## Returning Arrays from Functions
* C++ cannot return entire array from function --> return pointer
* Note: C++ does not advocate returning the address of a local variable to outside of the function so you must declare it as static

```
#include <iostream>
#include <ctime>
using namespace std;

int *getRand() {
    static int r[10];
    srand((unsigned)time(NULL)); // Seed set

    for (int i = 0; i < 10; i++) {
        r[i] = rand();
        cout<<r[i]<<endl;
    }
    return r;
}

int main() {
    int *p;
    p = getRandom();
    for (int i = 0; i < 10; i++) {
        cout<< *(p+i) <<endl;
    }
    return 0;
}
```

# C++ Strings
* 2 Types of strings in C++
  * C style character strings
  * Standard C++ string class type

## C Style Character Strings
* 1D array of chars ending in '\0'
* null terminated strings contain characters of string followed by null
* size of char array containing the string is 1+ string length

```
                  1    2    3    4    5     6
char greet[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```
or 
```
char greet = "Hello";
```

```
                 0  1  2  3  4  5
Both strings:   [H][e][l][l][o][\0];
```

## C++ functions on NULL-terminated strings
(char arrays)

```
#include <cstring>
strcpy(s1, s2); // Copy s2 into s1
strcat(s1, s2); // concat s2 onto s1
strlen(s1)      // length s1
strcmp(s1, s2); // compare s1 to s2, 0 if s1==s2
                                    <0 if s1 < s2
                                    >0 if s1 > s2
strchr(s1, ch); // Returns pointer to 1st occurance of ch in s1
strstr(s1, s2); // Returns pointer to 1st occurnace of s2 in s1

char st1[10] = "Hello";
char st2[10] = "World";
char st3[10];

strcpy(s3, s1);     // Hello
strcat(st1, st2);   // HelloWorld
strlen(st2);        // World --> 5
```
```
#include <string>
string st1 = "Hello";
string st2 = "World";
string st3;

st3 = st1 + st2;    // HelloWorld
st3.size();         // 10
```

# C++ Pointers
* Dynamic memory allocation
* Every variable is a memory location
* Every memory location has an address that can be retrieved via '&' operator
## **Pointer** 
* Variable whose value is the address of another variable
* Type * varname;
  * Actual type is hex value
  * Access the value at the address of the pointer via *ptr

Assign NULL to ptr not used
```
int *ip = NULL;         // *ip created
cout<< ip ;             //  0
cout<< *ip ;            //  throws error!

if (ip) { ... }         // To avoid null pointer access

int var = 20;
int *ptr;
ptr = &var;             // Set pointer to address of variable var
cout<< *ip << endl;     // 20
```
## Pointer Arithmetic
++, --, +, -

### Incrementing
```
int var[] = {1, 2, 3};
int *p = NULL;
p = var;        // works because arrays are pointers to memory
for (int i = 0; i < 3; i++) {
    cout<< *p << endl;
    p++;        // increment the pointer ex: 1000, 1004 (int memory addres)
}
// Output: 1, 2, 3
```

### Decrementing
```
int var[] = {1, 2, 3};
int *p = NULL;
p = &var[2];        // size -1
for (int i = 0; i < 3; i++) {
    cout<< *p << endl;
    p--;        // decrement the pointer ex: 1000, 996 (int memory addres)
}

// Output: 3, 2, 1
```
### Pointer Comparison
```
int var[] = {1, 2, 3};
int *ptr = NULL;
ptr = var;
while (ptr <= &var[size - 1]) {
    cout<< *ptr << endl;
    ptr++;
}
```
### Pointers and Arrays
* Can use pointer to assign a value to an array
```
int var[] = {1, 2, 3};
int *ptr = NULL;
p = var;

*(var + 0)  // 1
*(var + 1)  // 2
*(var + 2)  // 3

correct:    *var = 0;
incorrect:  var++;
```
* BUT Pointers and arrays are NOT interchangeable 

### Ararys of pointers
```
#include <iostream>
using namespace std;
const int sz = 3;

int main() {
    int var[sz] = {10,100,200};
    int *ptr[sz];   //  declaration of an array of integer pointers

    for (int i = 0; i < sz; i++) {
        ptr[i] = &var[i];       // assign address of integer
    }

    for (int i = 0; i < sz; i++) {
        cout<<*ptr[i];       // 10, 100, 200
    }

    // Example 2:
    char * names[sz] = {"name A", "name B", "name C"};
    for (int i = 0; i < sz; i ++) {
        cout << *(names + i) << endl;       // name A, name B, name C
    }
}
```

### Pointer to Pointer
``` 
 pointer      pointer     variable 
[Address] -> [Address] -> [value]

int ** var;

int main() {
    int var;
    int *ptr;
    int **pptr;
    var = 3000;
    ptr = &var;
    pptr = &ptr;
    cout << var << endl;        // 3000
    cout << *ptr << endl;       // 3000
    cout << **pptr << endl;     // 3000
}
```
### Passing Pointers to Functions
* This allows you to change the value inside the function and it reflects back in the calling function
```
#include <iostream>
#include <ctime>
using namespace std;
void getSeconds(unsigned long *ptr) {
    // Get current # of seconds;
    *ptr = time(NULL);
}
int main() {
    unsinged long sec;
    getSeconds(&sec);
    cout << sec << endl;
}
```
* Function can accept array or pointer

```
int myFunc(int * arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i ++) {
        sum += arr[i] << endl; 
    }
    return sum;
}

int main() {
    int nums[5] = {1,2,3,4,5};
    int a = myFunc(nums, 5);
}
```
### Return Pointers from Functions
```
int * myFunc(){
    static int arr[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = rand();        // Not how rand works, but for ex sake
    }
    return arr;
}

int main() {
    int *p;
    p = myFunc();
    for (int i = 0; i < 5; i++) {
        cout << *(p + i) << endl;
    }
}

```

# References vs Pointers
* **Reference Variable**--alias
  * Another name for already existing variable
  * once initialized, references or var name can be used to refer to variable

### Difference between references and pointers
* References cannot be NULL
  * must connect to legitimate piece of storage
* Once reference is initialized, it cannot be changed to refer to another object. 
  * Pointers can be pointed to another object at any time
* Reference must be initalized on creation

### Creating Reference
```
int i = 17;
int &r = i;        // Read as: "r is an integer reference initialized to i"

double d = 4.3;
double &s = d;     // Read as: "s is a double reference initialized to d"

cout << i << r << d << s << endl;
//     17   17   4.3  4.3
```
### Passing parameter by reference
* Call by reference using pointers (covered earlier)
```
int a = 100;
int b = 200;
swap(a,b);

void swap(int & x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
```
### Returning Values by Reference
* References can be easier to read than pointers
* C++ function can return a reference like it can a pointer
  * returns an implicit pointer === reference to its return value
* **NOTE**
  * Cannot return reference to object that has gone out of scope
```
int & func() {
    int q;          // do NOT return "q" // compile time error
    static int x;   
    return x;       // Safe, x lives outside scope
}
```

```
#include <iostream>
#include <ctime>
using namespace std;

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double & setVals(int i) {
    return vals[i];
}

int main() {
    for (int i = 0; i < 5; i++) {
        cout << vals << ", ";
    }
    // Output: 10.1, 12.6, 33.1, 24.1, 50.0

    setVals(1) = 20.0; 
    setVals(3) = 3.3;
    setVals(0) = 0.01;

    for (int i = 0; i < 5; i++) {
        cout << vals << ", ";
    }
    // Output: 0.01, 20.0, 33.1, 3.3, 50.0

}
```
# Structs
* Allow you to define variables that combine several different kinds of data items

```
struct [struct tag] {
    member definition;  // ex int i;
    member definition;
    ...
} [one or more structure variables];
```
* A struct defines a new data type
* [structure tag] - optional
### To access a struct member
* Use "." operator



# to be continued....

# Remaining topics to cover

### Pointers to Structs

### Structs vs Classes (C++)


# "typedef" keyword
### typedef vs const

# Classes and Objects
## Constructors
### Initialization Lists
### Copy Constructor
## Deconstructors
## Friend Function
## Inline Function
## "this" pointer
### Pointer to C++ class
### Static Members of a Class
# Stack vs Heap
### Stack Allocation
### Heap Allocation
### Types of Memory Allocation
### Arrays in the Heap
# Inheritence (Polymorphism) classes
### Static Resolution
### Derived Access Specifier

## Multiple Inheritance 

# Overload Operator
## Overload "+" operator




