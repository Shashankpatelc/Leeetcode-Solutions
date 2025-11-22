class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int res = 0;
        for(auto &ele : nums){
            if((ele & 1) == 0){
                res |= ele;
            }
        }
        return res;
    }
};