import heapq
from collections import deque
from typing import List

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        memo = {}
        queue = []
        
        n = len(grid)
        direct = [(1,0),(0,1),(-1,0),(0,-1)]
        heapq.heappush(queue,(grid[0][0], 0, 0))
        memo[(0,0)] = grid[0][0]

        while queue:
            val,x,y = heapq.heappop(queue)

            if x == n-1 and y == n-1:
                return val

            for r,c in direct:
                dx = x + r
                dy = y + c

                if 0 <= dx <= n -1 and 0 <= dy <= n-1:
                    if (dx,dy) not in memo:
                        memo[(dx,dy)] = max(val, grid[dx][dy])
                        heapq.heappush(queue,(memo[(dx,dy)], dx, dy))

                    elif max(val,grid[dx][dy]) < memo[(dx,dy)]:
                        memo[(dx,dy)] = max(val,grid[dx][dy])
                        heapq.heappush(queue,(max(val,grid[dx][dy]),dx,dy))
                    else:
                        pass
        return 0

