#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> answer;
        for (int i = k - 1; i < nums.size(); i++){
            priority_queue< pair<int,int>> maxheap;
            unordered_map<int,int> freq;
            int sum = 0;
            for (int j = i + 1 - k; j <= i; j++){
                freq[nums[j]]++;
            }
            for (auto &a : freq){
                maxheap.push({a.second,a.first});
            }
            for (int temp = 0; temp < x && !maxheap.empty(); temp++){
                auto ele = maxheap.top();
                sum += (ele.first * ele.second);
                maxheap.pop();
            }
            answer.push_back(sum);
        }
        return answer;
    }
};

