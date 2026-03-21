class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        if(k == 1) {
            vector<vector<int>> ans(m, vector<int>(n ,0));
            return ans;
        } 

        vector<vector<int>> ans;
        for(int i = 0; i < m - k + 1; i++ ) {

            vector<int> row;
            for(int j = 0; j < n - k + 1 ; j++ ) {

                set<int> ele;
                int minDiff = INT_MAX;
                for(int x = 0; x < k; x++) 
                    for(int y = 0; y < k; y++) 

                        ele.insert(grid[x+i][y+j]);
                    
                if(ele.size() == 1) {
                    row.push_back(0);
                }
                else {
                    int prev = -100001;
                    for(int curr : ele) {
                        if(prev == -100001) {
                            prev = curr;
                        } else {
                            minDiff = min(minDiff, abs(prev - curr));
                            prev = curr;
                        }
                    }
                    row.push_back(minDiff);
                }
            }
            ans.push_back(row);
        }
        return ans;
    }
};