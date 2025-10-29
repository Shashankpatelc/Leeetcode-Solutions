class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        
        if len(s) == 0:
            return 0
                
        temp_s = ""
        n = len(s)

        for i in range( n - 1, -1, -1):
            if int(s[i] + temp_s, 2) <= k:
                temp_s = s[i] + temp_s
            else:
                pass
        
        return len(temp_s)
        