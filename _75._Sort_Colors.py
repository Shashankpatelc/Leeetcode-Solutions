from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)-1):
            min = i
            for j in range(i+1,len(nums)):
                if nums[j] < nums[min]:
                    min = j
            nums[min],nums[i] = nums[i],nums[min]
            