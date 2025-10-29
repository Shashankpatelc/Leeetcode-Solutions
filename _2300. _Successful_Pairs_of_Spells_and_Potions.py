import bisect

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        
        potions.sort()
        res = [ ]

        n = len(spells)
        m = len(potions)

        i = 0
        l = 0
        r = m - 1

        while i < n:

            if spells[i] * potions[0] >= success:
                res.append(m)
                i+=1
                continue
            
            if spells[i] * potions[m - 1] < success:
                res.append(0)
                i+=1
                continue

            mid = (l + r )// 2
            if (spells[i] * potions[mid] == success):
                idx = bisect.bisect_left(potions,potions[mid])
                res.append(m - idx)
                i+=1
                l = 0
                r = m - 1
                continue

            elif spells[i] * potions[mid - 1] < success and spells[i] * potions[mid] > success:
                res.append(m - mid)
                i+=1
                l = 0
                r = m - 1
                continue

            elif spells[i] * potions[mid + 1] > success and spells[i] * potions[mid] < success:
                res.append(m - (mid + 1))
                i+=1
                l = 0
                r = m - 1
                continue

            elif spells[i] * potions[mid] < success:
                l = mid + 1

            elif spells[i] * potions[mid] > success:
                r = mid 

        return res

