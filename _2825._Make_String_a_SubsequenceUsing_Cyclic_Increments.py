class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        if len(str2) > len(str1):
            return False
            
        i = j = 0
        while i < len(str1) and j < len(str2):
            if str1[i] == str2[j] or ord(str1[i])+1 == ord(str2[j]) or (str1[i] == 'z' and 'a' == str2[j]):
                j+=1
                i+=1
            else:
                i+=1
        
        if len(str2) == j:
            return True
        return False
      