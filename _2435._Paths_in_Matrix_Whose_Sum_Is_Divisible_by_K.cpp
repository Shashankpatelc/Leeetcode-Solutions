#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1'000'000'007;
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, 0))
        );

        dp[0][0][ grid[0][0] % k ] = 1;

        for (int i = 0; i < m; ++i) {

            for (int j = 0; j < n; ++j) {

                if (i == 0 && j == 0) 
                    continue;
                int val = grid[i][j] % k;   

                for (int prev_r = 0; prev_r < k; ++prev_r) {
                
                    int new_r = (prev_r + val) % k;
                    long long add = 0;
                
                    if (i > 0) 
                        add += dp[i-1][j][prev_r];
                
                    if (j > 0) 
                        add += dp[i][j-1][prev_r];
                
                    if (add) {
                        dp[i][j][new_r] = (int)((dp[i][j][new_r] + add) % MOD);
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};
