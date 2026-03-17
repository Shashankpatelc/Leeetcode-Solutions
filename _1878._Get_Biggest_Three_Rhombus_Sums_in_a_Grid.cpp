class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> res;
        set<int> s;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                s.insert(grid[i][j]);

                for(int k = 1; ;k++) {

                    int sum = 0;
                    int left = j - k;
                    int right = j + k;
                    int bottom = i + 2*k;

                    if(bottom >= m || left < 0 || right >= n) break;

                    for(int t = 0; t < k; t++) {
                        sum += grid[i + t][j + t];
                    }

                    for(int t = 0; t < k; t++) {
                        sum += grid[i + k + t][j + k - t];
                    }
                    
                    for(int t = 0; t < k; t++) {
                        sum += grid[i + 2*k - t][j - t];
                    }

                    for(int t = 0; t < k; t++) {
                        sum += grid[i + k - t][j - k + t];
                    }

                    s.insert(sum);

                }
            }
        }

        for (auto it = s.rbegin(); it != s.rend() && res.size() < 3; ++it) 
            res.push_back(*it);
        
        return res;
    }
};

