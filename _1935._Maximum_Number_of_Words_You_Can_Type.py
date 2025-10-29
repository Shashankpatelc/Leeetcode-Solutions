class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        res = 0
        text = text.split()

        for i in text:
            check = True

            for j in brokenLetters:

                if j in i:
                    check = False
                    break

            if check:
                res+=1

        return res
        