class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> points;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.push_back({i, j});
            }
        }

        dp[0][0] = 0;

        sort(points.begin(), points.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return grid[a.first][a.second] > grid[b.first][b.second];
        });

        for (int t = 0; t <= k; t++) {

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int new_cost = INT_MAX; 
                    
                    if (i > 0) new_cost = min(new_cost, dp[i - 1][j]);
                    if (j > 0) new_cost = min(new_cost, dp[i][j - 1]);

                    if (new_cost != INT_MAX) {
                        int cost = new_cost + grid[i][j];
                        if (dp[i][j] > cost) {
                            dp[i][j] = cost;
                        }
                    }
                }
            }

            if (t < k) {
                int min_cost_so_far = INT_MAX;

                for (int i = 0; i < points.size(); ) {
                    int j = i;

                    while (j < points.size() &&
                           grid[points[j].first][points[j].second] == grid[points[i].first][points[i].second]) {
                        j++;
                    }

                    int current_group_min = INT_MAX;
                    for (int k_idx = i; k_idx < j; k_idx++) {
                        int r = points[k_idx].first;
                        int c = points[k_idx].second;
                        current_group_min = min(current_group_min, dp[r][c]);
                    }

                    int best_transfer_cost = min(min_cost_so_far, current_group_min);

                    if (best_transfer_cost != INT_MAX) {
                        for (int k_idx = i; k_idx < j; k_idx++) {
                            int r = points[k_idx].first;
                            int c = points[k_idx].second;
                            dp[r][c] = min(dp[r][c], best_transfer_cost);
                        }
                    }

                    min_cost_so_far = best_transfer_cost;

                    i = j;
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};