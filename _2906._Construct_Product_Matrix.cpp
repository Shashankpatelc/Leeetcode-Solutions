class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int prefix = 1;
        int sufix = 1;
        
        vector<vector<int>> res(m,vector<int>(n));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if( i == 0 && j == 0 ) 
                    res[i][j] = (prefix) % 12345;
                else 
                    res[i][j] = (prefix) % 12345 ;
                
                prefix =((prefix % 12345) * (grid[i][j] % 12345)) % 12345;
            }
        }


        for(int i = m-1; i > -1; i--) {
            for(int j = n-1; j > -1; j--) {
                if( i == m-1 && j == n-1 ) 
                    res[i][j] *= (sufix) % 12345;
                else 
                    res[i][j] = (sufix * res[i][j]) % 12345;

                sufix =((sufix % 12345) * (grid[i][j] % 12345)) % 12345;
            }
        }

        return res;
    }
};