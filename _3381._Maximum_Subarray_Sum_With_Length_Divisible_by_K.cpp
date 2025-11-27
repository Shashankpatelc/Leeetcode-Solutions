#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        if (k <= 0) {
            return 0; 
        }

        long long max_sum = numeric_limits<long long>::min();

        long long current_prefix_sum = 0;

        const long long INF = numeric_limits<long long>::max();
        
        vector<long long> min_prefix_sum(k, INF); 

        min_prefix_sum[0] = 0;

        for (int j = 0; j < nums.size(); ++j) {
            
            current_prefix_sum += nums[j];

            int current_r = (j + 1) % k;

            long long min_start_p = min_prefix_sum[current_r];
            
            if (min_start_p != INF) {
                long long potential_sum = current_prefix_sum - min_start_p;
                
                max_sum = max(max_sum, potential_sum);
            }
            
            min_prefix_sum[current_r] = min(min_prefix_sum[current_r], current_prefix_sum);
        }
        
        return max_sum == numeric_limits<long long>::min() ? 0LL : max_sum; 
    }
};