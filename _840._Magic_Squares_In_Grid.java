class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int count = 0;

        for (int i = 0; i < row - 2; i++) {
            for (int j = 0; j < col - 2; j++) {
                int total = 0;
                boolean[] seen = new boolean[10]; 
                boolean invalid = false;
                
                for (int r = 0; r < 3; r++) {
                    for (int c = 0; c < 3; c++) {
                        int num = grid[i + r][j + c];
                        total += num;
                        if (num < 1 || num > 9) {
                            invalid = true;
                            break;
                        }
                        if (seen[num]) {
                            invalid = true;
                            break;
                        }
                        seen[num] = true;
                    }
                    if (invalid) break;
                }
                
                if (invalid || total != 45) continue;
                
                if (grid[i][j] + grid[i][j+1] + grid[i][j+2] == 15 && 
                grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] == 15 && 
                grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] == 15 && 
                grid[i][j] + grid[i+1][j] + grid[i+2][j] == 15 && 
                grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] == 15 && 
                grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] == 15 && 
                grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] == 15 && 
                grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] == 15) {
                    count++;
                }
            }
        }
        return count;
    }
}