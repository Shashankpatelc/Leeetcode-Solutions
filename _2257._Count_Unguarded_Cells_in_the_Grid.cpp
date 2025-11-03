#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 = free, 1 = guard, 2 = wall, 3 = guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark guards
        for (auto& g : guards) {
            grid[g[0]][g[1]] = 1;
        }
        
        // Mark walls
        for (auto& w : walls) {
            grid[w[0]][w[1]] = 2;
        }
        
        // Direction vectors: up, right, down, left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        // Process each guard
        for (auto& g : guards) {
            // Look in all 4 directions
            for (int dir = 0; dir < 4; dir++) {
                int x = g[0] + dx[dir];
                int y = g[1] + dy[dir];
                
                // Keep moving in this direction
                while (x >= 0 && x < m && y >= 0 && y < n) {
                    // Stop at guard or wall
                    if (grid[x][y] == 1 || grid[x][y] == 2) {
                        break;
                    }
                    
                    // Mark as guarded
                    grid[x][y] = 3;
                    
                    // Move to next cell
                    x += dx[dir];
                    y += dy[dir];
                }
            }
        }
        
        // Count free cells
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
