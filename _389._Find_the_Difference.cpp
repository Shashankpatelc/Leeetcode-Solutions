#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;

        for( auto a : t)
            res ^= a;
        
        for( auto a : s)
            res ^= a;
        
        return res;
    }
};