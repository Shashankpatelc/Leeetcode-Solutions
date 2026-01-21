class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++ ) {
            int num = nums[i];
            int idx = 0;
            while( (num & 1) == 1 ) {
                idx++;
                num >>= 1;
            }
            if( nums[i] == 2 ) {
                res[i] = -1;
            } else {
                res[i] = nums[i] - (1 << (idx - 1));
            }
        }

        return res;
    }
};
