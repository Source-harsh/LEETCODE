class Solution {
public:
    const int MOD = 1e9 + 7;

    int dfs(vector<vector<int>>& grid,
            vector<vector<vector<int>>>& dp,
            int i, int j, int dir) {

        int m = grid.size();
        int n = grid[0].size();

        if(i >= m || j >= n)
            return 0;

        if(i == m-1 && j == n-1)
            return 1;

        if(dp[i][j][dir] != -1)
            return dp[i][j][dir];

        long long ans = 0;

        // Mirror encountered
        if(grid[i][j] == 1) {

            if(dir == 0) {
                // Moving right -> redirected down
                ans = dfs(grid, dp, i+1, j, 1);
            }
            else if(dir == 1) {
                // Moving down -> redirected right
                ans = dfs(grid, dp, i, j+1, 0);
            }
        }

        // Empty cell
        else {

            // Move right
            ans += dfs(grid, dp, i, j+1, 0);

            // Move down
            ans += dfs(grid, dp, i+1, j, 1);
        }

        return dp[i][j][dir] = ans % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, -1))
        );

        return dfs(grid, dp, 0, 0, 2);
    }
};