from collections import deque
from collections import defaultdict
from bisect import bisect_left, bisect_right
from typing import List

class Router:

    def __init__(self, memoryLimit: int):
        self.routersize = memoryLimit
        self.router = deque()
        self.byDest = defaultdict(list)
        self.seen = set()

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        if (source, destination, timestamp) in self.seen:
            return False

        if len(self.router) == self.routersize:
            packet = self.router.popleft()    
            self.seen.remove((packet[0],packet[1],packet[2]))
            self.byDest[packet[1]].pop(0) 

        self.router.append([source, destination, timestamp])
        self.seen.add((source, destination, timestamp))
        self.byDest[destination].append(timestamp)

        return True


    def forwardPacket(self) -> List[int]:
        if len(self.router) <= 0:
            return []

        packet = self.router.popleft()
        self.seen.remove((packet[0],packet[1],packet[2]))
        self.byDest[packet[1]].pop(0)

        return packet
         

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        timestamps = self.byDest.get(destination, [])
        left = bisect_left(timestamps, startTime)
        right = bisect_right(timestamps, endTime)

        return right - left

# Your Router object will be instantiated and called as such:
# obj = Router(memoryLimit)
# param_1 = obj.addPacket(source,destination,timestamp)
# param_2 = obj.forwardPacket()
# param_3 = obj.getCount(destination,startTime,endTime)

