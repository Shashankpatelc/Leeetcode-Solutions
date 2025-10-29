#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map <int,int> memo;

        for(auto a: nums){
            int rem = ((a % value) + value) % value;
            memo[rem]++;
        }

        int target = 0;
        for(;;){
            int rem = target % value;
            if(memo[rem] == 0) return target;
            memo[rem]--;
            target++;
        }
    }
};
