class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        vector<int> st;
        for( auto &ele : nums){

            while(!st.empty() && st.back() > ele){
                st.pop_back();
            }

            if(ele == 0) continue;

            if(st.empty() || st.back() < ele){
                st.push_back(ele);
                count++;
            }
        }
        return count;
    }
};
