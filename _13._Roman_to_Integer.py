class Solution:

    def romanToInt(self, s: str) -> int:
        num = 0
        pre = {
            'I' : 1,
            'V' : 5,
            'X' : 10,
            'L' : 50,
            'C' : 100,
            'D' : 500,
            'M' : 1000
        }
        for i in range(len(s)):
            a = pre[s[i]]
            if i < len(s) - 1 :
                if pre[s[i]] < pre[s[i+1]]:
                    num = num - a
                else:
                    num = num + a
            else:
                num = num + a
        return num