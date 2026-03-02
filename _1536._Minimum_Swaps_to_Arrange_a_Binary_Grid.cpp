class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        vector<int> swap_pos;

        int swaps = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            int pos = -1;
            for(int j = 0; j < grid.size(); j++) if( grid[i][j] == 1) pos = j;
            swap_pos.push_back(pos);
        }

        for(int i = 0; i < swap_pos.size() - 1; i++ ) {
            int pos = swap_pos[i];
            int new_pos = -1;
            if(pos <= i) 
                continue;
            else
            {
                int j = 0;
                for(j = i + 1; j < swap_pos.size(); j++) {
                    if(swap_pos[j] <= i) {
                        new_pos = swap_pos[j];
                        break;
                    }
                }

                if(new_pos == -1) return -1;

                for(j; j > i; j--){
                    swaps++;
                    swap_pos[j] = swap_pos[j-1];
                }
                swap_pos[j] = new_pos;
            }
        }
        return swaps;
    }
};