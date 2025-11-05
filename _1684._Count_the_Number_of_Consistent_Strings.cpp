class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0, bitmask = 0;
        
        for (auto &e : allowed){
            bitmask |= (1 << (e - 'a'));
        }

        for( auto &e : words){
            int bitword = 0;
            for( auto &ele : e){
                bitword |= (1 << (ele - 'a'));
            }
            if ((bitmask & bitword) == bitword)
                count++;
        }
        return count;
    }
};
