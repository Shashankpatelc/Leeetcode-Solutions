from typing import List


class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        
        def dfs(r, c):
            if r == n - 1:
                return triangle[r][c]
            
            sum1 = dfs(r + 1, c)
            sum2 = dfs(r + 1, c + 1)
            
            return triangle[r][c] + min(sum1, sum2)
        
        return dfs(0, 0)