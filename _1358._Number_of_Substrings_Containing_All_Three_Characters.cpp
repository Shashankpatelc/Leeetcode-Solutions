class Solution {
public:
    int numberOfSubstrings(string s) {
        int length_str = s.size(), left = 0, right = -1, total_count = 0, a_count = 0, b_count = 0, c_count = 0;

        while(right < length_str) {

            if(a_count && b_count && c_count) {

                total_count += length_str - right;
                if(s[left] == 'a') a_count--;
                else if(s[left] == 'b')    b_count--;
                else if(s[left] == 'c')    c_count--;
                left++;
            } else {
                right++;
                if(right == length_str) break;
                if(s[right] == 'a') a_count++;
                else if(s[right] == 'b')    b_count++;
                else if(s[right] == 'c')    c_count++;
            }
        }

        return total_count;
    }
};