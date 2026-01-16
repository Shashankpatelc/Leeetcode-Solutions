class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int len = s.length();
        for(int i = len - 1; i > -1; i--) {
            if(s.at(i) == ' ' && count == 0) {
                continue;
            } else if( s.at(i) != ' ') {
                count++;
            } else {
                return count;
            }
        }
        return count;
    }
};