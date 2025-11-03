#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &a : image){
            for(int i = 0; i < (a.size()+1) / 2; i++){
                int j = a.size() - 1 - i;
                if(i == j){
                    a[i] ^= 1;
                } else {
                    int left = a[i];
                    a[i] = a[j] ^ 1;
                    a[j] = left ^ 1;
                }
            }
        }
        return image;
    }
};
