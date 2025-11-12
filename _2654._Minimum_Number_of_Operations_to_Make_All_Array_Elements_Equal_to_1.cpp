class Solution {
public:
    int minOperations(vector<int>& nums) {

        int res = count( nums.begin(), nums.end(), 1 );
        if( res > 0 ) return nums.size() - res;
        

        int g = nums[0];
        for ( auto &x : nums ) g = gcd(g,x);
        
        if( g > 1 ) return -1;

        int len = INT_MAX;
        for( int i = 0; i < nums.size(); i++) {

            g = nums[i];
            for( int j = i+1; j < nums.size(); j++ ){

                g = gcd( nums[j], g );
                if( g == 1 ){

                    len = min(len, j - i + 1);
                    break;
                }
            }
        }

        return (nums.size() - 1) + ( len - 1);
    }
};
