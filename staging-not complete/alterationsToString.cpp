 int editDistance(string s, string t) {
        // Code here
        string c = s;
        s = t;
        t = c;
        int x = s.length();
        int y = t.length();
        x++;
        y++;
        int L[x][y];
        memset(L, 0 , sizeof(L));
        for (int i = 0; i < x; i++)  L[i][0] = i;
        for (int j = 0; j < y; j++)  L[0][j] = j;
        
        for (int i = 1; i < x; i++){
            for (int j = 1; j <y;j++) {
                if (s.at(i-1) == t.at(j-1)) {
                    L[i][j] = L[i-1][j-1];
                } else {
                    int v = min(L[i-1][j], L[i][j-1]);
                    v = min(v, L[i-1][j-1]);
                    L[i][j] = 1 + v;
                }
            }
        }
        // for (int i = 0; i < x; i++){
        //     for (int j = 0; j <y;j++) {
        //         cout<<L[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        return L[x-1][y-1];
    }