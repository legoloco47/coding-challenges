// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // not quite "longest contiguous subsequence"
    // but, longest "things less than the edges" problem

    // create a table --> let L[i] be the deppest flood length at element [i]
    // need decrease than increase 
    int N = A.size();
    if (N < 3) return 0;
    int L[N] = {0};
    int deepest = 0;
    int tallest = max(A[0], A[1]);
    int lowest = (A[0] > A[1]) ? A[0] - A[1] : 0;
// a depth means you have a block A[j] >= A[i] and 
//       a block A[k] (j<k<i) where A[k] < A[j] && A[k] < A[i]
//   L[i] = min(A[j],A[i]) - A[k]

// Try greedy approach first, then find overlapping subproblems
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1;j < N;j++){
            for (int k = i+1;k < j; k++){
                if (A[i] <= A[k]) {
                    // cout<<"\tA["<<i<<"]<=A["<<k<<"]"<<endl;
                    j = N;
                    break;
                }

    // cout<<"["<<i<<" k("<<k<<") "<<j<<"] = "<<"["<<A[i]<<" "<<A[k]<<" "<<A[j]<<"]"<<endl;
                if (A[k] < A[j] && A[k] < A[i] && A[j] >= A[i]) {
                    L[i] = min(A[j],A[i]) - A[k];
                    // cout<<"found a depth: "<<L[i]<<endl;
                    deepest = max(deepest, L[i]);
                }
            }
        }
    }
    // for (int i = 0; i <N; i++){
    //     cout<<L[i]<<" ";
    // }

    return deepest;
}