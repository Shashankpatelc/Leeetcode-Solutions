class Solution {
public:
    int minChanges(int n, int k) {
        int count = 0;

        if( n == k) return 0;
        
        if( k > n) return -1;

        while( n > 0){

            int n_val = n & 1;
            int k_val = k & 1;

            if( n_val == 0 && k_val == 1)
                return -1;

            else if( n_val != k_val ){
                n >>= 1;
                k >>= 1;
                count++;
            } else {
                n >>= 1;
                k >>= 1;
            }
        }
        return count++;
    }
};