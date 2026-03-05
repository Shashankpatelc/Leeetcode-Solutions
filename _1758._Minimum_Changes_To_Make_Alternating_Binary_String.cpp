class Solution {
public:
    int minOperations(string s) {
        int a = 0, n = size(s);
        
        for(int i = 0; i < size(s); i++) 
            if(s[i] != (i % 2 + '0')) a++;
        
        return min(a, n - a);
    }
};