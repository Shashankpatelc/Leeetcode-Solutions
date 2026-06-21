class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_val = std::ranges::max(costs);
        vector<int> selected_ice(max_val + 1,0);
        
        if( coins < ranges::min(costs))
            return 0;

        for( int i = 0; i < costs.size(); i++ ) {
            if( costs[i] <= max_val ) {
                selected_ice[costs[i]]++;
            }
        }
        
        int max_ice = 0;
        for( int i = 0; i < selected_ice.size(); i++ ) {
            long long ices = selected_ice[i];
            ices *= i;
            if( ices <= coins && ices > 0 ) {
                coins -= ices;
                max_ice += selected_ice[i];
            } else if( i > coins || coins == 0) {
                break;
            } else if(i != 0 && ices > 0) {
                int n = coins / i;
                max_ice += n;
                coins -= n * i;
            }
        }

        return max_ice;
    }
};