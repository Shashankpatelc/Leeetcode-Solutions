class Solution {
public:
    int minOperations(string s, int k) {
        int z = 0, n = size(s);
        
        for(int i = 0; i < n; i++ ) if(s[i] == '0') z++; 

        if( z % 2 == 1 && k % 2 == 0) return -1;

        vector<int> dist(n + 1, -1);
        queue<int> q;
        set<int> unvisited_odd;
        set<int> unvisited_even;

        for (int i = 0; i <= n; i++) {
            if (i == z) continue; 
            if (i % 2 == 0) unvisited_even.insert(i);
            else unvisited_odd.insert(i);
        }

        dist[z] = 0;
        q.push(z);

        while(!q.empty()) {
            int c = q.front();
            q.pop();

            if (c == 0) return dist[c];

            int min_x = max(0, k - (n - c));
            int max_x = min(k, c);

            int low_bound = c + k - 2 * max_x;
            int high_bound = c + k - 2 * min_x;

            auto& target_set = ((c + k) % 2 == 0) ? unvisited_even : unvisited_odd;
            auto it = target_set.lower_bound(low_bound);

            while (it != target_set.end() && *it <= high_bound) {
                int next_c = *it;
    
                dist[next_c] = dist[c] + 1;
                q.push(next_c);
    
                it = target_set.erase(it); 
            }        
        }
        return -1;
    }
};