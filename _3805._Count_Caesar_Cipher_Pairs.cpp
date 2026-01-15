class Solution {
public:
    long long countPairs(vector<string>& words) {
        
        long long pairCount = 0;
        unordered_map<string, int> freqMap;
        
        for ( string& word : words) {
            if (word.empty()) continue;

            string key = word;
            int shift = word[0] - 'a';
            
            for (int i = 0; i < key.length(); ++i) {
                int originalVal = key[i] - 'a';
                int newVal = (originalVal - shift + 26) % 26;
                key[i] = 'a' + newVal;
            }
            
            pairCount += freqMap[key];
            
            freqMap[key]++;
        }
        
        return pairCount;
    }
};