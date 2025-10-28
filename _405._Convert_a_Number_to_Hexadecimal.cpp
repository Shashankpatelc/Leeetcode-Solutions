#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        string res = "";
        if (num == 0){
            return "0";
        }
        for(int i = 0; i < 8; i++){
            int a = num & 15;
            char c = '0';
            if(a >=0 && a <= 9){
                c = '0' + a;
            } else {
                c = 'a' + a % 10;
            }
            if(num == 0 && res !=""){
                break;
            }
            res = c + res;
            num = num >> 4;
        }
        return res;
    }
};