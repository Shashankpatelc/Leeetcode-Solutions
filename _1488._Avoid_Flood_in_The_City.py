import bisect

class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        lakes = set()
        res = []
        index = []
        last_rain = dict()
        count = 0

        for i in range(len(rains)):
            if rains[i] == 0:
                index.append(i)
                count+=1
                res.append(0)

            elif rains[i] in lakes:
                idx = bisect.bisect_right(index, last_rain[rains[i]])
                if idx >= len(index) or index[idx] > i:
                    return []
                res[index[idx]] = rains[i]
                last_rain[rains[i]] = i
                index.pop(idx)
                res.append(-1)
                count-=1
                
            else:
                last_rain[rains[i]] = i
                res.append(-1)
                lakes.add(rains[i])

        for i in index:
            res[i] = 1

        return res

