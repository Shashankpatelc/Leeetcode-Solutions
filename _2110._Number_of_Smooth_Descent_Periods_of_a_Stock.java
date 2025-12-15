class Solution {
    public long getDescentPeriods(int[] prices) {
        long total = 0;
        long n = 1;
        for( int i = 0; i < prices.length-1; i++){
            if( prices[i] - prices[i+1] == 1 ){
                n++;
            } else {
                total += (n * ( n + 1 )) / 2;
                n = 1;
            }
        }
        total += (n * (n + 1)) / 2;
        return total;
    }
}