class Solution {
public:
    bool check(string s1, string s2) {
        if(s1 == s2) return true;
        char temp = s2[0];
        s2[0] = s2[2];
        s2[2] = temp;
        if(s1 == s2) return true;
        temp = s2[0];
        s2[0] = s2[2];
        s2[2] = temp;
        temp = s2[1];
        s2[1] = s2[3];
        s2[3] = temp;
        if(s1 == s2) return true;
        temp = s2[0];
        s2[0] = s2[2];
        s2[2] = temp;
        if(s1 == s2) return true;
        return false;
    }

    bool canBeEqual(string s1, string s2) {
        if(s1 == s2) return true;
        char temp = s1[0];
        s1[0] = s1[2];
        s1[2] = temp;
        if(check(s1,s2)) return true;
        temp = s1[0];
        s1[0] = s1[2];
        s1[2] = temp;
        temp = s1[1];
        s1[1] = s1[3];
        s1[3] = temp;
        if(check(s1,s2)) return true;
        temp = s1[0];
        s1[0] = s1[2];
        s1[2] = temp;
        if(check(s1,s2)) return true;
        return false;
    }
};