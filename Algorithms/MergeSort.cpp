/*
MergeSort
- Divide and conquor algorithm
- divide unsorted arrays into subarrays of 1

O(nlogn)
*/ 

void merge(int arr[], int temp[], int low, int m, int high) {
    int k = low;
    int j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])   
            temp[k++] = arr[i++];
        else 
            temp[k++] = arr[j++];
    }

    // Copy remaining elments
    while (i<=mid) {
        temp[k++] = arr[i++];
    }

    // Note: Do not need to check j, because they are already in temp
    for (int i = low; i <= high; i++) {
        arr[i] = temp;
    }
}

void MergeSort(int arr[], int temp[], int low, int high) {
    // base case
    if (high == low) return;    // run size = 1
    int mid = low + (high - low)/2;
    // Recursively split them in half until size = 1
    // then merge them and return up the call chain
    MergeSort(arr, temp, low, mid);
    MergeSort(arr, temp, mid + 1, high);

    Merge(arr, temp, low, mid, high);
}

int main() {
    srand(time(NULL));
    int arr[N], temp[N];
    for (int i = 0; i <N; i++){
        arr[i] = temp[i] = (rand()%100) - 50;
    }
    MergeSort(arr, temp, 0, N);
}