from collections import deque
from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        directions = [(1,0),(0,1),(-1,0),(0,-1)]
        n = len( heights )
        m = len( heights[0] )
        
        # Pacific
        pacific_queue = deque()
        pacific_visited = set()

        for i in range(n):
            pacific_queue.append((i,0))
            pacific_visited.add((i,0))
        
        for i in range(1,m):
            pacific_queue.append((0,i))
            pacific_visited.add((0,i))

        while pacific_queue:
            x,y = pacific_queue.popleft()
            pacific_visited.add((x,y))
            for dr,dc in directions:
                if 0 <= x+dr < n and 0 <= y+dc < m and (x+dr,y+dc) not in pacific_visited and heights[x+dr][y+dc] >= heights[x][y]:
                    pacific_queue.append(( x+dr, y+dc ))
                    pacific_visited.add(( x+dr, y+dc ))

        # Atlantic
        atlantic_queue = deque()
        atlantic_visited = set()

        for i in range(m-1):
            atlantic_queue.append((n-1,i))
            atlantic_visited.add((n-1,i))
        
        for i in range(n):
            atlantic_queue.append((i,m-1))
            atlantic_visited.add((i,m-1))

        while atlantic_queue:
            x,y = atlantic_queue.popleft()
            atlantic_visited.add((x,y))
            for dr,dc in directions:
                if 0 <= x+dr < n and 0 <= y+dc < m and (x+dr,y+dc) not in atlantic_visited and heights[x+dr][y+dc] >= heights[x][y]:
                    atlantic_queue.append(( x+dr, y+dc ))
                    atlantic_visited.add(( x+dr, y+dc ))

        # Both common
        result = list(atlantic_visited & pacific_visited)
        return result

