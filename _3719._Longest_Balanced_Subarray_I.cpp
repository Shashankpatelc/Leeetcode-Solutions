class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int longest = 0;
        int even_c = 0, odd_c = 0, total_len = 0;
        static bool visited[1000001] = {false};

        for( int i = 0; i < nums.size(); i++) {
            vector<int> idx;
            even_c = 0;
            odd_c = 0;
            total_len = 0;

            for( int j = i; j < nums.size(); j++) {
                int num = nums[j];
                if( visited[num]) {
                    total_len++;
                    if( even_c == odd_c)    longest = max(longest, total_len);
                    continue;
                }
                
                if( num % 2 == 0) even_c++;
                else odd_c++;

                total_len++;
                visited[num] = true;
                idx.push_back(num);

                if( even_c == odd_c)    longest = max(longest, total_len);
            }

            for(auto &id : idx) visited[id] = false;
        }

        return longest;
    }
};