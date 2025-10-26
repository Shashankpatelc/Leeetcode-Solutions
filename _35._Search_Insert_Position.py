from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:

        if nums[-1] < target:
            return len(nums)

        for i in nums:
            if i == target or i > target:
                return nums.index(i)
        return 0


        