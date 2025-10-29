from typing import List

class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        mod = 10**9 + 7
        powers = []
        pow = 1
        while pow <= n:
            pow *= 2

        while n > 0:
            if n >= pow:
                n -= pow
                powers.append(pow)
            pow //= 2

        powers.sort()
        result = []
        for i in queries:
            temp = 1
            for j in range(i[0],i[1]+1):
                temp = (temp * powers[j]) % mod
            result.append(temp)
        
        return result
