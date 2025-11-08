class Solution {
public:
    int similarPairs(vector<string>& words) {
        int count = 0;
        vector<int> v;
        for(auto &a : words){
            int mask = 0;
            for( auto &ele : a){
                mask |= (1 << (ele - 'a'));
            }
            v.push_back(mask);
        }

        for (int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size(); j++){
                if(v[i] == v[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
