class Solution {
public:
    char kthCharacter(int k) {
        int len = 1;

        while( len < k ) len <<= 1;

        int shift = 0;
        
        while(len > 1){
        
            int half = len >> 1;
        
            if( k > half){
                shift++;
                k -= half;
            }
            len = half;
        }
        
        return char('a' + shift % 26);
    }
};