#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0,prev = 0, curr = 1;
        while(curr < neededTime.size()){
            if(colors[prev] == colors[curr]){
                if(neededTime[prev] <= neededTime[curr]){
                    time += neededTime[prev];
                    prev = curr;
                } else {
                    time += neededTime[curr];
                }
                curr++;
            }
            else {
                prev = curr;
                curr++;
            }
        }
        return time;
    }
};
