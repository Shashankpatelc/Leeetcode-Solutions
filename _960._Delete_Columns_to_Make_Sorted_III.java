class Solution {
    public int minDeletionSize(String[] strs) {
        int count = 0;

        if ( strs[0].length() == 0 ) return 0;

        int [] dp = new int[strs[0].length()];

        for( int i = 0; i < strs[0].length(); i++ ) {
            dp[i] = 1;
        
            for( int j = 0; j < i; j++){
                boolean canKeep = true;
        
                for( int k = 0; k < strs.length; k++){
        
                    if( !(strs[k].charAt(j) <= strs[k].charAt(i)) ){
                        canKeep = false;
                        break;
                    }
                }

                if( canKeep ){
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
            }
        }
        for( int i = 0; i < dp.length; i++){
            count = Math.max(count, dp[i]);
        }

        return strs[0].length() - count;
    }
}