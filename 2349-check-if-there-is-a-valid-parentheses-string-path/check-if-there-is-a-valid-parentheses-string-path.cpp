class Solution {
public:
    int dp[100][100][201];

    bool dfs(vector<vector<char>>& grid, int row, int col, int open) {
        int m = grid.size();
        int n = grid[0].size();

        if (row >= m || col >= n)
            return false;

        if (grid[row][col] == '(')
            open++;
        else
            open--;

        // Invalid prefix
        if (open < 0)
            return false;

        // Not enough cells remaining to close all '('
        int remaining = (m - row - 1) + (n - col - 1);

        if (open > remaining)
            return false;

        // Destination
        if (row == m - 1 && col == n - 1)
            return open == 0;

        if (dp[row][col][open] != -1)
            return dp[row][col][open];

        bool down = dfs(grid, row + 1, col, open);
        bool right = dfs(grid, row, col + 1, open);

        return dp[row][col][open] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // Must start with '('
        if (grid[0][0] == ')')
            return false;

        // Must end with ')'
        if (grid[m - 1][n - 1] == '(')
            return false;

        memset(dp, -1, sizeof(dp));

        return dfs(grid, 0, 0, 0);
    }
};