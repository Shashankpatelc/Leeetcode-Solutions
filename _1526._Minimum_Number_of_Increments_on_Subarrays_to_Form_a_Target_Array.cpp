#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int temp = target[0] ,count = target[0];
        for (int i = 1; i < target.size(); i++){
            if (temp < target[i]){
                count+=(target[i] - temp);
            }
            temp = target[i];
        }
        return count;
    }
};