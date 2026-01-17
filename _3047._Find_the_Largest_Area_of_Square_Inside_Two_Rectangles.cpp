class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long max_area = 0;
        long long n = topRight.size();

        vector<vector<int>> rect;
        
        for( int i = 0; i < n; i++) {
            rect.push_back({bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1]});
        }

        sort(rect.begin(), rect.end());

        for( int i = 0; i < n; i++ ) {
            for( int j = i + 1; j < n; j++) {

                if( rect[i][2] <= rect[j][0] ) break;

                long long x2 = max(rect[i][0], rect[j][0]);
                long long y2 = max(rect[i][1], rect[j][1]);

                long long x1 = min(rect[i][2], rect[j][2]);
                long long y1 = min(rect[i][3], rect[j][3]);

                if( x2 <= x1 && y2 <= y1) {
                    long long side = min((x1 - x2), (y1 - y2));
                    max_area = max(max_area, side * side);
                }
            }
        }
        return max_area;
    }
};