class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int [][] dp = new int[s2.length() + 1][s1.length() + 1];
        char[] charArray1 = s1.toCharArray();
        char[] charArray2 = s2.toCharArray();
        int i=0,j=0;
        
        dp[0][0] = 0;

        if( s1.length() > 0 )
            for( i = 0; i < s1.length(); i++ ) 
                dp[0][i+1] = charArray1[i] + dp[0][i];

        if( s2.length() > 0 )
            for(i = 0; i < s2.length(); i++ ) 
                dp[i+1][0] = charArray2[i] + dp[i][0];
        

        for( i = 1; i <= s2.length(); i++ ) {
            for( j = 1; j <= s1.length(); j++ ) {
                if( charArray2[i-1] == charArray1[j-1] ) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = Math.min(charArray2[i-1] + dp[i-1][j], charArray1[j-1] + dp[i][j-1]);
                }
            }
        }
        return dp[s2.length()][s1.length()];
    }
}