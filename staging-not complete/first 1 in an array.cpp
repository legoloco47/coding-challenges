// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
     int N = A.size();
     sort(A.begin(), A.end());

     // we have a sorted array
     //get the first element
     if (A[N-1] <= 0) {
         // If the entire array is negative or 0, then return 1
         return 1;
     }
     if (A[0] > 0){
        if (A[0] != 1) {
            return 1;
        }
        // we have at least (1, numbers...)
        for (int i = 1; i < N; i++){
            if (A[i] != A[i-1] + 1 && A[i] != A[i-1]) {
                return A[i-1] + 1;
            }
        }
        return A[N-1] + 1;
     }
     
     // we have a mixed array (ex: [-10,-5,-1,0,4])
     int i = 0;
     while (i<N && A[i] <= 0){
         i++;
     }
     // i is starting at the first positive index 
     
     if (A[i] != 1) {
        return 1;
    }
    // we have at least (1, numbers...)
    for (i; i < N; i++){
        if (A[i] != A[i-1] + 1 && A[i] != A[i-1]) {
            return A[i-1] + 1;
        }
    }

    return A[N-1] + 1;     
}


// version 2

// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    int N = A.size();
    sort(A.begin(), A.end());
    if (A[N-1] <= 0) {
        //entire array is negative or 0 --> return 1;
        return 1;
    }
    if (A[0] > 0) {
        //if entire array is positive, make sure the first element is a 1
        if (A[0] != 1) return 1;
        if (N==1) return 2;
    }
    int i = 0;
    // pass all the negative numbers
    for (i; i < N; i++) {
        if (A[i] <=0) continue;
        else break;
    }
    //cout<<"looking at: A["<<i<<"] = "<<A[i]<<" which should def be positive"<<endl;
    if (A[i] != 1) return 1;

    int same = A[i];

    // next will always exist because of the previous check to make sure the last element is >0
    int next = A[i+1];
    for (i; i < N; i++) {
        if (A[i] != same && A[i] != next){
            //cout<<"Returning "<<next<<endl;
            return next;
        }
        same = A[i];
        next = A[i] + 1;
    }
    //cout<<"Ending at: "<<A[N-1]<<" + 1 = "<<A[N-1]+1<<endl;
    return A[N-1] + 1;
}