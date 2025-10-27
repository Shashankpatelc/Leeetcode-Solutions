class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"

        is_neg = (numerator < 0) ^ (denominator < 0)

        numerator, denominator = abs(numerator), abs(denominator)

        integer = numerator // denominator
        rem = numerator % denominator

        rem_table = dict()
        dec_str = ''
        pos = 0

        while rem != 0:
            if rem in rem_table:
                dec_str = dec_str[0:rem_table[rem]] + '(' + dec_str[rem_table[rem]:] + ')' 
                break
                
            rem_table[rem] = pos
            rem*=10
            digit = rem // denominator
            rem = rem % denominator

            dec_str+=str(digit)
            pos+=1

        if dec_str == '':
            res = str(integer)
        else:
            res = str(integer) + '.' + dec_str
        
        if is_neg:
            res = '-' + res

        return res

