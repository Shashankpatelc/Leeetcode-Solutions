class Solution:

    def getKth(self, lo: int, hi: int, k: int) -> int:
        memo = {}

        def reduse(x):

            if x in memo:
                return memo[x]

            elif x == 1:
                memo[x] = 0
                return 0

            elif x % 2 == 0:
                memo[x] = 1 + reduse(x//2)

            else:

                memo[x] = 1 + reduse(3 * x + 1)
                
            return memo[x]


        def calc(lo,hi):

            steps = []

            for i in range(lo,hi+1):
                res = reduse(i)
                steps.append((i,res))

            steps.sort(key = lambda x: (x[1], x[0]))
            return steps[k-1][0]

        return calc(lo,hi)
        