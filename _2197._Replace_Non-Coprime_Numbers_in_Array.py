import math

class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:

        stack = [nums[0]]
        
        for a in nums[1:]:
            while stack:
                g = gcd(stack[-1], a)
                if g == 1:
                    break
                b = stack.pop()
                a = (a * b) // g
            stack.append(a)

        return stack
        