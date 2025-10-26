from typing import List

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        # Initialize sets to keep track of numbers used in rows, columns, and boxes
        rows_used = [set() for _ in range(9)]
        cols_used = [set() for _ in range(9)]
        boxes_used = [set() for _ in range(9)]

        # Pre-fill sets with initial board values
        for r in range(9):
            for c in range(9):
                if board[r][c] != '.':
                    ch = board[r][c]
                    rows_used[r].add(ch)
                    cols_used[c].add(ch)
                    box_index = (r // 3) * 3 + (c // 3)
                    boxes_used[box_index].add(ch)

        def backtrack():
            # Find empty cell with minimum candidates (MRV)
            min_candidates = 10
            cell = None
            for r in range(9):
                for c in range(9):
                    if board[r][c] == '.':
                        box_index = (r // 3) * 3 + (c // 3)
                        candidates = [ch for ch in map(str, range(1, 10))
                                      if ch not in rows_used[r]
                                      and ch not in cols_used[c]
                                      and ch not in boxes_used[box_index]]
                        if len(candidates) < min_candidates:
                            min_candidates = len(candidates)
                            cell = (r, c)
                        if min_candidates == 1:  # can't do better than 1
                            break
                if min_candidates == 1:
                    break

            # If no empty cell found, puzzle is solved
            if cell is None:
                return True

            r, c = cell
            box_index = (r // 3) * 3 + (c // 3)
            for ch in [ch for ch in map(str, range(1, 10))
                       if ch not in rows_used[r]
                       and ch not in cols_used[c]
                       and ch not in boxes_used[box_index]]:
                # Place the number
                board[r][c] = ch
                rows_used[r].add(ch)
                cols_used[c].add(ch)
                boxes_used[box_index].add(ch)

                if backtrack():
                    return True

                # Backtrack
                board[r][c] = '.'
                rows_used[r].remove(ch)
                cols_used[c].remove(ch)
                boxes_used[box_index].remove(ch)

            return False

        backtrack()
