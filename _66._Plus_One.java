class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        int [] res = new int[len+1];
        int rem = 1;

        for(int i = len - 1; i > -1; i--) {
            digits[i]+=rem;
            rem = 0;
            if(digits[i] >= 10) {
                digits[i] = 0;
                rem = 1;
            }
            res[i+1] = digits[i];
        }
        if(rem == 0) {
            return digits;
        }
        res[0] = 1;
        return res;
    }
}