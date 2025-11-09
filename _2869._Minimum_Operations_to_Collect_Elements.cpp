class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long target = (1LL << (k + 1)) - 2;
        long long mask = 0; 
        int count = 0;
        for (int i = nums.size() - 1; i>=0; i--){
            count++;
            if ( nums[i] <= k )
                mask |= (1LL << (nums[i]));
            if ( target == mask )
                return count;
        }
        return count;
    }
};
