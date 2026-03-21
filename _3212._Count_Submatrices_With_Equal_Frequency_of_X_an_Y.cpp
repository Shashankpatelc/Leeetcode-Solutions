class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> num(m, vector<int>(n, 0));
        vector<vector<int>> xcount(m, vector<int>(n, 0));
        int count = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                xcount[i][j] = 0;
                if(grid[i][j] == 'X') {
                    num[i][j] = 1;
                    xcount[i][j] = 1;
                }
                else if(grid[i][j] == 'Y') num[i][j] = -1;
                else num[i][j] = 0;
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                if(i == 0){
                    num[i][j] += num[i][j-1];
                    xcount[i][j] += xcount[i][j-1];
                } 
                else if(j == 0) {
                    num[i][j] += num[i-1][j];
                    xcount[i][j] += xcount[i-1][j];
                } 
                else {
                    num[i][j] +=(num[i][j-1] + num[i-1][j] - num[i-1][j-1]);
                    xcount[i][j] +=(xcount[i][j-1] + xcount[i-1][j] - xcount[i-1][j-1]);
                }
                
                if(num[i][j] == 0 && xcount[i][j] > 0) count++;
            }
        }

        return count;
    }
};