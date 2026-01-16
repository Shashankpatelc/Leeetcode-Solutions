class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long maxGap = -1;
        unordered_set<int> hgap;

        hFences.push_back(1);
        hFences.push_back(m);
        
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        for( int i = 0; i < hFences.size() - 1; i++ ) {
            for( int j = i + 1; j < hFences.size(); j++ ) {
                hgap.insert((hFences[j] - hFences[i]));
            }
        }

        for( int i = 0; i < vFences.size() - 1; i++ ) {
            for( int j = i + 1; j < vFences.size(); j++ ) {
                int gap = (vFences[j] - vFences[i]);
                if( gap > maxGap && hgap.count(gap) ) {
                    maxGap = gap;
                }
            }
        }

        return (maxGap > -1) ? (long long)maxGap * maxGap % 1000000007 : -1;
    }
};

