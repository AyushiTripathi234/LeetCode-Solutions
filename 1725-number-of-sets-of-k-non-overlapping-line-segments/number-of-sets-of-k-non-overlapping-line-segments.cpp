class Solution {
public:
    
        
    static const long long MOD = 1000000007LL;

    long long modPow(long long a, long long e) {
        long long res = 1;

        while (e > 0) {
            if (e & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            e >>= 1;
        }

        return res;
    }

    long long C(int n, int r,
                const vector<long long>& fact,
                const vector<long long>& invFact) {
        if (r < 0 || r > n)
            return 0;

        return fact[n] * invFact[r] % MOD
                     * invFact[n - r] % MOD;
    }

    int numberOfSets(int n, int k) {
        // Answer = C(n + k - 1, 2k)

        int N = n + k - 1;

        vector<long long> fact(N + 1);
        vector<long long> invFact(N + 1);

        fact[0] = 1;

        for (int i = 1; i <= N; ++i)
            fact[i] = fact[i - 1] * i % MOD;

        invFact[N] = modPow(fact[N], MOD - 2);

        for (int i = N; i >= 1; --i)
            invFact[i - 1] = invFact[i] * i % MOD;

        return C(N, 2 * k, fact, invFact);
    }
};

   