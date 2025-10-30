from typing import List
import numpy as np

class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        arr = np.array(grid)
        # left -> right
        for j in range(len(grid[0])):
            if 1 in arr[:,j]:
                break
        
        # right -> left
        for l in range(len(grid[0])-1,-1,-1):
            if 1 in arr[:,l]:
                l+=1
                break
        
        # up -> down
        for i in range(len(grid)):
            if 1 in grid[i]:
                break
        
        # down -> up
        for k in range(len(grid)-1,-1,-1):
            if 1 in grid[k]:
                k+=1
                break
        
        row = i - k
        col = j - l

        return row*col

        