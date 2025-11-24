class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> map;
        vector<bool> check(26,false);
        stack<char> st;
        string res = "";
        
        for(auto &ele : s)
            map[ele]++;
        
        for(auto &ele : s){
            
            map[ele]--;
            
            if(check[ele - 'a']) continue;
            
            while(!st.empty() && st.top() > ele && map[st.top()] > 0){
                check[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ele);
            check[ele - 'a'] = true;
            
        }
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
