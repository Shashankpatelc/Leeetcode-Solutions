class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        
        vector<int> r(mat.size(), 0);
        vector<int> c(mat[0].size(), 0);

        for(int i = 0; i < mat.size(); i++) 
            for(int j = 0; j < mat[i].size(); j++) 
                if(mat[i][j] == 1) {
                    r[i]++;
                    c[j]++;
                }

        for(int i = 0; i < r.size(); i++) 
            for(int j = 0; j < c.size(); j++) 
                if(c[j] == 1 && r[i] == 1 && mat[i][j] == 1) count++;
            
        return count;
    }
};