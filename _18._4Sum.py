from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        result = []
        nums.sort()

        i = 0
        while i < len(nums) - 3:
            if i > 0 and nums[i] == nums[i-1]:
                i+=1
                continue 

            j = i + 1
            while j < len(nums) - 2:
                if j > i + 1 and nums[j] == nums[j-1]:
                    j+=1
                    continue

                k = j + 1
                l = len(nums) - 1 
                while k < l:
                    if (nums[i] + nums[j] + nums[k] + nums[l]) == target:
                        result.append([nums[i], nums[j], nums[k], nums[l]])
                        k+=1
                        while nums[k] == nums[k-1] and k < l:
                            k+=1
                    elif (nums[i] + nums[j] + nums[k] + nums[l]) < target:
                        k+=1
                    elif (nums[i] + nums[j] + nums[k] + nums[l]) > target:
                        l-=1

                j+=1
            i+=1
        return result

