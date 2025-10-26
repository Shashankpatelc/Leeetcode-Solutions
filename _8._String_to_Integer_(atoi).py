class Solution:
    def myAtoi(self, s: str) -> int:
        res = 0
        i = 0
        neg = False
        if s == "":
            return 0
        while i < len(s) and s[i] == ' ':
            i+=1

        if i < len(s) and s[i] == '-':
            neg = True
            i+=1

        elif i <len(s) and s[i] == '+' :
            i+=1

        while i < len(s):
            if s[i].isdigit():
                res = (res * 10) + int(s[i])
                i+=1
            else:
                break
        if neg:
            res = res * -1
        if res > 2147483647:
            res = 2147483647
        if res < -2147483648:
            res = -2147483648
        return res

        