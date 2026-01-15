class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            long long current_sum = 0;
            unordered_set<long long> seen;
            
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                seen.insert(nums[j]);
                
                if (seen.count(current_sum)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};