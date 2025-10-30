from bisect import bisect_right
from typing import List


class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        memo = dict()
        ele = set()
        
        for i in power:
            if i not in ele:
                ele.add(i)
                memo[i] = 0
            memo[i]+=i

        sorted_power = sorted(ele)
        n = len(sorted_power)
        dp = [0]*n
        dp[0] = memo[sorted_power[0]]

        for i in range(1,n):
            skip = dp[i-1]
            take = memo[sorted_power[i]]
            j = bisect_right(sorted_power,sorted_power[i] - 3) - 1
            if j >= 0:
                take+=dp[j]
            dp[i] = max(take,skip)

        return dp[-1]
        