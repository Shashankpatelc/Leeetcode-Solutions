class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> map;
        int xor_val = 0;
        for(auto &a : nums){
            map[a]++;
            if(map[a] > 1){
                xor_val ^= a;
            }
        }
        return xor_val;
    }
};