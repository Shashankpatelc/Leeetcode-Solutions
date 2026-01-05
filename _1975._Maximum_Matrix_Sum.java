class Solution {
    public long maxMatrixSum(int[][] matrix) {
        long neg = 0, sum = 0, neg_min = Integer.MAX_VALUE;
        
        for( int [] i : matrix ) {
            for( int j : i ) {
                if( j < 0 ) {
                    neg++;
                    j *= -1;
                }
                neg_min = j < neg_min ? j : neg_min;
                sum += j;                
            }
        }

        return ((neg & 1) == 0) ? sum : (sum - (neg_min) * 2);
    }
}