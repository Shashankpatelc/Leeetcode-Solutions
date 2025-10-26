class Solution:
    def cal(self, ref, r, rom):

            if ref == 1:
                if r == 1:
                    return "I"
                elif r == 2:
                    return "II"
                elif r == 3:
                    return "III"
                elif r == 4:
                    return "IV"
                elif r == 5:
                    return "V"
                elif r == 6:
                    return "VI"
                elif r == 7:
                    return "VII"
                elif r == 8:
                    return "VIII"
                elif r == 9:
                    return "IX"
            elif ref == 2:
                if r == 1:
                    return "X"
                elif r == 2:
                    return "XX"
                elif r == 3:
                    return "XXX"
                elif r == 4:
                    return "XL"
                elif r == 5:
                    return "L"
                elif r == 6:
                    return "LX"
                elif r == 7:
                    return  "LXX"
                elif r == 8:
                    return "LXXX"
                elif r == 9:
                    return "XC"
            elif ref == 3:
                if r == 1:
                    return "C"
                elif r == 2:
                    return "CC"
                elif r == 3:
                    return "CCC"
                elif r == 4:
                    return "CD"
                elif r == 5:
                    return "D"
                elif r == 6:
                    return "DC"
                elif r == 7:
                    return "DCC"
                elif r == 8:
                    return "DCCC"
                elif r == 9:
                    return "CM"
            elif ref == 4:
                if r == 1:
                    return "M"
                elif r == 2:
                    return "MM"
                elif r == 3:
                    return "MMM"
            return ""

    def intToRoman(self, num: int) -> str:
        n = num
        ref = 1
        rom = ""
        while num > 0:
    
            r = num % 10
            num = int(num / 10)
            rom = self.cal(ref,r,rom) + rom
            ref = ref + 1
            
        return rom