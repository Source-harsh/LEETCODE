class Solution {
public:
    long long power(long long a, long long b) {
        long long ans = 1;
        long long MOD = 1e9 + 7;

        while (b) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {
        long long modulo = 1e9 + 7;
        long long prod = 1, prod2 = 1;

        for (int i = 1; i <= 2*k; i++) {
            prod = prod * (n + k - i) % modulo;
            prod2 = prod2 * i % modulo;
        }

        return prod * power(prod2, modulo - 2) % modulo;
    }
};