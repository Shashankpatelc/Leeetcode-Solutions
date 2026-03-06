class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zero = false;

        for( int i = 0; i < size(s); i++) {
            if( s[i] == '0' ) zero = true;
            if( s[i] == '1' && zero ) return false;
        }
        
        return true;
    }
};