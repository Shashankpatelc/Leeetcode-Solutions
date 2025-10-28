from collections import deque
from typing import List

class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        state = "".join(str(j) for i in board for j in i)
        target = "123450"

        nib = {
            0: [1, 3],
            1: [0, 2, 4],
            2: [1, 5],
            3: [0, 4],
            4: [1, 3, 5],
            5: [2, 4]
        }

        queue = deque([(state,0)])
        visited = set()
        visited.add(state)

        while queue:
            state,step = queue.popleft()
            if state == target:
                return step
            
            zero = state.index('0')
            for n in nib[zero]:
                new_state = list(state)
                new_state[n],new_state[zero] = new_state[zero],new_state[n]
                new_state = ''.join(new_state)

                if new_state not in visited:
                    visited.add(new_state)
                    queue.append((new_state,step + 1))

        return -1

            