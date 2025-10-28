class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        s = sorted(str(n))
        for i in range(31):
            res = sorted(str(2**i))
            if res == s:
                return True
        return False
