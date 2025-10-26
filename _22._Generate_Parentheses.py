class Solution:
    def generateParenthesis(self, n):
        res = []

        def back(openP, closeP, s):
            if openP == closeP and openP + closeP == n * 2:
                res.append(s)
                return
            
            if openP < n:
                back(openP + 1, closeP, s + "(")
            
            if closeP < openP:
                back(openP, closeP + 1, s + ")")

        back(0, 0, "")

        return res
