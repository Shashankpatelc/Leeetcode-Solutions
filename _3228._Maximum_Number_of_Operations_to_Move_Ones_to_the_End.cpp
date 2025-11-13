class Solution {
public:
    int maxOperations(string s) {
        int c_1 = 0,count = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                c_1++;
            } else if(s[i] == '0' && ( i + 1 == s.size() || s[i + 1] == '1' )) {
                count += c_1;
            }
        }
        return count;
    }
};
