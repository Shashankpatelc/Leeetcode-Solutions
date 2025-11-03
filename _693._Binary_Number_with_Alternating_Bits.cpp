#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long int res = n ^ (n >> 1);
        if ((res & (res + 1)) == 0){
            return true;
        }
        return false;
    }
};
