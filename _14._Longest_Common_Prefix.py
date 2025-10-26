from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        if not strs:
            return ""

        pre = temp = ""

        for i in strs[0]:
            temp = temp + i
            if all(j.startswith(temp) for j in strs):
                pre = temp
            else:
                break
        return pre


        


        