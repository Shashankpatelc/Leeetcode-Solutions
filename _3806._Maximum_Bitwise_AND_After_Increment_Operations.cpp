class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        
        long long ans = 0;
        
        for (int i = 30; i >= 0; --i) {
            long long target = ans | (1LL << i);
            vector<long long> costs;
            costs.reserve(nums.size());
            
            for (int val : nums) {
                long long x = val;
                
                if ((x & target) == target) {
                    costs.push_back(0);
                    continue;
                }
                
                long long diff = target & ~x;
                
                int msb = 63 - __builtin_clzll(diff);
                
                long long upper = ~((1LL << (msb + 1)) - 1);
                long long lower = (1LL << msb) - 1;
                
                long long y = (x & upper) | (1LL << msb) | (target & lower);
                
                costs.push_back(y - x);
            }
            
            nth_element(costs.begin(), costs.begin() + m, costs.end());
            
            long long current_cost = 0;
            for (int j = 0; j < m; ++j) {
                current_cost += costs[j];
            }
            
            if (current_cost <= k) {
                ans = target;
            }
        }
        
        return ans;
    }
};