class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        stack<int> st;
        vector<int> res;
        int i = n;
        if( digits[n] == 0){
            digits[n] = 1;
        } else if( digits[n] == 9){
            while( i >= 0 && digits[i] == 9){
                st.push(0);
                i--;
            }
            if( i < 0)
                st.push(1);
            else
                digits[i]++;
        } else {
            digits[n]++;
        }
        n = i;
        while( i >= 0 ){
            st.push(digits[i]);
            i--;
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};