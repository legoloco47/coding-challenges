
// function to find longest common subsequence
void printArray(int **L, int x, int y) {
    for (int i = 0; i <x; i++) {
        for (int j = 0; j <x; j++) {
            cout<<L[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int lcs(int x, int y, string s1, string s2){
    // cout<<x<<", s1 = "<<s1<<endl;
    // cout<<y<<", s2 = "<<s2<<endl;
    
    x++;
    y++;
    int L[x][y];
    memset(L, 0, sizeof(L));
    //printArray(L, x, y);
    
    for (int i = 0; i <x; i++) L[i][0] = 0;
    for (int j = 0; j <y; j++) L[0][j] = 0;
    
    //  for (int i = 0; i <x; i++) {
    //     for (int j = 0; j <x; j++) {
    //         cout<<L[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"----------------\n";
    for (int i = 1; i <x; i++) {
        for (int j = 1; j <y; j++){
            if (s1.at(i-1) == s2.at(j-1)) {
                L[i][j] = 1 + L[i-1][j-1];
            }
            else {
                L[i][j] = max(L[i][j-1], L[i-1][j]);
            }
        }
    }

    // for (int i = 0; i <x; i++) {
    //     for (int j = 0; j <x; j++) {
    //         cout<<L[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    return L[x-1][y-1];
    // your code here
    
}