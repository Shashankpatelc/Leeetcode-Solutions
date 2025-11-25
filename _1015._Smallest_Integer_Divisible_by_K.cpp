class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int res = 1 % k, count = 1;

        if( k % 5 == 0 || k % 2 == 0 )
            return -1;

        while( res != 0){
            res = (res * 10 + 1) % k;
            count++;
        }
        
        return count;
    }
};