/*

    These are a few simple recursive examples from GeeksforGeeks.com

    This can be run via
    $ g++ SimpleRecursionExamples.cpp -o SimpleRec.out
    $ ./SimpleRec.out
*/
#include <iostream>
using namespace std;

// Calculates log2(n)
int fun1(int n){
    if (n == 1) return 0;
    else return 1 + fun1(n/2);
}

// Outputs binary representation
void fun2(int n) {
    if (n==0) return;
    fun2(n/2);
    cout<< n % 2<<" ";
}

void fun3(int n) {
    if (n <= 0) return;
    if (n > 1000) return;
    cout<<n<<" ";
    fun3(2*n);
    cout<<n<<" ";
}

int main() {
    cout << "Function 1: n = 16 --> " << fun1(16) << endl;
    // Output: 4
    
    cout << "Function 2: n = 21 --> ";
        fun2(21);
    cout << endl;
    // Output: 10101
    
    cout << "Function 3: n = 100 --> ";
        fun3(100);
    cout << endl;
    //  Output: 100, 200, 400, 800, 800, 400, 200, 100

}