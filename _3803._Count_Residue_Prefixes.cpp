class Solution {
public:
    int residuePrefixes(string s) {
        int count = 0;
        unordered_set<char> set;
        for( int i = 0; i < s.length(); i++) {
            set.insert(s[i]);
            
            int setlen = set.size();
            int clen = i + 1;

            if (setlen > 2)
                return count;
            
            if(setlen == clen % 3) {
                count += 1;
            }
        }
        return count;
    }
};