/*

This is the fibonacci seqeunce in:
1. Recursive solution
2. Memoization (top down)
3. Tabulation (bottom up)
4. Clever solution
*/
#include <iostream>
#include <chrono>
// For calculating time it takes to execute function
// https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c


using namespace std;

enum DPAlgorithms {recursive, memoization, tabular, clever};

/* O(n^2) */
long fibonacci_recursive(int n) {
    if (n < 2) return n;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

/*
Memoization--Top-down solution
- there are a lot of identical nodes
*/
long int fibonacci_memoization(int n, long int memo[]) {
    if (memo[n] == -1) {
        if (n < 2) memo[n] = n;
        else
            memo[n] = fibonacci_memoization(n-1, memo) + fibonacci_memoization(n-2,memo);
    }
    
    return memo[n]; 
}

int fibonacci_memoization_wrapper(int n) {
    long int memo[n+1];
    memset(memo, -1, sizeof(memo));
    return fibonacci_memoization(n, memo);
}

/* Tabulation -- bottom up approach */
long int fibonacci_tabular(int n) {
    long int memo[n+1];
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i-1] + memo[i-2];        
    }

    return memo[n]; 
}


/* Clever */
long int fibonacci_clever(int n) {
    long int memo[n+1];
    long int a,b,c, temp;
    a = 0;
    b = 1;
    for (int i = 2; i <= n; i++) {
        temp = a;
        c = a + b;
        a  = c;
        b = temp;
        //cout<<i<<": a = "<<a<<", b = "<<b<<", c = "<<c<<"\n";
    }

    return a+b;
}


int calculateFibonaci(DPAlgorithms algo, int N) {
    switch (algo) {
        case recursive:
            return fibonacci_recursive(N);
        case memoization:
            return fibonacci_memoization_wrapper(N);
        case tabular:
            return fibonacci_tabular(N);
        case clever:
            return fibonacci_clever(N);
        default:
            cout<<"Something went wrong \n";
            return -1;
    }
}

chrono::milliseconds calculateFibonaciTime(DPAlgorithms algo, int N, int result) {
    auto t1 = chrono::high_resolution_clock::now();
    long res = calculateFibonaci(algo, N);
    auto t2 = chrono::high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
    chrono::duration<double, std::milli> ms_double = t2 - t1;

    if (res != result) {
        cout<<"Expected "<<result<<" got "<<res<<endl;
        return chrono::milliseconds(0);
    } else {
        cout<<"Got correct number "<<result<<" calculcation took "<<ms_double.count()<<endl;
        return ms_int;
    }
}

void CompareFibonacciAlgosForN(int n, long result){
    cout<<"Calculate the "<<n<<"th fibonacci number:"<<endl;
    cout<<"Recursive"<<endl;
    calculateFibonaciTime(recursive, n, result);
    cout<<"Memoization"<<endl;
    calculateFibonaciTime(memoization, n, result);
    cout<<"Tabular"<<endl;
    calculateFibonaciTime(tabular, n, result);
    cout<<"Clever"<<endl;
    calculateFibonaciTime(clever, n, result);
}

int main() {
    CompareFibonacciAlgosForN(30,832040);
    //CompareFibonacciAlgosForN(40,102334155);
    // Takes too long on my PC
    //CompareFibonacciAlgosForN(50,12586269025);
    //CompareFibonacciAlgosForN(60,1548008755920);
    
    return 0;
}

/*
Calculate the 30th fibonacci number:
Recursive
Got correct number 832040 calculcation took 5.91909
Memoization
Got correct number 832040 calculcation took 0.00936
Tabular
Got correct number 832040 calculcation took 0.000172
Clever
Got correct number 832040 calculcation took 0.000175


Calculate the 40th fibonacci number:
Recursive
Got correct number 102334155 calculcation took 611.103
Memoization
Got correct number 102334155 calculcation took 0.000469
Tabular
Got correct number 102334155 calculcation took 0.000164
Clever
Got correct number 102334155 calculcation took 0.000172
*/