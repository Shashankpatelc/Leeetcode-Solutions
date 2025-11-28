class Solution {
public:

    int max_components = 0;

    long long dfs(int u, int p, vector<int>& values, long long k, const vector<vector<int>>& adj){
        long long sum = values[u];
        for( auto &v : adj[u]){
            if( v == p){
                continue;
            }
            sum += dfs(v,u,values,k,adj);
        }
        if(sum % k == 0){
            max_components++;
            return 0;
        } else {
            return sum;
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> adj(n);
        long long ll_k = k;
        
        for( auto ele : edges){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }

        dfs(0, -1, values, ll_k, adj);

        return max_components;
    }
};

