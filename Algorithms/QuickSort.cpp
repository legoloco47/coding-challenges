/*
Picks a random element as a "pivot" and then swaps values in the array such that 
    elemnts "< pivot" appear on the LHS and elements "> pivot" appear on the RHS of the pivot
This gives a partial sort.
Then, it recursively sorts left and right sides using a similar process

Best Case Scenario: Omega(N), O(N)
Worst Case Scenario: O(N^2)
    - Can happen if pick pivot to be largest element 
    - Can happen if use a[0] as pivot in reverse sorted array
    - recursive shrinks array by 1 element each time
Expected Case: O(nLogn)


swap(&a, &b) is included in STL (bits/stdc++.h)
*/
#include <bits/stdc++.h>

int partition(int a[], int start, int end) {
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++) {
        if (a[i] <= pivot) {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }

    swap(a[pIndex], a[end]);        // swap pIndex with pivot
    return pIndex;
}

void quickSort(int a[], int start, int end) {
    // base condition
    if (start >= end) return;
    int pivot = partition(a, start, end);
    quickSort(a, start, pivot - 1);
    quickSort(a, pivot+1, end);
}

int main() {
    int a[] = {9, -3, 6, 2, 5, 8, -6, 1, 3};
    int size = sizeof(a)/sizeof(a[0]);
    quickSort(a, 0 ,size-1);
}