// you can use includes, for example:
#include <algorithm>
#include <cmath>
#include <math.h>
#include <bits/stdc++.h>
#include <string>

int getDigitCount(int N) {
    //ex 54321 = 10^4.73 -> 5
    if (N==0) return 1;
    return ceil(log10(N));
}
/*
    Approach (performance is not of concern)
    several different ways to do it:
    1-iterate through value until find digit less than 5 (using % and *10). insert it there
        if the digit is <5 put it there, else keep iterating
        if negative, do other precauntions
    2-use strings <-- chose this approach
    */
int solution(int N) {

    bool isNegative = false;
    int maximalSum = INT_MIN;

    if (N < 0) {
        isNegative = true;
        N = abs(N);
    }

    int digits = getDigitCount(abs(N));
    string intString = to_string(N);
    
    if (isNegative){
        maximalSum = INT_MAX;
    }
    for (int i = 0; i<= digits; i++) {
        string tryfives = intString.substr(0,i) + '5' + 
            intString.substr(i, digits+1);
        // cout<<"tryfives = "<<tryfives<<endl;
        int current = stoi(tryfives);

        if (isNegative){ 
            if (current < maximalSum) 
                maximalSum = current;
        } else {
            if (current > maximalSum) 
                maximalSum = current;
        }
    }
    if (isNegative) maximalSum *=-1;
    
    return maximalSum;
   
/*
// try to simply the original code (above is simplification)

    if (isNegative){
        maximalSum = INT_MAX;
        for (int i = 0; i<= digits; i++) {
            string tryfives = intString.substr(0,i) + '5' + 
                intString.substr(i, digits+1);
            // cout<<"tryfives = "<<tryfives<<endl;
            int current = stoi(tryfives);

            if (current < maximalSum) 
                maximalSum = current;
        }
        
        return -1*maximalSum;
    } else {
        for (int i = 0; i<= digits; i++) {
            string tryfives = intString.substr(0,i) + '5' + 
                intString.substr(i, digits+1);
            int current = stoi(tryfives);
            // cout<<"tryfives = "<<tryfives<<endl;
            if (current > maximalSum) 
                maximalSum = current;
        }
    }
*/
    return maximalSum;
}
