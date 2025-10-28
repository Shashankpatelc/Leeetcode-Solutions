#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        queue<pair<int,int>> q;
        vector<pair<int,int>> direction = {
            {-1,0},{0,1},{1,0},{0,-1}
        };

        int col = image[sr][sc];
        q.push({sr,sc});
        while(!q.empty()){
            auto [x,y] = q.front();
            image[x][y] = color;
            q.pop();

            for(auto [r,c] : direction){
                r = r + x;
                c = c + y;
                if (c > -1 && r > -1 && c < m && r < n && !visited[r][c] && image[r][c] == col){
                    q.push({r,c});
                    visited[r][c] = true;
                }
            }
        }
        return image;
    }
};

