class Solution:
    def reverse(self, x: int) -> int:
        # for negitive value
        if x < 0:
            res = int(str(x*-1)[::-1])*-1
        # for positive value
        else:
            res = int(str(x)[::-1])
        # check res is 32 bit int or not
        if res > 2147483647 or res < -2147483648:
            return 0
        # return res if it is a 32 bit int
        return res
