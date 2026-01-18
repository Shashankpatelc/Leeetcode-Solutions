class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int size = 1;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));

        // Row prefix
        for( int i = 0; i < m; i++ ) {
            for( int j = 0; j < n; j++ ) {
                row[i][j + 1] = row[i][j] + grid[i][j];
            }
        }

        // col prefex
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < m; j++ ) {
                col[j + 1][i] = col[j][i] + grid[j][i];
            }
        }

        // find the largest size
        size = min(m,n);
        for( size ; size > 1; size--) {

            // create a matrix of the size
            for( int i = 0; i+size <= m; i++ ) {
                for( int j = 0; j+size <= n; j++ ) {
            
                    int dia = 0, adia = 0;
            
                    // Find the sum of diagnal
                    for( int d = 0; d < size; d++){
                        dia += grid[i + d][j + d];
                        adia += grid[i + d][j + size - d - 1];
                    }
            
                    if(dia != adia) continue;
                    int rowval = 0;
                    int colval = 0;

                    // Check if all the row and column are equal
                    for( int k = 0; k < size; k++ ) {
                        rowval = row[i + k][j + size] - row[i + k][j];
                        colval = col[i + size][j + k] - col[i][j + k];

                        if( rowval != dia || colval != dia ) {
                            rowval = 0;
                            break;
                        }
                    }

                    if( rowval != 0) {
                        return size;
                    }
                }
            }
        }

        // Return the size 
        return 1;
    }
};