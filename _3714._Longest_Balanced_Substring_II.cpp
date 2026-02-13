class Solution {
    int solve2(char c1, char c2, string& s) {
        int max_len = 0;
        int diff = 0; 
        
        unordered_map<int, int> mp;
        mp[0] = -1; 

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c1) {
                diff++;
            } 
            else if (s[i] == c2) {
                diff--;
            } 
            else { 
                mp.clear();
                mp[0] = i; 
                continue; 
            }

            if (mp.count(diff)) {
                max_len = max(max_len, i - mp[diff]);
            } else {
                mp[diff] = i; 
            }
        }
        return max_len;
    }

    int solve3(string& s) {
        int max_len = 0;
        int diff1 = 0; 
        int diff2 = 0; 

        unordered_map<string, int> mp;
        mp["0,0"] = -1; 
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (c == 'a') {
                diff1++; 
            } 
            else if (c == 'b') {
                diff1--; 
                diff2++;
            } 
            else if (c == 'c') {
                diff2--;
            }

            string key = to_string(diff1) + "," + to_string(diff2);

            if (mp.count(key)) {
                max_len = max(max_len, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }
        return max_len;
    }

public:
    int longestBalanced(string s) {
        if (s.empty()) return 0;

        int largest_sub = 0;

        int count = 1;
        for(int i = 1; i < s.size(); i++) { 
            if(s[i] == s[i - 1]) {
                count++;
            } else {
                largest_sub = max(largest_sub, count);
                count = 1; 
            }
        }
        largest_sub = max(largest_sub, count); 
        largest_sub = max(largest_sub, solve2('a', 'b', s));
        largest_sub = max(largest_sub, solve2('a', 'c', s));
        largest_sub = max(largest_sub, solve2('b', 'c', s));

        largest_sub = max(largest_sub, solve3(s));
        
        return largest_sub;
    }
};