class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int l1 = nums1.length;
        int l2 = nums2.length;
        int min_len = Math.min(l1, l2);

        int[][] dp = new int[l1 + 1][l2 + 1];

        for( int i = 0; i <= l1; i++ ) {
            dp[i][0] = -50000000;     
        }
        for( int i = 0; i <= l2; i++ ) {
            dp[0][i] = -50000000;     
        }


        for( int i = 1; i <= l1; i++ ) {
            for( int j = 1; j <= l2; j++) {
                int tak = nums1[i-1] * nums2[j-1];
                int cur = Math.max( (tak + dp[i-1][j-1]), tak);
                int skip = Math.max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = Math.max( cur, skip );
            }
        }

        return dp[l1][l2];
    }
}