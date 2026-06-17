class Solution {
public:
    char processStr(string s, long long k) {
        long long length = 0;
        vector<long long> lengths(s.size());
        char ch;

        for( int i = 0; i < s.size(); i++ ) {
            if( s[i] == '*' ) {
                if (length > 0) {
                    length--;
                }
                lengths[i] = length;
            } else if( s[i] == '#' ) {
                length *= 2;
                lengths[i] = length;
            } else if( s[i] == '%' ) {
                lengths[i] = length;
            } else {
                length += 1;
                lengths[i] = length;
            }
        }

        if( k > length - 1 ) return '.';
        for( int i = s.size() - 1; i >=0 ; i-- ) {
            if( k > lengths[i] ) return '.';
            if( s[i] == '#' ) {
                if( k >= lengths[i] / 2 )
                    k = k - lengths[i] / 2;
            } else if( s[i] == '%') {
                k = lengths[i] - k - 1;
            } else if( s[i] == '*') {
                continue;
            } else {
                if( k == lengths[i] - 1) {
                    ch = s[i];
                    break;
                }
            }
        }

        return ch;
    }
};