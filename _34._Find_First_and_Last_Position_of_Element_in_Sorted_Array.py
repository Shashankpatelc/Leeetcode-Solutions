from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        res = []
        for i in range(len(nums)):
            if nums[i] == target:
                res.append(i)
                break

        for i in range(len(nums)-1,-1,-1):
            if nums[i] == target:
                res.append(i)
                break
                
        if res == []:
            return [-1,-1]
        return res