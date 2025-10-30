from typing import List


class Solution:
    def maxSum(self, nums: List[int]) -> int:
        if max(nums) < 0:
            return max(nums)
        else:
            return sum(set(x if x > 0 else 0 for x in nums))
        