from typing import List


class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        area = 0
        for x in range(len(points) - 2):
            for y in range(x + 1, len(points) - 1):
                for z in range(y + 1, len(points)):
                    x1,y1 = points[x]
                    x2,y2 = points[y]
                    x3,y3 = points[z]

                    temp = 0.5 * abs(((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))))
                    area = max(area,temp)
        return area
                    