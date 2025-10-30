from typing import List


class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        count = 0
        for A in range(len(points)):
            for B in range(len(points)):
                if A == B:
                    continue
                Ax,Ay = points[A]
                Bx,By = points[B]
                if Ax <= Bx and (Ay >= By ):
                    valid = True
                    for C in range(len(points)):
                        if C == A or C == B:
                            continue
                        Cx,Cy = points[C]
                        if Ax <= Cx <= Bx and Ay >= Cy >= By:
                            valid = False
                            break
                    if valid:
                        print(points[A],points[B])
                        count+=1
        return count
        