
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = [int(x) for x in version1.split('.')]
        v2 = [int(x) for x in version2.split('.')]
        
        # Pad shorter array to match longer one
        max_len = max(len(v1), len(v2))
        v1.extend([0] * (max_len - len(v1)))
        v2.extend([0] * (max_len - len(v2)))
        
        # Compare element by element
        for i in range(len(v1)):
            if v1[i] < v2[i]:
                return -1
            if v1[i] > v2[i]:
                return 1
        return 0
