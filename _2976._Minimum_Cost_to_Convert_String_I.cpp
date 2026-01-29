class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        long long ans = 0;
        const long long INF = 1e15;
        vector<vector<long long>> table(26, vector<long long>(26, INF));

        for (int i = 0; i < 26; i++) {
            table[i][i] = 0;
        }

        for( int i = 0; i < original.size(); i++ ) {
            table[original[i] - 'a'][changed[i] - 'a'] = min((long long)cost[i], table[original[i] - 'a'][changed[i] - 'a']);
        }

        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    table[i][j]=min(table[i][j],table[i][k]+table[k][j]);
                }
            }
        }

        for( int i = 0; i < source.size(); i++ ) {
            if( source[i] == target[i]) {
                continue;
            }
            if( table[source[i] - 'a'][target[i] - 'a'] >= INF) {
                return -1;
            }
            ans += table[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
    }
};