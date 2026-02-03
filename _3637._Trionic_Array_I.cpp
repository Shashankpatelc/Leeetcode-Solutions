class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        bool inc = false, dec = false, inc_n = false;
        int idx = 0;

        for( ; idx < nums.size() - 1; idx++ ) {

            if( nums[idx] < nums[idx+1] ) inc = true; 
            else break;
        }

        if( !inc ) return false;

        for( ; idx < nums.size() - 1; idx++ ) {

            if( nums[idx] > nums[idx + 1] ) dec = true;
            else break;
        }

        if( !dec ) return false;
        
        for( ; idx < nums.size() - 1; idx++ ) {

            if( nums[idx] < nums[idx+1] ) inc_n= true;
            else return false;
        }

        return inc_n;
    }
};
