from typing import List

MOD = 10**9 + 7

class Solution:
    def mod_pow(self, base: int, exp: int, mod: int) -> int:
        """Efficient modular exponentiation (base^exp % mod)"""
        result = 1
        base %= mod
        while exp:
            if exp & 1:
                result = result * base % mod
            base = base * base % mod
            exp >>= 1
        return result

    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        n = len(nums)

        # Precompute factorials and inverse factorials for multinomial coefficients
        factorial = [1] * (m + 1)
        for i in range(1, m + 1):
            factorial[i] = factorial[i - 1] * i % MOD

        inverse_factorial = [1] * (m + 1)
        inverse_factorial[1] = 1  # inverse of 1 is 1
        for i in range(2, m + 1):
            inverse_factorial[i] = self.mod_pow(i, MOD - 2, MOD)
        for i in range(2, m + 1):
            inverse_factorial[i] = inverse_factorial[i - 1] * inverse_factorial[i] % MOD

        # Precompute powers of each number up to m (so nums[i] ** cnt can be retrieved fast)
        powers = [[1] * (m + 1) for _ in range(n)]
        for i in range(n):
            for j in range(1, m + 1):
                powers[i][j] = powers[i][j - 1] * nums[i] % MOD

        # DP table: dp[pos][count][bitSum][carryCount]
        # pos: index in nums
        # count: how many elements used so far
        # bitSum: intermediate pseudo-binary sum (including carries)
        # carryCount: number of bits resolved during addition
        dp = [
            [[[0] * (k + 1) for _ in range(m * 2 + 1)]
             for _ in range(m + 1)]
            for _ in range(n)
        ]

        # Initialize first column in dp
        for used in range(m + 1):
            dp[0][used][used][0] = powers[0][used] * inverse_factorial[used] % MOD

        # Process each index in nums
        for i in range(n - 1):
            for used in range(m + 1):
                for bit_sum in range(m * 2 + 1):
                    for carries in range(k + 1):
                        curr = dp[i][used][bit_sum][carries]
                        if curr == 0:
                            continue

                        # Update carried bits
                        new_carries = carries + (bit_sum % 2)
                        if new_carries > k:
                            continue  # already too many bits

                        max_pick = m - used
                        for pick in range(max_pick + 1):
                            new_sum = (bit_sum // 2) + pick
                            if new_sum > m * 2:
                                continue

                            val = curr * powers[i + 1][pick] % MOD
                            val = val * inverse_factorial[pick] % MOD
                            dp[i + 1][used + pick][new_sum][new_carries] = (
                                dp[i + 1][used + pick][new_sum][new_carries] + val
                            ) % MOD

        # Final result: sum all valid states with exactly k bits in the final sum
        total = 0
        for final_sum in range(m * 2 + 1):
            for carried in range(k + 1):
                if bin(final_sum).count('1') + carried == k:
                    ways = dp[n - 1][m][final_sum][carried]
                    total = (total + ways * factorial[m]) % MOD

        return total


