class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int , int> map;
        vector <int> res;
        for(auto &a : nums1){
            map[a] |= 1;
        }

        for(auto &a : nums2){
            map[a] |= 2;
        }

        for(auto &a : nums3){
            map[a] |= 4;
        }

        for(auto [a,b] : map){
            if(__builtin_popcount(b) > 1){
                res.push_back(a);
            }
        }
        return res;
    }
};
