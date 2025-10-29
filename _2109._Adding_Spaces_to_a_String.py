class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:

        result = []     # used to store result in list 
        space = 0       # used to travel through spaces

        for s_i in range(len(s)):       # loop to travel through s tring

            if space < len(spaces) and s_i == spaces[space] :       #used to check the conditions

                result.append(" ")      #If the condition true add space to list
                space+=1        # Incremnt space by 1 

            result.append(s[s_i])       # Add string value to result list

        return "".join(result)      # Join all the result list and return it.