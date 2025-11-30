class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int N = nums.size();
        long long P = (long long) p;
        int R = 0;

        for(auto &ele : nums){
            R = (R + ele) % P;
        }

        if( R == 0) return 0;

        long long prefix_sum = 0;
        int min_len = N;
        unordered_map<int,int> map;
        map[0] = 0;

        for( int i = 0; i < N; i++){

            prefix_sum = (prefix_sum + nums[i]) % P;
            int T = ( prefix_sum - R + P) % P;
            
            if( map.count(T) ){
                min_len = min(min_len, i - map[T] + 1);
            }
            map[prefix_sum] = i + 1;
        }

        if( min_len < N) return min_len;
        return -1;
    }
};