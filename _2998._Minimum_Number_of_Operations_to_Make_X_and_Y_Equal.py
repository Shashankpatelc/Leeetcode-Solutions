from functools import lru_cache

class Solution:
    def minimumOperationsToMakeEqual(self, x: int, y: int) -> int:

        @lru_cache(None)
        def calc(curr: int) -> int:
            if curr == y:
                return 0
            if curr < y:
                # only way is to increment up to y
                return y - curr

            # fallback: decrement all the way to y (safe upper bound)
            best = curr - y

            # try making divisible by 11
            r11 = curr % 11
            if r11 == 0:
                best = min(best, 1 + calc(curr // 11))
            else:
                # subtract r11 to make divisible, then divide
                best = min(best, r11 + 1 + calc((curr - r11) // 11))
                # add (11 - r11) to make divisible, then divide
                best = min(best, (11 - r11) + 1 + calc((curr + (11 - r11)) // 11))

            # try making divisible by 5
            r5 = curr % 5
            if r5 == 0:
                best = min(best, 1 + calc(curr // 5))
            else:
                best = min(best, r5 + 1 + calc((curr - r5) // 5))
                best = min(best, (5 - r5) + 1 + calc((curr + (5 - r5)) // 5))

            return best

        return calc(x)

