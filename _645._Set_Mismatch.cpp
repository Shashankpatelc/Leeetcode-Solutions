#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xor_val = 0, bit_diff, g1 = 0, g2 = 0;

        for (int i = 1; i <= nums.size(); i++)
            xor_val^=i;
        
        for (auto a : nums)
            xor_val^=a;
        
        bit_diff = xor_val & (~xor_val + 1);
        
        for (int i = 1; i <= nums.size(); i++)
            if (i & bit_diff)   g1^=i;
            else    g2^=i;
        
        for (auto a : nums)
            if (a & bit_diff)   g1^=a;
            else    g2^=a;
        
        for (auto a : nums) 
            if (a == g1) return {g1, g2};  

        return {g2, g1};  
    }
};
