from typing import List


class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        count = 0
        nums.sort()
        n = len(nums)

        # Skip leading zeros as they can't form valid triangle sides
        start = 0
        while start < n and nums[start] == 0:
            start+=1

        for k in range(start + 2,n):
            l = 0
            r = k - 1
            while l < r:
                if nums[l] + nums[r] > nums[k]:
                    count += r - l
                    r-=1
                else:
                    l+=1

        return count

