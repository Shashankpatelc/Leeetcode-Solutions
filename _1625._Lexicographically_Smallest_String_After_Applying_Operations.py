from collections import deque

class Solution:

    def add_odd(self,s: str,a: int):
        chars = list(s)

        for i in range(1, len(chars), 2):
            chars[i] = str((int(chars[i]) + a) % 10)
        return ''.join(chars)

    def rotate(self,s: str,i: int):
        return s[-i:] + s[:-i]

    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        q = deque()
        visited = set()
        q.append(s)
        visited.add(s)

        while q:

            string = q.pop()

            str1 = self.add_odd(string,a)
            if str1 not in visited:
                q.append(str1)
                visited.add(str1)

            str1 = self.rotate(string,b)
            if str1 not in visited:
                q.append(str1)
                visited.add(str1)

        return min(visited)
        