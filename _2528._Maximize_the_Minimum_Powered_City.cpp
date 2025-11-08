#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, long long k) {
        int n = stations.size();
        vector<ll> pref(n+1, 0);
        for (int i = 0; i < n; ++i) pref[i+1] = pref[i] + stations[i];

        // base[i] = sum of stations in [max(0,i-r) .. min(n-1,i+r)]
        vector<ll> base(n);
        ll base_max = 0;
        for (int i = 0; i < n; ++i) {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            base[i] = pref[R+1] - pref[L];
            base_max = max(base_max, base[i]);
        }

        ll lo = 0, hi = base_max + k, ans = 0;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (feasible(base, r, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    // Check if we can make every city's power >= target using <= k added stations
    bool feasible(const vector<long long>& base, int r, long long k, long long target) {
        int n = base.size();
        vector<long long> diff(n + 1, 0); // diff array, diff[n] is sentinel
        long long add_effect = 0; // running added stations affecting current city
        long long used = 0;

        for (int i = 0; i < n; ++i) {
            add_effect += diff[i];
            long long current = base[i] + add_effect;
            if (current < target) {
                long long need = target - current;
                used = used +  need;
                if (used > k) return false;
                add_effect = add_effect + need; // effect starts now (left <= i guaranteed)
                int right = min(n - 1, i + 2 * r); // placement at pos = min(n-1, i+r) gives right = min(n-1, i+2r)
                if (right + 1 <= n) diff[right + 1] = diff[right + 1] - need;
            }
        }
        return true;
    }
};

