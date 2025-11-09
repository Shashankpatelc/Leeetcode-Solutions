class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odd = 0, even = 0,count = 0;
        while(n > 0){
            if((count & 1) == 0){
                even += (n & 1);
            }
            else {
                odd += (n & 1);
            }
            count++;
            n >>=1;
        }
        return {even,odd};
    }
};
