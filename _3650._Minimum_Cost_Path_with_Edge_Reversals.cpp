class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        unordered_map<int, vector<pair<int, int>>> adj;
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>> queue;

        for( auto &temp : edges ) {
            adj[temp[0]].push_back({temp[1], temp[2]});
            adj[temp[1]].push_back({temp[0], temp[2] * 2});
        }

        dist[0] = 0;
        queue.push({0,0});

        while( !queue.empty() ) {

            int curr_cost = -queue.top().first;
            int curr_node = queue.top().second;

            queue.pop();

            if ( curr_cost > dist[curr_node] ) {
                continue;
            }

            dist[curr_node] = curr_cost;

            for( auto &nib : adj[curr_node] ) {

                int nib_cost = nib.second;
                int nib_node = nib.first;
                int new_cost = nib_cost + curr_cost;
                
                if( new_cost < dist[nib_node] ) {
                    dist[nib_node] = new_cost;
                    queue.push({-(new_cost), nib_node});
                }
            }
        }
        return (dist[n - 1] == INT_MAX) ? -1 : dist[n - 1];
    }
};