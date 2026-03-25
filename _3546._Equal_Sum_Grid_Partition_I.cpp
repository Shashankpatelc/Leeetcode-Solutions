class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> row_prefix;
        vector<long long> col_prefix;

        long long row_acc = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row_acc += grid[i][j];
            }
            row_prefix.push_back(row_acc);
        }

        long long total_sum = row_prefix.back();

        if (total_sum % 2 != 0) return false;
        long long target = total_sum / 2;

        long long col_acc = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                col_acc += grid[i][j];
            }
            col_prefix.push_back(col_acc);
        }

        for (int i = 0; i < m - 1; i++) {
            if (row_prefix[i] == target) return true;
        }

        for (int j = 0; j < n - 1; j++) {
            if (col_prefix[j] == target) return true;
        }

        return false;
    }
};