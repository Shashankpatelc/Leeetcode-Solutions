class Solution:
    def climb(self,n,a,way,memo):
        if n in memo:
            return memo[n]
        if n == 0:
            return 1
        if n < 0:
            return 0
        for i in a:
            rem = n - i
            way += self.climb(rem,a,way,memo)
            memo[rem] = way
        return way


    def climbStairs(self, n: int) -> int:
        return self.climb(n,[1,2],0,memo=dict())
        