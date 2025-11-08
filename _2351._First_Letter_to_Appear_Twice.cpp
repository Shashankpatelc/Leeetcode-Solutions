class Solution {
public:
    char repeatedCharacter(string s) {
        int mask = 0;
        for(auto &a : s){
            if((mask & (1 << (a - 'a'))) > 0){
                return a;
            }
            mask |= (1 << (a - 'a'));
        }
        return '\0';
    }
};
