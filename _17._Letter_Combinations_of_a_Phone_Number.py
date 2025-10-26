from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        nums = {
            '2':['a','b','c'],
            '3':['d','e','f'],
            '4':['g','h','i'],
            '5':['j','k','l'],
            '6':['m','n','o'],
            '7':['p','q','r','s'],
            '8':['t','u','v'],
            '9':['w','x','y','z']
        }
        
        result = set()

        if len(digits) == 0:
            return []
        
        if len(digits) == 1:
            for i in nums[digits]:
                result.add(i)

        elif len(digits) == 2:
            for i in nums[digits[0]]:
                for j in nums[digits[1]]:
                    result.add(''.join(i+j))
                
        
        elif len(digits) == 3:
            for i in nums[digits[0]]:
                for j in nums[digits[1]]:
                    for k in nums[digits[2]]:
                        result.add(''.join(i+j+k))

        elif len(digits) == 4:
            for i in nums[digits[0]]:
                for j in nums[digits[1]]:
                    for k in nums[digits[2]]:
                        for l in nums[digits[3]]:
                            result.add(''.join(i+j+k+l))
        return list(result)
            