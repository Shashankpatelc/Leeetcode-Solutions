import heapq
from typing import List

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if not heightMap or not heightMap[0]:
            return 0

        n, m = len(heightMap), len(heightMap[0])
        visited = [[False] * m for _ in range(n)]
        heap = []

        # Push all border cells
        for i in range(n):
            for j in range(m):
                if i == 0 or i == n - 1 or j == 0 or j == m - 1:
                    if not visited[i][j]:
                        visited[i][j] = True
                        heapq.heappush(heap, (heightMap[i][j], i, j))

        total_water = 0
        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        while heap:
            level, x, y = heapq.heappop(heap)
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                    visited[nx][ny] = True
                    next_level = max(level, heightMap[nx][ny])
                    total_water += max(0, level - heightMap[nx][ny])
                    heapq.heappush(heap, (next_level, nx, ny))

        return total_water

