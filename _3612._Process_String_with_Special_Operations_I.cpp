class Solution {
public:
    string processStr(string s) {

        string res = "";

        for( char &a : s ) {

            if( a == '*' ) {

                if( !res.empty() )
                    res.pop_back();

                else 
                    continue;

            } else if ( a == '#' ) {

                res += res;

            } else if( a == '%' ) {

                reverse(res.begin(),res.end());

            } else {

                res += a;
            }
        }
        return res;
    }
};