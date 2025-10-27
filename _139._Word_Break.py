from typing import List


class Solution:
        
    def wordBreak(self, s: str, word: List[str]) -> bool:
        word = set(word)
        memo = {}

        def comb(start):
            if start in memo:
                return memo[start]
            if start == len(s):
                return True
            if start > len(s):
                return False
            for end in range(start+1,len(s)+1):
                if s[start:end] in word:
                    if comb(end):
                        memo[start] = True
                        return memo[start]
            memo[start] = False
            return memo[start]

        return comb(0)
    
        