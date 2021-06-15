I. Public vs private vs protected
* Public—members of class A are accessible for all and everyone
* Protected—members of class A are not accessible outside of A’s code. But it is accessible from the code of any class derviced from A
* Private—memebrs of a ckass A are not accessible outside of A’s code or from the code of any class derviced from A

Choosing between protected or private?
* How much trust do you have in the programmer of the derived class?
* By default assume derviced classes cannot be trusted -> use private

Protected—child classes can access the inherited protected data members of base class

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


class Circle {
private: double radius;
public:
    double computeArea(double r){
        radius = r;
        return radius*3.14* radius;
    }
};


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







