class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int ans = 0;
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> presum(m+1, vector<int>(n + 1, 0));

        // rectangle prefix
        for( int i = 0; i < m; i++ ) {
            for( int j = 0; j < n; j++ ) {
                presum[i+1][j+1] = presum[i][j+1] + mat[i][j] + presum[i+1][j] - presum[i][j];
            }
        }

        // insted of check each we check the square sum and compare to next square
        for( int i = 0; i <= m; i++ ) {
            for( int j = 0; j <= n; j++ ) {

                int target = ans + 1;
                if( i >= target && j >= target ) {

                    int sum = presum[i][j] + presum[i - target][j - target] - presum[i][j-target] - presum[i-target][j];

                    if( sum <= threshold ) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
