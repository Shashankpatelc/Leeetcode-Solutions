from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        exist = set()
    
        for i in range(9):
            for j in range(9):
                val = board[i][j]
                if val == ".":
                    continue

                # Generate unique keys
                row_key = ("row", i, val)
                col_key = ("col", j, val)
                box_key = ("box", i // 3, j // 3, val)

                # Check for duplicates
                if row_key in exist or col_key in exist or box_key in exist:
                    return False

                # No duplicates, add the keys
                exist.add(row_key)
                exist.add(col_key)
                exist.add(box_key)

        return True

        