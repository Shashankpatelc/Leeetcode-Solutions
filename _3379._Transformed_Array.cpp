class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        
        int new_idx = 0;
        int len = nums.size();
        vector<int> result(len, 0);
        
        for( int i = 0; i < len; i++ ) {

            new_idx = ((i + nums[i]) % len + len) % len;
            result[i] = nums[new_idx];
            
        }

        return result;
    }
};