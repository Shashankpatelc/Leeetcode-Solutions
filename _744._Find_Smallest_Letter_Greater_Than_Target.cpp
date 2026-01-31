class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if( target >= letters.back()) {
            return letters[0];
        }
        char res = 'a';
        int l = 0, h = letters.size(),mid;
        
        while( l < h) {
            mid = (l + h) / 2;
            if(letters[mid] <= target) {
                l = mid + 1;
            } else {
                res = letters[mid];
                h = mid;
            }
        }
        return res;
    }
};