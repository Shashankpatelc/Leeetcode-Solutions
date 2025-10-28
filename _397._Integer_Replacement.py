class Solution:
    def integerReplacement(self, n: int) -> int:
        def calc(target,memo={}):
            if target in memo:
                return memo[target]
            if target == 1:
                return 0
            if target % 2 == 0:
                memo[target] = 1 + calc(target // 2,memo)
                return memo[target]
            else:
                memo[target] = 1 + min(calc(target - 1,memo),calc(target + 1,memo))
                return memo[target]
        return calc(n)
        