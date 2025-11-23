class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> v[3];
        
        for(auto &ele : nums){
            sum += ele;
            v[ele % 3].push_back(ele);
        }
        
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());

        int remove = INT_MAX;

        if( sum % 3 == 0){
            remove = 0;
        } else if ( sum % 3 == 1 ) {
            if( v[1].size() >= 1 ){
                remove = min(remove, v[1].end()[-1]);
            }
            if( v[2].size() >= 2 ){
                remove = min(remove, (v[2].end()[-2]) + (v[2].end()[-1]));
            }
        } else {
            if( v[1].size() >= 2 ){
                remove = min(remove, (v[1].end()[-2]) + (v[1].end()[-1]));
            }
            if( v[2].size() >= 1 ){
                remove = min(remove, (v[2].end()[-1]));
            }
        }

        return sum - remove;
    }
};