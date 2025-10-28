from typing import List


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:

        m = len(mat)
        n = len(mat[0])
        arr = []
        i = j = 0

        while i < m and j < n:
            arr.append(mat[i][j])
            if (i+j)%2 == 0:
                if j == n - 1:
                    i+=1
                elif i == 0:
                    j+=1
                else:
                    i-=1
                    j+=1
            else:
                if i == m - 1:
                    j+=1
                elif j == 0:
                    i+=1
                else:
                    j-=1
                    i+=1
        return arr
