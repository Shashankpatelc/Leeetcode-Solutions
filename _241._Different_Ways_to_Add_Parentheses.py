from typing import List


class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        def way(exp,memo = {}):
            if exp in memo:
                return memo[exp]

            if exp.isdigit():
                memo[exp] = [int(exp)]
                return memo[exp]

            result = []
            for i,e in enumerate(exp):

                if e in '+-*':

                    left = way(exp[:i])
                    right = way(exp[i+1:])

                    for l in left:
                        for r in right:
                    
                            if e == '+':
                                result.append(l + r)
                            elif e == '-':
                                result.append(l - r)
                            elif e == '*':
                                result.append(l * r)
            
            memo[exp] = result
            return memo[exp]
        
        return way(expression)
                            
