class Solution:
    def calc(self, s: str):
        temp = ''
        for i in range(len(s) - 1):
            num = (int(s[i]) + int(s[i+1])) % 10
            temp+=str(num)
        return temp

    def hasSameDigits(self, s: str) -> bool:

        while len(s) > 2:
            s = self.calc(s)

        
        return s[0] == s[-1]
        