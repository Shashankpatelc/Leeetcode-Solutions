class Solution {
private:
    // Union-Find class nested inside Solution
    class UnionFind {
    private:
        vector<int> parent;
        vector<int> rank;
        
    public:
        UnionFind(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            
            // Initialize: each station is its own parent
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
        }
        
        // Find with path compression
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        // Union by rank
        void unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            
            if (rootX == rootY) return;
            
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    };

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // Step 1: Build Union-Find structure
        UnionFind uf(c);
        
        // Step 2: Process all connections to form power grids
        for (auto& conn : connections) {
            uf.unite(conn[0], conn[1]);
        }
        
        // Step 3: Build map of grid -> set of online stations
        unordered_map<int, set<int>> gridOnline;
        for (int i = 1; i <= c; i++) {
            int root = uf.find(i);
            gridOnline[root].insert(i);
        }
        
        // Step 4: Process queries
        vector<int> result;
        
        for (auto& query : queries) {
            int type = query[0];
            int station = query[1];
            
            if (type == 1) {
                // Maintenance check
                int root = uf.find(station);
                
                // Check if this station is online
                if (gridOnline[root].count(station)) {
                    // Station is online, it handles itself
                    result.push_back(station);
                } else {
                    // Station is offline, find smallest online in same grid
                    if (gridOnline[root].empty()) {
                        result.push_back(-1);
                    } else {
                        result.push_back(*gridOnline[root].begin());
                    }
                }
            } else {
                // type == 2: Turn station offline
                int root = uf.find(station);
                gridOnline[root].erase(station);
            }
        }
        
        return result;
    }
};
