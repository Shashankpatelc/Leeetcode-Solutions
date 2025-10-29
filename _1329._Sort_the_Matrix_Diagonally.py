class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        x = len(mat)
        y = len(mat[0])

        temp = []
        for i in range(max(x,y)):
            # Downwards
            for j in range(min(x-i,y)):
                temp.append(mat[i+j][j])
            temp.sort()
            for j in range(min(x-i,y)):
                mat[i+j][j] = temp[j]
            temp.clear()

            if i <= 0:
                continue

            # Right Side
            for j in range(min(x,y-i)):
                temp.append(mat[j][j+i])
            temp.sort()
            for j in range(min(x,y-i)):
                mat[j][j+i] = temp[j]
            temp.clear()
        
        return mat