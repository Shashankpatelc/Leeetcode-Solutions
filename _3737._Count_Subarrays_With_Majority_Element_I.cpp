class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n_target = count(nums.begin(), nums.end(), target);
        if( n_target == 0) {
            return 0;
        }
        int res = 0;
        for(int i = 0; i < nums.size(); i++ ) {
            int t_count = 0;
            for(int j = i; j < nums.size();  j++ ) {
                if( nums[j] == target) {
                    t_count++;
                }
                if( 2 * t_count > j - i + 1 && t_count > 0 ) {
                    res++;
                }
            }
        }
        return res;
    }
};