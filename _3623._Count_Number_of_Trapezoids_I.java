class Solution {
    public int countTrapezoids(int[][] points) {

        long M = 1000000007L;
        Map<Integer, Integer> ycount = new HashMap<>();
        long S = 0, Q = 0; 

        for(int[] p : points){
            int y = p[1];
            ycount.put(y, ycount.getOrDefault(y,0) + 1);
        }

        for(int count : ycount.values()){
            if(count > 1){
                long Ny = count;
                long cy = (Ny * (Ny - 1L)) / 2;
                
                S = (S + cy) % M;

                long cy_mod = cy % M;
                long cy_sq_mod = (cy_mod * cy_mod) % M;
                Q = (Q + cy_sq_mod) % M;
            }
        }
        
        long S_sq_mod = (S * S) % M; 
        
        long numerator = (S_sq_mod - Q + M) % M;

        long finalResult = (numerator * 500000004L) % M;

        return (int)finalResult;
    }
}