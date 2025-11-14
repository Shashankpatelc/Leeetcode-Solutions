#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        for( auto &a : queries){
            for( int i = a[0]; i <= a[2]; i++){
                for( int j = a[1]; j <= a[3]; j++){
                    res[i][j] += 1;
                }
            }
        }
        return res;
    }
};