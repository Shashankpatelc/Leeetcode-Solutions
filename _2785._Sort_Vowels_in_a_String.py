class Solution:
    def sortVowels(self, s: str) -> str:
        
        vov = []
        t = ""

        vov = [i for i in s if i in "aeiouAEIOU"]
        vov.sort(reverse=True)

        for i in s:

            if i in "aeiouAEIOU":
                t += vov.pop()
            else:
                t += i

        return t
                