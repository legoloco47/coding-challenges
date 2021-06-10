int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    if (N == 0) return 0;
    if (N==1){
        if(A[1] < 0) 
            return 0;
        return A[1];
    }
    // 2, 4,1,8,-3,2,7
    // looking for longest contiguous sum  
    int maxSum = 0;

    int profit = 0;
    int last = A[0];
    for (int i = 1; i < N; i++){
        profit = profit + (A[i]-last);
//cout<<A[i]<<": profit = "<<profit<<" = "<<A[i]<<" - "<<last<<" ";
        if (profit < 0) {
            profit = 0;
        }
        last = A[i];

        
        maxSum = (profit > maxSum) ? profit : maxSum;
        //cout<<" New max sum "<<maxSum<<endl;
    }

    return maxSum;

}