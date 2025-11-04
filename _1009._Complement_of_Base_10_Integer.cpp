#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        return n ^ ((1 << ((int)log2(n) + 1)) - 1);
    }
};
