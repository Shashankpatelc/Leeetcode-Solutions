from typing import List


class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        last = nums[0] - k
        count = 1

        for i in range(1,len(nums)):
            if nums[i] - k > last:
                nums[i]-=k
                last = nums[i]
                count+=1
            else:
                if nums[i] - k <= last + 1 <= nums[i] + k:
                    nums[i] = last + 1
                    last = nums[i]
                    count+=1
                else:
                    pass

        return count

