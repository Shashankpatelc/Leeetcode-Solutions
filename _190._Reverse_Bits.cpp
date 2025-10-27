#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        string b = bitset<32>(n).to_string();
        reverse(b.begin(),b.end());
        return stoi(b,nullptr,2);
    }
};