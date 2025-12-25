class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long wanted = happiness.length - k, max_happi = 0, count = 0;

        for( int i = happiness.length-1; i >= wanted; i--){
            long happy = happiness[i] - count;
        
            if( happy <= 0 ){
                break;
            }
        
            max_happi += happy;
            count++;
        }
        
        return max_happi;
    }
}