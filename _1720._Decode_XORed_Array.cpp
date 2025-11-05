#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        int n = encoded.size();
        res.push_back(first);
        for (int i = 0; i < n; i++){
            res.push_back((encoded[i] xor res[i]));
        }
        return res;
    }
};
