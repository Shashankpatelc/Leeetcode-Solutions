from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        arr = []            # Array to store the merged array

        # merge the 2 array while sorting
        i = j = 0           
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                arr.append(nums1[i])
                i+=1
            else:
                arr.append(nums2[j])
                j+=1

        # Add the remaining elements to the array
        arr.extend(nums1[i:])       
        arr.extend(nums2[j:])

        # Return the middle value
        l = len(arr)            # Length of the array
        if(l%2==0):
            return (arr[l//2]+arr[(l//2)-1])/2
        else:
            return (arr[l//2])
        
        