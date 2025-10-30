class Solution:
    def maxFreqSum(self, s: str) -> int:
        vov = dict()
        cons = dict()

        for i in s:
            if i in 'aeiou':
                if i in vov.keys():
                    vov[i] += 1
                else:
                    vov[i] = 1
            else:
                if i in cons.keys():
                    cons[i]+=1
                else:
                    cons[i] = 1

        return max(vov.values() if vov.values() else [0]) + max(cons.values() if cons.values() else [0])