class Solution {
public:
    const int mod = 1e9 + 7;

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<long long> dp(n + 1, 0);

        dp[0] = 1;

        vector<int> last(26, 0);

        for (int i = 1; i <= n; i++) {

            int c = s[i - 1] - 'a';

            dp[i] = (2 * dp[i - 1]) % mod;

            if (last[c] != 0) {
                dp[i] = (dp[i] - dp[last[c] - 1] + mod) % mod;
            }

            last[c] = i;
        }

        return (dp[n] - 1 + mod) % mod;
    }
};