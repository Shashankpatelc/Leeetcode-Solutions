from typing import List

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ans = max_num = streak = 0
        
        for n in nums:
            if n > max_num:
                max_num = n
                ans = streak = 0
            
            if n == max_num:
                streak += 1
            else:
                streak = 0
            
            ans = max(ans,streak)
        return ans
