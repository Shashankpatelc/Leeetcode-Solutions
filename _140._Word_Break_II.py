from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        # memo = {}
        
        def calc(st):
            res = []
            # if st in memo:
            #     return memo[st]

            if len(st) <= 0:
                return [""]
            
            for j in range(len(st)+1):
                if st[:j] in wordDict:
                    for word in calc(st[j:]):
                        if word:
                            res.append(st[:j] + " " + word)
                        else:
                            res.append(st[:])

            # memo[st[:j]] = res
            return res

        return calc(s)

