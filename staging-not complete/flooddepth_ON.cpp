// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // return depth at  lowest point 
    if (A)
    int size = A.size();
    
    int startingWallHeight = A[0];
    int wallHeightatI = ;
    int deepestDipHere = 0;
    int deepestDip = 0;
    bool onTheWayUp = false;
    bool inADip = false;
    int L[size] = {0};

    for (int i = 1; i <size; i++){
        if (A[i-1] < A[i]){
            // if current is higher 
            onTheWayUp = true;
        } else if (A[i-1] > A[i]){
            // if current is higher 
            onTheWayUp = false;
        }
        else {
            continue;
        }
        if ()

    }

    return deepestDip;

}
