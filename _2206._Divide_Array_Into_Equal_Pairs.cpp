class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> s;
        for(auto &a : nums){
            if( s.find(a) != s.end()){
                s.erase(a);
            } else {
                s.insert(a);
            }
        }

        if(s.size() != 0){
            return false;
        }
        return true;
    }
};
