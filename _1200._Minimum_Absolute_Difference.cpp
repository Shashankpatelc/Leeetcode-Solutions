class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int min_val = INT_MAX;
        vector<vector<int>> res;

        sort(arr.begin(), arr.end());
        
        for( int i = 0, j = 1; j < arr.size(); i++,j++ ) {
        
            int a = arr[i];
            int b = arr[j];
        
            if( b - a < min_val) {
                min_val = b - a;
                res.clear();
                res.push_back({a,b});
            } else if( b - a == min_val ) {
                res.push_back({a,b});
            } else {
                continue;
            }
        
        }
        return res;
    }
};