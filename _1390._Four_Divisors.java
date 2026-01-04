class Solution {
    public int sumFourDivisors(int[] nums) {
        int sum = 0, count = 0, current = 0;
        for (int i : nums) {
            count = 0;
            current = 0;
            for ( int j = 1; j * j <= i; j++ ) {
                if ( i % j == 0) {
                    current += j;
                    if ( j * j == i) {
                        count++;
                    } else {
                        current+= (i/j);
                        count+=2;
                    }
                } 

                if ( count > 4 )
                    break;
            }
            if ( count == 4 ) 
                sum += current;
        }
        return sum;
    }
}