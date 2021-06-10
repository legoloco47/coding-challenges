#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;

/*
goal: create a random number generator
// except reduce duplciation as much as possible

user calls random number generator repeatedly 

bounds on the 
user will provide a range (integers)
return value: int

    
    v1 = rand() % 100;         // v1 in the range 0 to 99
    v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
    v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
    
    //rand ()  --> The rand() function is used in C/C++ to generate random numbers in the range [0, RAND_MAX). 

1--
*/
// Check for valid input
// Range is inclusive
//  Esnure upperRange > lowerRange
set<int> randomNumbersSeen;

int GetRandomNumber(int lowerRange, int upperRange) {
    //if (upperRange < lowerRange) return NULL;
           
    int randomValue;
    
    /* initialize random seed: */
    srand (time(NULL));
    
    int values = upperRange-lowerRange+1;
    // TODO: make sure this works for range of 1, 2, 3
    if(randomNumbersSeen.size() == values){
        randomNumbersSeen.clear();
        cout<<"--------\n";
    }
    
    // correct if lower range is negative
    
    randomValue = rand() % values;
    randomValue  = randomValue + lowerRange;
    
    while(randomNumbersSeen.count(randomValue) == 1) {
        // If the set.size() is equal to values. We have exhausted our possibilities --> clear the set
        randomValue = rand() % values;        
        randomValue  = randomValue + lowerRange;
    }
    
    randomNumbersSeen.insert(randomValue);
    
    return randomValue;    
}
//int ar

int main() {
    int numberOfRandomNumbers, upperRange, lowerRange;
    //cin>>numberOfRandomNumbers>>lowerRange>>upperRange;
    numberOfRandomNumbers = 10;
    upperRange = 3;
    lowerRange = -3;
    cout<<"range: "<<upperRange<<" "<<lowerRange<<" values: "<<upperRange - lowerRange + 1<<endl;

    int randomNumber;
    int i = 0;
    while(i < numberOfRandomNumbers) {
        randomNumber = GetRandomNumber(lowerRange, upperRange);        
        cout<<randomNumber<<endl;
        i++;       
    }

    return 0;
}
