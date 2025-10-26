class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j = -1, index = -1, temp;
        if (size(haystack) < size(needle)) {
            return index;
        }

        for (i = 0; i < size(haystack); i++) {
            if (haystack[i] == needle[j + 1]) {
                temp = i;
                while (i < size(haystack)) {
                    if (haystack[i] == needle[j + 1]) {
                        j += 1;
                        i += 1;
                        index = i - j - 1;
                    } else if (j == size(needle) - 1) {
                        return index ;
                    } else {
                        j = -1;
                        index = -1;
                        i = temp;
                        break;
                    }
                } 
                if(i >= size(haystack) && j < size(needle) - 1) {
                    index = -1;
                }
            }
        }

        return index;
    }
};
