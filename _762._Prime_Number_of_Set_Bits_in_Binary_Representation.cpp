#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        int bitmask = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19);
        for( int i = left; i < right+1; i++){
            if(bitmask & (1 << __builtin_popcount(i) )){
                count++;
            }
        }
        return count;
    }
};
