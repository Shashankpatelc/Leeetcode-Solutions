from typing import List


class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        if sum(nums)%k != 0:
            return False
        target = sum(nums)//k

        def backtrack(index,bucket):
            if index == len(nums):
                return all(b == target for b in bucket)
            
            for i in range(k):
                if bucket[i] + nums[index] > target:
                    continue
                bucket[i]+=nums[index]
                if backtrack(index+1,bucket):
                    return True
                bucket[i]-=nums[index]

                if bucket[i] == 0:
                    break
            return False

        nums.sort(reverse=True)
        bucket = [0] * k
        return backtrack(0,bucket)
