class Solution {
    static long fact(int n){
        long res = 1;
        while(n > 1){
            res = ((res) % 1_000_000_007L) * n;
            n--;
        }
        return res % 1_000_000_007L;
    }
    public int countPermutations(int[] complexity) {
        int min_val = complexity[0];
        for(int i = 1; i < complexity.length; i++){
            if(complexity[i] <= min_val){
                return 0;
            }
        }
        return (int)fact(complexity.length - 1);
    }
}