class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result = {1};
        
        for(int k = 1; k < rowIndex + 1; k++) 
            result.push_back((long long)result[k-1] * (rowIndex-k+1) / k);
        
        return result;
    }
};