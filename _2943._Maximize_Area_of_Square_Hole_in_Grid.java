class Solution {
    private int helper(int[] bars) {
        int count = 1, max_count = 1;

        for( int i = 1; i < bars.length; i++) {

            if( bars[i - 1] + 1 == bars[i] ) {
             
                count++;
            
            } else {
            
                count = 1;
            
            }
            
            max_count = Math.max(count, max_count);
        }

        return max_count + 1;
    }

    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {

        int side = 1;

        Arrays.sort(vBars);
        Arrays.sort(hBars);

        side = Math.min(helper(hBars), helper(vBars));

        return side*side;

    }
}