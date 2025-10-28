from typing import List


class Solution:          
    
    def sortArray(self, nums: List[int]) -> List[int]:
        def mergesort(self,nums):
            if len(nums) > 1:
            
                mid = len(nums)//2
                left = nums[:mid]
                right = nums[mid:]
            
                mergesort(self,left)
                mergesort(self,right)
            
                i = j = k = 0
                while i < len(left) and j < len(right):
                    if left[i] < right[j]:
                        nums[k] = left[i]
                        i+=1
                    else:
                        nums[k] = right[j]
                        j+=1
                    k+=1
            
                while i < len(left):
                    nums[k] = left[i]
                    k+=1
                    i+=1
            
                while j < len(right):
                    nums[k] = right[j]
                    j+=1
                    k+=1
        mergesort(self,nums)
        return nums
             