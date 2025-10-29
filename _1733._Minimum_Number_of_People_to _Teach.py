class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:

        def check(u1,u2):
            if len(users[u1] & users[u2]) > 0:
                return False
            return True

        users = { }
        for i in range(len(languages)):
            users[i+1] = set(languages[i])


        broken = set()
        for i in friendships:
            if check(i[0],i[1]):
                broken.add(i[0])
                broken.add(i[1])
        
        ans = float('Inf')
        for i in range(1,n+1):
            count = 0   
            for p in broken:
                if i in users[p]:
                    count+=1
            ans = min(ans,len(broken) - count)

        return ans

