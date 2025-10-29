class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        if 1 not in nums:
            return 0

        l = []
        j = 0

        for i in range(len(nums)):
            if nums[i] == 0:
                l.append(j)
                j = 0
                continue
            j+=1

        if j!=0: l.append(j)

        if len(l) == 1: return l[0]-1

        j = s = 0
        i = 1
        
        while i<len(l):
            if l[i]+l[j] >= s:
                s = l[i]+l[j]
            i+=1
            j+=1

        return s

        