#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int left(vector<int> num,int i, int n){
        bool l = true;
        while( -1 < i and i < n){
            if(num[i] > 0)
            {
                num[i]--;
                if(l){
                    i++;
                    l = false;
                } 
                else{
                    i--;
                    l = true;
                }
            }
            else{
                if(l) i--; 
                else i++;
            }
        }
        for(auto a : num){
            if ( a != 0) return 0;
        }
        return 1;
    }

    int right(vector<int> num,int i,int n){
        bool r = true;
        while( -1 < i and i < n){
            if(num[i] > 0)
            {
                num[i]--;
                if(r){
                    i--;
                    r = false;
                } 
                else{
                    i++;
                    r = true;
                }
            }
            else{
                if(r) i++; 
                else i--;
            }
        }
        for(auto a : num){
            if ( a != 0) return 0;
        }
        return 1;
    }

    int countValidSelections(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] == 0){
                count += left(nums,i,n);
                count += right(nums,i,n);
            }
        }
        return count;
    }
};