#include <bits/stdc++.h>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int i;
        stack<char> st;

        for (i = 0; i < s.size(); i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
            {
                st.push(s[i]);
            } 
            else if (!st.empty()) 
            {
                if (s[i] == ')' && st.top() == '(') 
                {
                    st.pop();
                } 
                else if (s[i] == ']' && st.top() == '[') 
                {
                    st.pop();
                } 
                else if (s[i] == '}' && st.top() == '{') 
                {
                    st.pop();
                } 
                else 
                {
                    return false;
                }
            } 
            else 
            {
                return false;
            }
        }

        if (st.empty()) 
        {
            return true;
        }
        return false;
    }
};