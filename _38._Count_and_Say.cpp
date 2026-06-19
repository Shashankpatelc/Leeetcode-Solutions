class Solution {
public:
    string count(string s) {
        string res = "";
        char prev_ch = s[0];
        int count = 0;

        for( int i = 0; i < s.length(); i++ ) {
        
            char ch = s[i];
        
            if( ch == prev_ch ) {
                count++;
            } else {
                res += count + '0';
                res += prev_ch;
                prev_ch = ch;
                count = 1;
            }
        }
        
        res += count + '0';
        res += prev_ch;
        
        return res;
    }

    string countAndSay(int n) {
        string res = "1";
        
        for( int i = 1; i < n; i++) 
            res = count(res);
        
        return res;
    }
};