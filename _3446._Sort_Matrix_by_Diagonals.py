from typing import List


class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        temp = []
        for i in range(n):
            # Downwards
            for j in range(i,n):
                temp.append(grid[j][j-i])
            temp.sort(reverse=True)
            for j in range(i,n):
                grid[j][j-i] = temp[j-i]
            temp.clear()

            if i <= 0:
                continue

            # Right Side
            for j in range(0,n-i):
                temp.append(grid[j][j+i])
            temp.sort()
            for j in range(0,n-i):
                grid[j][j+i] = temp[j]
            temp.clear()

        return grid