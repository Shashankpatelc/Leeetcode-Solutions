class Solution {
public:
    int minPartitions(string n) {
        char max_num = '0';

        for(auto &i : n) if( i > max_num ) max_num = i;

        return ((int)max_num - 48);
    }
};