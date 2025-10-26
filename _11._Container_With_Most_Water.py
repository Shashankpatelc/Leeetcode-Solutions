from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:

        max_water = 0
        left = 0
        right = len(height)-1

        mini = min(height[left],height[right])
        if mini*(right - left) > max_water:
            max_water = mini*(right - left)
        
        while left < right:
            if height[left] < height[right]:
                left +=1
            else:
                right -=1
            mini = min(height[left],height[right])
            if mini*(right - left) > max_water:
                max_water = mini*(right - left)

        return max_water
