class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        nums = [i for i in range(1,maxChoosableInteger+1)]

        if desiredTotal <= 0:
                return True
        if sum(nums) < desiredTotal:
                return False
                
        memo = {}
        
        def calc(target,rem_nums):
            key = tuple(rem_nums)
            if key in memo:
                return memo[key]

            if target <= 0:
                return False

            for i in rem_nums:

                new_nums = rem_nums[:]
                new_nums.remove(i)
                rem = target - i

                if rem <= 0:
                    memo[key] = True
                    return True
                
                if not calc(rem,new_nums):
                    memo[key] = True
                    return True
            memo[key] = False
            return False

        return calc(desiredTotal,nums)
            
        