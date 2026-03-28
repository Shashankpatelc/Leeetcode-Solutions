class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> copy = mat;

        k = k % n;
        
        for(int t = 0; t < k; t++) {
            for(int i = 0; i < m; i++ ) {
                if(i % 2 == 0) {
                    int temp = mat[i][0];
                    for(int j = 1; j < n; j++) {
                        mat[i][j-1] = mat[i][j];
                    }
                    mat[i][n-1] = temp;
                } else {
                    int temp = mat[i][n-1];
                    for(int j = n-1; j > 0; j--) {
                        mat[i][j] = mat[i][j-1];
                    }
                    mat[i][0] = temp;
                }
            }
        }

        if(mat == copy) {
            return true;
        }
        return false;
    }
};