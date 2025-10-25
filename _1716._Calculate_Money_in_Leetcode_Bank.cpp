using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int monday = 1,i = 0;
        int money = 0,temp = monday;
        while(i < n){
            if(i % 7 == 0 && i != 0){
                monday++;
                temp = monday;
            }
            money+=temp;
            temp++;
            i++;
        }
        return money;
    }
};