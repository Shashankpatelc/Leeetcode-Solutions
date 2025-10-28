#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n ; i++){
            bitset<20> b(i);
            res.push_back(b.count());
        }
        return res;
    }
};