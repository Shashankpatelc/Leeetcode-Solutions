class Solution {
public:
    int minimumDeletions(string s) {
        int left_b = 0;
        int right_a = 0;

        for( int i = 0; i < s.size(); i++) {
            if( s[i] == 'a') right_a += 1;
        }

        int min_opp = right_a;

        for( int i = 0; i < s.size(); i++) {
            if( s[i] == 'a') {
                right_a -= 1;
            } else {
                left_b += 1;
            }
            min_opp = min(min_opp, (left_b + right_a));
        }

        return min_opp;
    }
};