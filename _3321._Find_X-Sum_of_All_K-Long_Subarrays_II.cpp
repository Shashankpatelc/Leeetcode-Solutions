// C++17
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        if (n == 0) return {};
        vector<long long> ans;
        ans.reserve(n - k + 1);

        // count map
        unordered_map<int,int> cnt;
        cnt.reserve(k * 2);

        // Both sets store pairs (count, value) and are ordered ascending by pair.
        // Ascending order is fine: to get largest element use prev(end()).
        set<pair<int,int>> top;   // holds up to x largest (count,value)
        set<pair<int,int>> rest;  // holds the remaining elements

        auto contribution = [&](const pair<int,int>& p)-> long long {
            return 1LL * p.first * p.second;
        };

        long long topSum = 0;

        // helper to insert a pair into rest (then we'll rebalance)
        auto insertIntoRest = [&](const pair<int,int>& p) {
            if (p.first <= 0) return;
            rest.insert(p);
        };

        // helper to rebalance so that top.size() == min(x, distinct)
        auto rebalance = [&]() {
            int distinct = (int)(top.size() + rest.size());
            int want = min(x, distinct);

            // move largest from rest to top until top.size() == want
            while ((int)top.size() < want && !rest.empty()) {
                auto it = prev(rest.end()); // largest in rest
                top.insert(*it);
                topSum += contribution(*it);
                rest.erase(it);
            }

            // if top has too many, move smallest from top to rest
            while ((int)top.size() > want && !top.empty()) {
                auto it = top.begin(); // smallest in top
                topSum -= contribution(*it);
                rest.insert(*it);
                top.erase(it);
            }

            // ensure the smallest in top is >= largest in rest; if not swap
            if (!top.empty() && !rest.empty()) {
                auto itTopSmall = top.begin();           // smallest in top
                auto itRestLarge = prev(rest.end());    // largest in rest
                // while there is a rest element larger than smallest top element, swap them
                while (itTopSmall != top.end() && itRestLarge != rest.end()
                       && *itRestLarge > *itTopSmall) {
                    pair<int,int> a = *itTopSmall;
                    pair<int,int> b = *itRestLarge;
                    top.erase(itTopSmall);
                    rest.erase(itRestLarge);
                    top.insert(b);
                    rest.insert(a);
                    topSum += contribution(b) - contribution(a);

                    if (top.empty() || rest.empty()) break;
                    itTopSmall = top.begin();
                    itRestLarge = prev(rest.end());
                }
            }
        };

        // initialize first window
        for (int i = 0; i < k; ++i) ++cnt[nums[i]];
        for (auto &pr : cnt) {
            insertIntoRest({pr.second, pr.first});
        }
        rebalance();
        ans.push_back(topSum);

        // slide
        for (int i = k; i < n; ++i) {
            int addV = nums[i];
            int remV = nums[i - k];

            // ----- remove remV -----
            {
                int oldc = cnt[remV];
                // it must exist
                pair<int,int> oldp = {oldc, remV};
                // erase oldp from whichever set it is in
                auto itTop = top.find(oldp);
                if (itTop != top.end()) {
                    topSum -= contribution(*itTop);
                    top.erase(itTop);
                } else {
                    auto itRest = rest.find(oldp);
                    if (itRest != rest.end()) rest.erase(itRest);
                }
                // decrement count
                if (oldc == 1) {
                    cnt.erase(remV); // removed from window entirely
                } else {
                    cnt[remV] = oldc - 1;
                    insertIntoRest({oldc - 1, remV});
                }
            }

            // ----- add addV -----
            {
                int oldc = cnt.count(addV) ? cnt[addV] : 0;
                if (oldc > 0) {
                    // erase old pair if present
                    pair<int,int> oldp = {oldc, addV};
                    auto itTop = top.find(oldp);
                    if (itTop != top.end()) {
                        topSum -= contribution(*itTop);
                        top.erase(itTop);
                    } else {
                        auto itRest = rest.find(oldp);
                        if (itRest != rest.end()) rest.erase(itRest);
                    }
                }
                int newc = oldc + 1;
                cnt[addV] = newc;
                insertIntoRest({newc, addV});
            }

            // rebalance sets
            rebalance();
            ans.push_back(topSum);
        }

        return ans;
    }
};

