class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<pair<int,int>> calc;
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        for(auto &ele : strs){
            int c_0 = count(ele.begin(), ele.end(), '0');
            calc.push_back({c_0, ele.size() - c_0});
        }

        for (const auto &p : calc) {
            int zeros = p.first;
            int ones  = p.second;

            if (zeros > m || ones > n) continue;

            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
