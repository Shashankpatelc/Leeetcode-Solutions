class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> rotatedbox(n,vector<char>(m, '@'));

        // rotate
        for(int i = 0; i < n; i++ ){
            for(int j = 0; j < m; j++ ) {
                rotatedbox[i][j] = boxGrid[m - 1 - j][i];
            }
        }

        // stone allign
        for(int j = 0; j < m; j++) {
            int lowestkey = n - 1;

            for(int i = n-1; i > -1; i--) {
                
                if(rotatedbox[i][j] == '*') {
                    lowestkey = i - 1;
                } else if(rotatedbox[i][j] == '#') {
                    rotatedbox[i][j] = '.';
                    rotatedbox[lowestkey][j] = '#';
                    lowestkey--;
                }
            }
        }
            

        return rotatedbox;
    }
};