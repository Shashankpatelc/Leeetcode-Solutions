class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int a = -1, b = -1, res = 0;
        unordered_set<int> s;

        if( intervals.size() == 1){
            return 2;
        }
        
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b){
            if( a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });

        for(auto &ele : intervals){
            int e1 = ele[0], e2 = ele[1];
            if( e1 > b ){
                a = e2 - 1;
                b = e2;
                res += 2;
            } else if( e1 > a ){
                a = b;
                b = e2;
                res +=1;
            } else{
                continue;
            }
        }
        return res;
    }
};