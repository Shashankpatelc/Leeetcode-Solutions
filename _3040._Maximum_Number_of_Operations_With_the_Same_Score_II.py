from typing import List


class Solution:
    def check(self,s ,r ,nums, presum, memo):
        max_len = 0
        if s >= r:
            return 0

        if memo[s][r] != 0:
            return memo[s][r]
        
        if nums[s] + nums[s+1] == presum:
            max_len = max(max_len, self.check(s + 2 ,r ,nums, presum, memo)+1)

        if nums[s] + nums[r] == presum:
            max_len = max(max_len, self.check(s + 1 ,r - 1 ,nums, presum, memo)+1)

        if nums[r] + nums[r - 1] == presum:
            max_len = max(max_len, self.check(s ,r - 2 ,nums, presum, memo)+1)

        memo[s][r] = max_len
        return memo[s][r]
        
    def maxOperations(self, nums: List[int]) -> int:
        start = 0
        maxoperation = 0
        length = len(nums)
        end = length - 1
        memo = [[0] * length for _ in range(length)]

        maxoperation = max(maxoperation, self.check(start + 2, end, nums, nums[start] + nums[start + 1],memo)+1)

        maxoperation = max(maxoperation, self.check(start, end - 2, nums, nums[end] + nums[end - 1],memo)+1)

        maxoperation = max(maxoperation, self.check(start + 1, end - 1, nums, nums[start] + nums[end],memo)+1)

        return maxoperation

