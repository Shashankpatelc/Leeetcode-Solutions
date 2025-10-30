from typing import List


class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        for i in range(0,n-2*k+1):

            if all(nums[j] < nums[j+1] for j in range(i,i+k-1)) and all(nums[j] < nums[j+1] for j in range(i+k,i+2*k-1)):
                return True

        return False

