class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> idx = {-1};
        int n = s.size();

        for( int i = 0; i < n ; i++)
            if( s[i] == '0')
                idx.push_back(i);
        
        idx.push_back(n);

        long long ans = 0;
        int m = idx.size();
        for( int i = 0; i + 1 < m; i++){
            long long l = idx[i+1] - idx[i] - 1;
            if( l > 0) ans += l * (l + 1) / 2;
        }
        for (int k = 1; k >= 1 ; ++k) {
        long long need = 1LL * k + 1LL * k * k;
        if (need > n) break;

        for (int j = 1; j + k < m; ++j) {
            long long left_min  = idx[j-1] + 1;
            long long left_max  = idx[j];
            long long right_min = idx[j+k-1];
            long long right_max = idx[j+k] - 1;

            if (left_min > left_max || right_min > right_max) continue;

            for (long long start = left_min; start <= left_max; ++start) {
                long long end_req = start + need - 1;
                long long real_min_end = max(end_req, right_min);
                if (real_min_end > right_max) continue;
                ans += (right_max - real_min_end + 1);
            }
        }
    }
    return (int)ans;
    }
};