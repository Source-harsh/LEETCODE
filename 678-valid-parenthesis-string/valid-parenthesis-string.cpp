class Solution {
public:

    bool dfs(string &s, int idx, int balance,
             vector<vector<int>> &dp) {
        if (balance < 0)
            return false;
        if (idx == s.size())
            return balance == 0;

        if (dp[idx][balance] != -1)
            return dp[idx][balance];

        bool ans = false;

        if (s[idx] == '(') {
            ans = dfs(s, idx + 1, balance + 1, dp);
        }
        else if (s[idx] == ')') {
            ans = dfs(s, idx + 1, balance - 1, dp);
        }
        else {
            bool open = dfs(s, idx + 1, balance + 1, dp);
            bool close = dfs(s, idx + 1, balance - 1, dp);
            bool empty = dfs(s, idx + 1, balance, dp);

            ans = open || close || empty;
        }

        return dp[idx][balance] = ans;
    }

    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return dfs(s, 0, 0, dp);
    }
};