import heapq

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        max_heap = []
        push, pop = heapq.heappush, heapq.heappop

        # Build heap
        for p, t in classes:
            delta = (p + 1) / (t + 1) - (p / t)
            push(max_heap, (-delta, p, t))

        # Assign extra students
        for _ in range(extraStudents):
            delta, p, t = pop(max_heap)
            p, t = p + 1, t + 1
            new_delta = (p + 1) / (t + 1) - (p / t)
            push(max_heap, (-new_delta, p, t))

        # Compute final average directly
        avg = sum(p / t for _, p, t in max_heap)
        return avg / len(classes)

