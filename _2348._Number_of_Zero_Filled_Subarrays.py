from typing import List


class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        if 0 not in nums:
            return 0
        count = 0
        ans = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                count += 1
            else:
                ans += count * (count + 1) // 2
                count = 0
        ans += count * (count + 1) // 2
        return ans