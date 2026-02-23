class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < (pow(2,k) + k - 1) ) return false;
        int finalcount = 0, count = (1 << k) - 1;
        vector<bool> seen((1<<k), false);
        int current_value = 0;
        for(int i = 0; i < s.size(); i++) {
            current_value = ((current_value << 1) & count) | s[i] - '0';
            if( i < k -1 ) continue;
            if( seen[current_value] == false ) {
                seen[current_value] = true;
                finalcount++;
            }
            if(finalcount == pow(2, k)) return true;
        }
        return false;
    }
};