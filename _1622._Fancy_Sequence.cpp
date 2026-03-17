class Fancy {
public:
    
    vector<long long> list;
    long long a_total = 0;
    long long m_total = 1;
    long long mod = 1000000007;

    Fancy() {
        
    }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    
    void append(int val) {
        list.push_back((((val - a_total + mod) % mod) * power(m_total, mod - 2)) % mod);
    }
    
    void addAll(int inc) {
        a_total = (inc + a_total) % mod;
    }
    
    void multAll(int m) {
        m_total = (m_total * m) % mod;
        a_total = (a_total * m) % mod;
    }
    
    int getIndex(int idx) {
        if( idx >= size(list)) return -1;
        int ans = (( list[idx] * m_total) + a_total) % mod;
        return ans % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */