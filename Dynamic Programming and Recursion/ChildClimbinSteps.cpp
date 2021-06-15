/*
This is taken from Cracking the Code Interview

Child can take stairs in 1, 2, or 3 at a time.
Return the total number of combinations possible for a staircase of N steps.



Recursive solution:
base cases: 
if (n == 0) return 0;
if (n == 1) return 1;   // 1 = 1 
if (n == 2) return 2;   // 2 = 11, 2
if (n == 3) return 4;   // 4 = 111, 12, 21, 3

try for more:
if (n == 4) return 7;   // 7 = 31,13, 22, 211,211,112, 1111
if (n == 5) return 13;    // 13 = 

Pattern: stepCount(n) = stepCount(n-1) + stepCount(n-2) + stepCount(n-3) 
*/

int steps_rec(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;   // 1 = 1 
    if (n == 2) return 2;   // 2 = 11, 2
    if (n == 3) return 4;   // 4 = 111, 12, 21, 3
    return steps_rec(n-3) + steps_rec(n-2) + steps_rec(n-1);
}

// Use a cache to prevent recalculation of subproblems
/* Top down approach */
int steps_memo_util(int n, int memo[]) {
    if (n == 0) return 0;
    if (n == 1) return 1;   // 1 = 1 
    if (n == 2) return 2;   // 2 = 11, 2
    if (n == 3) return 4;   // 4 = 111, 12, 21, 3

    if (memo[n] == -1) {
        memo[n] = steps_memo_util(n-1, memo) + steps_memo_util(n-2, memo) + steps_memo_util(n-3, memo);
    }
    return memo[n];
}

int steps_memo(int n) {
    int memo[n];
    memset(memo, -1, n);
}

/* Tabulation--Bottom up approach */
int memo_dp(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;   // 1 = 1 
    if (n == 2) return 2;   // 2 = 11, 2
    if (n == 3) return 4;   // 4 = 111, 12, 21, 3

    int memo[n] = {-1};
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    for (int i = 4; i < n;i ++) {
        memo[n] = memo[n-1] + memo[n-2] + memo[n-3];
    }
    return memo[n-1];
}

/* O(n) */
int step_smart(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;   // 1 = 1 
    if (n == 2) return 2;   // 2 = 11, 2
    if (n == 3) return 4;   // 4 = 111, 12, 21, 3 

    int a = 1;
    int b = 2;
    int c = 4;
    for (int i = 3; i  < n; i++) {
        int d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return a + b + c;
}