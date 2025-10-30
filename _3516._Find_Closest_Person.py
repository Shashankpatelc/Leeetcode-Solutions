class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        
        if x <= z and z <= y:
            if z - x == y - z:
                return 0 
            if z - x > y - z:
                return 2
            return 1
        elif z <= x and z <= y:
            if x - z == y - z:
                return 0
            if x - z > y - z:
                return 2
            return 1
        elif y <= z and z <= x:
            if x - z == z - y:
                return 0 
            if x - z > z - y:
                return 2
            return 1 
        elif x <= z and y <= z:
            if z - x == z - y:
                return 0
            if z - x > z - y:
                return 2
            return 1
        return 0
        