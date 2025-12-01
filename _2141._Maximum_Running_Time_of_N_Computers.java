class Solution {

    private boolean canrun(long T, int[] B,int N){
        long required_min = N * T;
        long totaltime = 0;
        for(int b : B){
            totaltime += Math.min((long)b,T);
        }
        return totaltime >= required_min;
    }

    public long maxRunTime(int n, int[] batteries) {
        long totalpower = 0;
        long maxtime = 0;

        for(int b : batteries){
            totalpower += b;
        }

        long L = 0;
        long R = totalpower / n;

        while(L <= R){
            long T = (L + R) / 2;
            if( canrun(T, batteries, n) ){
                maxtime = Math.max(T ,maxtime );
                L = T + 1;
            } else {
                R = T - 1;
            }
        }
        return maxtime;
    }
}