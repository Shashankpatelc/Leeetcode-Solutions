#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while( num > 0 ){
            if( num & 1 ){
                num-=1;
            } else {
                num = num >> 1;
            }
            res++;
        }
        return res;
    }
};
