class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int min_val = INT_MAX;

        if ( nums.size() < k) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        for ( int i = 0; i <= nums.size() - k; i++) {
            int start = nums[i];
            int last = nums[i + k - 1];
            min_val = min(min_val, last - start);
        }

        return min_val;
    }
};