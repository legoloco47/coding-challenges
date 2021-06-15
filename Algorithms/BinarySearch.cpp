/*
Binary Search

O(?) : n -> n/2 -> n/2 -> n/4 -> ... -> 1
            n/(2^k) = 1
            n = 2^k
            k = log(2)(n)

*/

// Recursive Solution

int binSearch(int A[], int low, int high, int x) {
    if (low > high) return -1;

    int mid = (low + high) / 2;         // or low + (high-low)/2
    if (x == A[mid]) return mid;
    else if (x < A[mid]) return binSearch(A, low, mid-1, x);
    else return binSearch(A, mid+1, high, x);
}