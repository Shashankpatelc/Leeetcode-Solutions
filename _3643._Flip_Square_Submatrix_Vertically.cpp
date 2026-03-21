class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int temp;

        for(int i = x; i < x+k/2; i++ ) {
            int target_row = 2*x + k - i - 1;
            for(int j = y; j < y+k; j++) {
                temp = grid[i][j];
                grid[i][j] = grid[target_row][j];
                grid[target_row][j] = temp;
            }
        }

        return grid;
    }
};