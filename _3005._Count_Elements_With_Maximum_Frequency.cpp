#include<unordered_map>

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        std::unordered_map<int,int> fre;
        int count= 0;
        int max_val;
        for(auto x:nums){
            fre[x] +=1;
        }
        for(auto &p : fre){
            if(p.second > max_val){
                max_val = p.second;
                count = 1;
            } else if(p.second == max_val){
                count++;
            }
        }
        return (max_val * count);
    }
};