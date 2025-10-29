class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        count = 0
        ch = ch1 = 0
        if x > y:
            first = "a"
            second = "b"
            fs = x
            ss = y
        else:
            first = "b"
            second = "a"
            fs = y
            ss = x
        
        for i in s:
        
            if i == first:
                ch+=1
        
            elif i == second:
        
                if ch > 0:
                    ch-=1
                    count+=fs
        
                else:
                    ch1+=1
        
            else:
                count+=min(ch,ch1)*ss
                ch = ch1 =0
        
        if ch != 0 and ch1 != 0:
            count+= min(ch,ch1)*ss
        
        return count
        
        