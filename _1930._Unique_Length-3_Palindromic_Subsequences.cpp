class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26,INT_MAX);
        vector<int> last(26,INT_MIN);
        int res = 0;

        for(int i = 0; i < s.size(); i++){
            if(first[s[i] - 97] == INT_MAX){
                first[s[i] - 97] = i;
                last[s[i] - 97] = i;
            } else {
                last[s[i] - 97] = i;
            }
        }

        for(int i = 0; i < 26; i++){
            if( first[i] == INT_MAX || first[i] == last[i]){
                continue;
            }
            unordered_set<char> seen;
            for(int j = first[i]+1; j < last[i]; j++){
                seen.insert(s[j]);
            }
            res += seen.size();
        }
        return res;
    }
};