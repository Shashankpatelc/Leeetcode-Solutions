#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Simple grid scan without BFS
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0, rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> direction{{-1, 0},{0, 1},{1, 0},{0, -1}};

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (grid[x][y] == 1) {
                    for (auto& dir : direction) {
                        int r = x + dir.first;
                        int c = y + dir.second;
                        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }

    // BFS approach (alternative)
    int islandPerimeter_bfs(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<pair<int, int>> direction{{-1, 0},{0, 1},{1, 0},{0, -1}};
        deque<pair<int, int>> queue;
        int count = 0, x, y;

        // Find first land cell
        bool found = false;
        for (x = 0; x < rows && !found; x++) {
            for (y = 0; y < cols; y++) {
                if (grid[x][y] == 1) {
                    queue.push_back({x, y});
                    visited[x][y] = true;
                    found = true;
                    break;
                }
            }
        }

        // BFS traversal
        while (!queue.empty()) {
            auto [x, y] = queue.front(); queue.pop_front();
            for (auto& dir : direction) {
                int r = x + dir.first;
                int c = y + dir.second;

                if (r >= 0 && c >= 0 && r < rows && c < cols) {
                    if (grid[r][c] == 1 && !visited[r][c]) {
                        queue.push_back({r, c});
                        visited[r][c] = true;
                    } else if (grid[r][c] == 0) {
                        count++;
                    }
                } else {
                    count++;
                }
            }
        }

        return count;
    }
};

