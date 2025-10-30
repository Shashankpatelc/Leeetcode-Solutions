from typing import List


class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        n = len(energy)
        dp = [0]*n
        for i in range(n-1,-1,-1):
            dp[i] += energy[i]
            if i-k >= 0:
                dp[i-k] = dp[i-k]+dp[i]

        return max(dp)
        