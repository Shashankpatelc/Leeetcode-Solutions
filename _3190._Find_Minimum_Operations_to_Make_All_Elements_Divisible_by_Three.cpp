class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int steps = 0;
        for(auto &ele : nums){
            if(ele % 3 != 0){
                steps++;
            }
        }
        return steps;
    }
};