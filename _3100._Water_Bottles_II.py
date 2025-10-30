class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        empty = numBottles
        drunk = numBottles
        
        while empty >= numExchange:
            empty-=numExchange
            numExchange+=1
            drunk += 1
            empty += 1
    
        return drunk
        