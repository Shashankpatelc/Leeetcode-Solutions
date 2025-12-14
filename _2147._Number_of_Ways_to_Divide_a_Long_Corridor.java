class Solution {
    public int numberOfWays(String corridor) {

        final int MOD = 1_000_000_007;
        int seatcount = 0;
        long res = 1;
        List<Integer> seatIndices = new ArrayList<>();
        
        for( int i = 0; i < corridor.length(); i++){
            if( corridor.charAt(i) == 'S' ){
                seatIndices.add(i);
                seatcount++;
            }
        }
        
        if( seatcount % 2 != 0 || seatcount == 0 ) return 0;
        
        for( int i = 1; i < seatcount-1; i+=2 ){
            int first = seatIndices.get(i);
            int second = seatIndices.get(i+1);
            long ways = second - first;
            res = ( res * ways ) % MOD;
        }

        return (int) res;
    }
}