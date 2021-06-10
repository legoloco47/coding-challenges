#include <bits/stdc++.h>
#include <vector>
#include <map>

using namespace std;


/*--------------------------------------------------*/
// Reverse the array using a secondary vector
vector<int> reverseArray(vector<int> a) {
    int length = a.size();
    vector<int> reversedA;
    
    for (int i = length - 1; i >= 0;  i--){
        reversedA.push_back(a[i]);
    }
    
    return reversedA;
}

/*--------------------------------------------------*/
// reverse the array inplace
void swap(int& x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

vector<int> reverseArrayInplace(vector<int> a){
    int half = a.size() / 2;
    int length = a.size();
    for(int i = 0; i < half; i++) {
        swap(a[i], a[length- 1 - i]);
    }
    return a;
}
/*--------------------------------------------------*/

/*
 * Complete the 'rotateLeft' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */

vector<int> rotateLeft(int d, vector<int> arr) {
    int length = arr.size();
    if (length == 0 || d%length == 0) 
        return arr;
    
    // Get the actual array length
    d = d % length;
    
    vector<int> rotatedArr; 
    
    rotatedArr.insert(rotatedArr.end(), arr.begin() + d, arr.end());
    rotatedArr.insert(rotatedArr.end(), arr.begin(), arr.begin() + d);
    
    return rotatedArr;   
}


string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY strings
 *  2. STRING_ARRAY queries
 */

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    map<string, int> stringMap;
    
    int numberOfStrings = strings.size();
    int numberOfQueries = queries.size();
    vector<int> results;

    if (numberOfQueries == 0) return results; 
    
    for (int i = 0; i < numberOfStrings; i++) {
        stringMap[strings[i]] += 1;
    }
    
    for (int i = 0; i < numberOfQueries; i++) {
        results.push_back(stringMap[queries[i]]);
    }
    
    return results;    
}
