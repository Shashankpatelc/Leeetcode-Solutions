#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        long num = 0;
        for( auto b : nums){
            num = (num * 2 + b) % 5;
            if(num  == 0){
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }
        return res;
    }
};
