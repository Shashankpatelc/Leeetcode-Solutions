class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_apt = 0;
        int sum = 0; 
        for(int i = 0; i < gain.size(); i++) {
            max_apt = max(max_apt, sum);
            sum += gain[i];
        }
        max_apt = max(max_apt, sum);
        return max_apt;
    }
};