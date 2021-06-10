#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    int maxSum = 0;
    int N = arr.size();
    int L[N];
    memset(L, 0 ,sizeof(L));// = {0};
    
    // let L[n] be the max sum if you take n
    //3 5 -7 8 10
    if (N==0) return 0;
    if (N == 1) return (arr[1] > 0) ? arr[1] : 0;
    if (N == 2) {
        maxSum =  (arr[1] > arr[2]) ? arr[1] : arr[2];
        return max(maxSum, 0);
    } 
    // N > 2
    L[0] = max(0, arr[0]);
    L[1] = max(L[0], arr[1]);
    //L[2] = L[0] + max(0, arr[2]); 
    maxSum = L[1];
    // max sum of non adjacent elements
    for (int i = 2; i < N; i++) {
        if (arr[i] <= 0) {
            L[i] = maxSum;
        } else {
            
            L[i] = max(L[i-2] + max(0, arr[i]), L[i-1]);
        }
        maxSum = (maxSum > L[i]) ? maxSum : L[i];
        //cout<<i<<": maxsum = "<<maxSum<<endl;
    }
    
    // cout<<"L = ";
    // for (int i = 0; i <N; i ++) {
    //     cout<<L[i]<<" ";
    // }
    return maxSum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
