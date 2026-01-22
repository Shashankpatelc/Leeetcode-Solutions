class Solution {
public:
    bool is_sorted(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) 
            if(nums[i] > nums[i+1]) return false;
        
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while( !is_sorted(nums) ) {

            int min_sum = INT_MAX;
            int min_idx = -1;

            for( int i = 0; i < nums.size() - 1; i++ ) {
                int current = nums[i] + nums[i + 1];
                if( current < min_sum ) {
                    min_sum = current;
                    min_idx = i;
                }
            }

            nums[min_idx] = min_sum;
            nums.erase(nums.begin() + min_idx + 1);

            ops++;
        }

        return ops;
    }
};