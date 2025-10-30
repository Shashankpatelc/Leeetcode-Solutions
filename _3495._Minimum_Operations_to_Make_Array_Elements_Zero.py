from math import log, ceil

class Solution:
    def minOperations(self, queries):
        total_steps = 0
        
        for l, r in queries:
            steps = 0
            current = 1
            step_count = 1
            
            while current <= r:
                next_val = current * 4
                # Count overlap of this step range with [l, r]
                start = max(current, l)
                end = min(next_val - 1, r)
                if start <= end:
                    steps += (end - start + 1) * step_count
                current = next_val
                step_count += 1
            
            # Each operation reduces 2 numbers
            total_steps += ceil(steps / 2)
        
        return total_steps