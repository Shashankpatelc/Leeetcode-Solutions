#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < size(nums) - 2; i++) {

            for (int j = i + 1; j < size(nums) - 1; j++) {

                for (int k = j + 1; k < size(nums); k++) {
                    if((nums[i] + nums[j] + nums[k]) == target){
                        return (nums[i] + nums[j] + nums[k]);
                    }

                    else if ((target <= (nums[i] + nums[j] + nums[k]) && (nums[i] + nums[j] + nums[k]) <= sum)) {
                        sum = (nums[i] + nums[j] + nums[k]);
                        cout<<sum<<endl;
                    }
                    else if(sum <= (nums[i] + nums[j] + nums[k]) && (nums[i] + nums[j] + nums[k]) <= target){
                        sum = (nums[i] + nums[j] + nums[k]);
                    }

                    else if ((nums[i] + nums[j] + nums[k]) <= target && target <= sum){
                        if(((target - (nums[i] + nums[j] + nums[k]))) < (sum - target)){
                            sum = nums[i] + nums[j] + nums[k];
                        }
                    } 
                    else if (sum <= target && target <= (nums[i] + nums[j] + nums[k])) {
                        if(((target - sum)) > ((nums[i] + nums[j] + nums[k]) - target)){
                            sum =nums[i] + nums[j] + nums[k];
                        }
                    }
                }
            }
        }
        return sum;
    }
};