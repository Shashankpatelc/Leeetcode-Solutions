class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for( auto &ele : nums){
            if((ele & 1) == 0 ){
                res.push_back(-1);
            } else {
                int n = 1;
                while( n  <= ele){
                    if((n | n + 1) == ele){
                        res.push_back(n);
                        break;
                    }
                    n++;
                }
            }
        }
        return res;
    }
};