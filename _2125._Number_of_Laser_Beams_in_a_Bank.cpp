#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int a, b, j = 1, i = 0, temp = 0, totalcount = 0;
        string s1,s2;
        
        if ( bank.size() == 1 ) return 0;
        
        while ( i < bank.size() && j < bank.size() ){ 
            s1 = bank[i];
            s2 = bank[j];
            a = count(s1.begin(), s1.end(), '1');
            b = count(s2.begin(), s2.end(), '1');

            if (b == 0){
                j++;
            } else {
                temp = a * b;
                totalcount+=temp;
                i = j;
                j++;
            }
        }
        return totalcount;
    }
};