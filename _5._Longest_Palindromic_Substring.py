class Solution:
    def longestPalindrome(self, s: str) -> str:

        # check the string is empty or not

        if s == "" or len(s) == 1:
            return s
        
        # fun is used to find the Palindrome string

        def fun(left,right):
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right +=1
            return s[left+1:right]
        
        string = s[0]               # used to store the largest string

        # used to find largest Palindrome string and also for passing argument ro fun method

        for i in range(len(s)):
            
            odd = fun(i,i)
            even = fun(i,i+1)

            if len(odd) > len(string):
                string = odd
            if len(even) > len(string):
                string = even
        # return the largest string        

        return string

