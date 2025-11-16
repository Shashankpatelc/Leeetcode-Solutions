class Solution {
public:
    int numSub(string s) {
        long long count = 0;
        const long long MOD = 1000000007LL;
        vector<int> idx = {-1};

        for( int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                idx.push_back(i);
            }
        }

        idx.push_back(s.size());

        for(int i = 0; i+1 < idx.size(); i++){
            long long  left = idx[i];
            long long right = idx[i+1];
            long long l = right - left - 1;
            count = (count + ((l*(l+1))/2)) % MOD;
        }
        return (int)(count % MOD);
    }
};