class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        dp = [0 for _ in range(n+1)]
        dp[1] = 1
        mod = 10**9 + 7
        for i in range(1,(n+1)):
            for days in range(i+delay, min(n,i + forget - 1) + 1):
                dp[days] += dp[i]
        return sum(dp[n - forget + 1:n + 1]) % mod


